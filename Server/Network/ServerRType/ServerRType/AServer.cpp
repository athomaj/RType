//
//  AServer.cpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "AServer.hpp"

AServer::AServer(int const sockType, int const protoType, ISocket *fd, servType serverType) :
    _sockType(sockType), _protoType(protoType), _fd(fd), _serverType(serverType), _mutex(NULL), _gameEngine(NULL)
{
#ifdef _WIN32
	_cond = new ThreadCondWin();
#else
	_cond = new ThreadCond();
#endif
}

#ifdef _WIN32
void AServer::close(socketType const fd)
{
    closesocket(fd);
}
#else
void AServer::close(socketType const fd)
{
    ::close(fd);
}
#endif

IMutex* AServer::getMutex()
{
    return _mutex;
}

void AServer::run(int const port)
{
#ifdef _WIN32
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		wprintf(L"WSAStartup failed with error: %ld\n", iResult);
		return ;
	}
#endif
    _sIn.sin_family = AF_INET;
    _sIn.sin_port = htons(port);
    _sIn.sin_addr.s_addr = INADDR_ANY;

    socket();
    bind();
    std::cout <<_serverType << std::endl;
    if (_serverType == 0)
        this->listen();
    while (42)
    {
        resetFds();
        setFds();
        try {
            select();
        } catch (std::exception const& e) {
            if (_serverType == UDP)
                return ;
        }
        try {
            if (_mutex)
                _mutex->lock();
            checkFds();
            if (_mutex)
                _mutex->unlock();
        } catch (std::exception const& e) {
            e.what();
            if (_mutex)
                _mutex->unlock();
        }
    }
}

void AServer::socket()
{
    if ((_fd->getFd() = ::socket(AF_INET, _sockType, _protoType)) == -1)
    {
        perror("socket()");
        throw ("server socket init failed\n");
    }
    int enable = 1;
    if (setsockopt(_fd->getFd(), SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char *>(&enable), sizeof(int)) < 0)
        perror("setsockopt()");
/*    enable = 1;
    if (setsockopt(_fd->getFd(), SOL_SOCKET, SO_REUSEPORT, reinterpret_cast<char *>(&enable), sizeof(int)) < 0)
        perror("setsockopt()");*/
    maxFd = _fd->getFd();
}

void AServer::bind()
{
    if (::bind(_fd->getFd(), (const struct sockaddr *)(&_sIn), sizeof(_sIn)) == -1)
    {
        close(_fd->getFd());
        throw ("bind failed\n");
    }
}

void AServer::closeOwnFd()
{
    close(_fd->getFd());
}

void AServer::select()
{
    struct timeval timeout;
    
    timeout.tv_sec = 0;
    timeout.tv_usec = 100;
    if (::select(maxFd + 1, &fdRead, &fdWrite, NULL, &timeout) == -1)
    {
        perror("select()");
        throw (std::runtime_error("select failed\n"));
    }
}

void AServer::resetFds()
{
    FD_ZERO(&fdRead);
    FD_ZERO(&fdWrite);
}

void AServer::listen(int const nbClient)
{
    if (::listen(_fd->getFd(), nbClient) == -1)
    {
        close(_fd->getFd());
        throw ("listen failed\n");
    }
}

int AServer::accept()
{
    struct sockaddr_in    sInC;
    int             sSize;
    int                   fdC;
    
	std::cout << "before accept" << std::endl;
	if ((fdC = ::accept(_fd->getFd(), NULL,
                        NULL)) == -1)
    {
        close(_fd->getFd());
		std::cout << "accept failed" << std::endl;
        throw ("Accept failed");
    }
    return (fdC);
}

void AServer::addClient()
{
    int newFd;
    
	std::cout << "in add client" << std::endl;
//    if (_mutex)
//        _mutex->lock();
    if ((newFd = accept()) != -1)
    {
        maxFd = newFd > maxFd ? newFd : maxFd;
        std::cout << "New Client" << newFd << std::endl;
        clients.push_back(new TCPSocket(newFd));
    }
//    if (_mutex)
//        _mutex->unlock();
}

std::vector<ISocket *>& AServer::getClients()
{
    return (clients);
}

Packet* AServer::getUdpAction()
{
    auto it = _udpActions.begin();
    if (it == _udpActions.end())
        return NULL;
    Packet* action = *it;
    
    _udpActions.erase(it);
    return (action);
}

void AServer::initMutex()
{
#ifdef _WIN32
	_mutex = new MutexWin();
	#else
	_mutex = new Mutex();
#endif
    
    _mutex->init();
    _cond->init();
//    pthread_cond_init(&_cond, NULL);
}

std::pair<ISocket*, Packet*>* AServer::getActions()
{
    std::pair<ISocket*, Packet *>* action = NULL;

    if (_mutex)
        _mutex->lock();
    if (actions.size())
    {
        action = &actions.front();
        actions.erase(actions.begin());
    }
    if (_mutex)
        _mutex->unlock();
    return (action);
}

IThreadCond* AServer::getCond()
{
    return (_cond);
}

void AServer::setGameManager(IGameManager* gameManager)
{
    _gameManager = gameManager;
}


void AServer::broadcast(Packet& packet)
{
    for (unsigned int i=0; i<clients.size(); ++i)
    {
        reinterpret_cast<ASocket*>(clients[i])->addData<Packet>(packet, &serPacket);
    }
}

void AServer::setGameEngine(GameEngine *game)
{
    _gameEngine = game;
}

