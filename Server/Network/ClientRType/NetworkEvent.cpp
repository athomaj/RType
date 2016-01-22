//
// NetworkEvent.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Sun Dec 13 20:34:30 2015 Timothy Burdairon
// Last update Sun Dec 13 20:34:31 2015 Timothy Burdairon
//


#include "NetworkEvent.hh"

class ClientTCP;

void* launchTcpServer(void* param)
{
    IClient *clientTCP = new ClientTCP();
    MenuWindow *win = reinterpret_cast<MenuWindow*>(param);
    clientTCP->setMenuWindow(win);
    
    win->setTcpClient(clientTCP);
    try
    {
        clientTCP->run(win->getNetEvent()->getIp(), 4242);
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
    win->getMutex()->lock();
    win->setConnected(false);
    win->getMutex()->unlock();
    return (NULL);
}

NetworkEvent::NetworkEvent(MenuWindow *_menuWindow) :
    _networkThread(NULL), _ip(""), _name("")
{
	menuWin = _menuWindow;
	hostName = "";
}

NetworkEvent::~NetworkEvent()
{

}

void NetworkEvent::connection(const std::string& IP, const std::string& username)
{
    if (_ip == IP && menuWin->getConnected())
    {
        if (username != _name)
        {
//            _name = username;
            Packet packet = Packet::build(CONNECT, username);
            (reinterpret_cast<ASocket*>(menuWin->_tcpClient->getSocket()))->addData<Packet>(packet, &serPacket);
        }
        else
            menuWin->getNetEvent()->menuRoom();
    }
    else
    {
        _ip = IP;
//        _name = username;
        if (_networkThread)
        {
            if (menuWin->getConnected())
            {
                _networkThread->exit();
                menuWin->setConnected(false);
            }
            delete _networkThread;
            menuWin->_tcpClient = NULL;
        }
        _networkThread = new Thread();
        _networkThread->create(reinterpret_cast<void*>(&launchTcpServer), menuWin);
        usleep(1000);
        Packet packet = Packet::build(CONNECT, username);
        (reinterpret_cast<ASocket*>(menuWin->_tcpClient->getSocket()))->addData<Packet>(packet, &serPacket);
    }
//        menuWin->getNetEvent()->menuRoom();
//    }
//    else
//    {
//        menuWin->getNetEvent()->menuConnection();
//        _networkThread = NULL;
//        menuWin->_tcpClient = NULL;
//    }

//    }
//    catch (std::exception const& e)
//    {
//        std::cerr << e.what() << std::endl;
//        _networkThread = NULL;
//        _ip.clear();
//        _name.clear();
//        menuConnection();
//    }
}

void NetworkEvent::newRoom(const std::string& roomName, int const nbPlayer, const std::string& host)
{
    Packet packet = Packet::build(CREATE, std::to_string(nbPlayer) + roomName);
    (reinterpret_cast<ASocket*>(menuWin->_tcpClient->getSocket()))->addData<Packet>(packet, &serPacket);
}

void NetworkEvent::joinRoom(const std::string& roomName, const std::string& host)
{
    Packet packet = Packet::build(JOIN, roomName);
    (reinterpret_cast<ASocket*>(menuWin->_tcpClient->getSocket()))->addData<Packet>(packet, &serPacket);
}

void NetworkEvent::leaveRoom(const std::string& roomName, const std::string& host)
{
    Packet packet = Packet::build(LEAVE, roomName);
    (reinterpret_cast<ASocket*>(menuWin->_tcpClient->getSocket()))->addData<Packet>(packet, &serPacket);
}

void NetworkEvent::roomList()
{
    Packet packet = Packet::build(ROOM, "");
    (reinterpret_cast<ASocket*>(menuWin->_tcpClient->getSocket()))->addData<Packet>(packet, &serPacket);
}

void NetworkEvent::play(std::string map)
{
    Packet packet = Packet::build(READY, map);
    (reinterpret_cast<ASocket*>(menuWin->_tcpClient->getSocket()))->addData<Packet>(packet, &serPacket);
//	menuWin->play = true;
}

void NetworkEvent::waitingPage()
{
    menuWin->restartMenuPages();
    menuWin->currentPage = MenuWindow::WAIT;
}

void NetworkEvent::deadPage()
{
    menuWin->restartMenuPages();
    menuWin->currentPage = MenuWindow::DEAD;
}

void NetworkEvent::endPage()
{
    menuWin->restartMenuPages();
    menuWin->currentPage = MenuWindow::END;
}

void NetworkEvent::mainMenu()
{
	menuWin->restartMenuPages();
	menuWin->currentPage = MenuWindow::NONE;
}

void NetworkEvent::menuConnection()
{
	menuWin->restartMenuPages();
	menuWin->currentPage = MenuWindow::CONNECTION;
}

void NetworkEvent::menuRoom()
{
	menuWin->restartMenuPages();
	menuWin->currentPage = MenuWindow::ROOM;
}

void NetworkEvent::menuLevel()
{
	menuWin->restartMenuPages();
	menuWin->currentPage = MenuWindow::LEVEL;
}

void NetworkEvent::endGame()
{
    Packet packet = Packet::build(ENDGAME, "");
    (reinterpret_cast<ASocket*>(menuWin->_tcpClient->getSocket()))->addData<Packet>(packet, &serPacket);
}

void NetworkEvent::setHostName(const std::string &_hostName)
{
	hostName = _hostName;
}

std::string 	&NetworkEvent::getHostName()
{
	return (hostName);
}

std::string &NetworkEvent::getIp()
{
    return (_ip);
}

void NetworkEvent::setName(std::string const& name)
{
    _name = name;
}

