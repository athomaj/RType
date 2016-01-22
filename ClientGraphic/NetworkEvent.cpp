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

void* launchTcpServer(void* param)
{
    IClient *clientTCP = new ClientTCP();
    MenuWindow *win = reinterpret_cast<MenuWindow*>(param);
    
    clientTCP->run(win->netEvent->getIp(), 4242);
    win->setTcpClient(clientTCP);
    return (NULL);
}

void NetworkEvent::endGame()
{
    Packet packet = Packet::build(ENDGAME, "");
    (reinterpret_cast<ASocket*>(menuWin->_tcpClient->getSocket()))->addData<Packet>(packet, &serPacket);
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
    try {
        if (_ip.lenght() || _ip != IP)
        {
            _ip = IP;
            _name = username;
            if (_networkThread)
            {
                _networkThread->exit();
            }
            _networkThread = new Thread();
            thread->create(reinterpret_cast<void*>(&launchTcpServer), _menuWindow);
        }
        sleep(1);
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
        _networkThread = NULL;
        _ip.clear();
        _name.clear();
    }
}

void NetworkEvent::newRoom(const std::string& roomName, int const n, const std::string& host)
{

}

void NetworkEvent::joinRoom(const std::string& roomName, const std::string& host)
{
    dsadas
}

void NetworkEvent::leaveRoom(const std::string& roomName, const std::string& host)
{

}

void NetworkEvent::roomList()
{

}

void NetworkEvent::play(std::string map)
{
	menuWin->play = true;
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
