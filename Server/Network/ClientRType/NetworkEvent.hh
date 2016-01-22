//
// NetworkEvent.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Sun Dec 13 20:34:34 2015 Timothy Burdairon
// Last update Sun Dec 13 20:34:35 2015 Timothy Burdairon
//

#ifndef NETWORKEVENT_HH_
#define  NETWORKEVENT_HH_

#include <string>
#include "Thread.hpp"
#include "Packet.hpp"

class MenuWindow;

class NetworkEvent
{
public:
	NetworkEvent(MenuWindow *t);
	~NetworkEvent();

	void 			connection(const std::string &IP, const std::string &Username);
	void 			newRoom(const std::string &roomName, int const nbPlayer, const std::string &host);
	void 			joinRoom(const std::string &roomName, const std::string &host);
	void 			leaveRoom(const std::string &roomName, const std::string &host);
	void 			roomList();
	void 			play(std::string map);

	void 			mainMenu();
	void 			menuConnection();
	void 			menuRoom();
	void 			menuLevel();
    void            waitingPage();
    void            endPage();
    void            deadPage();

    void            endGame();
    
	void 			setHostName(const std::string &HostName);
	std::string 	&getHostName();
    void setName(std::string const&);
    std::string&    getIp();

private:
    IThread* _networkThread;
    std::string _ip;
    std::string _name;
	MenuWindow *menuWin;
	std::string hostName;
};

#include "menuWindow.hh"
#include "ClientTCP.hpp"

#endif /*  NETWORKEVENT_HH_ */
