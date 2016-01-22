//
// GameEngine.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Mon Nov 30 12:31:04 2015 Timothy Burdairon
// Last update Sun Jan  3 23:19:31 2016 Timothy Burdairon
//

#ifndef GameEngine_HH_
#define GameEngine_HH_



#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "Loader.hh"
#include "GameTime.hh"
#include "Audio.hh"
#include "Thread.hpp"
#include "IClient.h"
//#include "ClientUDP.hpp"
#include "Packet.hpp"
#include "IWindow.hh"
#include "Timer.hh"

class GameEngine
{
public:
//    GameEngine(LinuxWindow *, std::string const&, int const, int const);
	GameEngine(IWindow *, std::string const&, int const, int const);
	~GameEngine();
	void	setDefaultSettings();
	void	playGame();
	bool	checkEvent();
	void 	playerMove();
    std::string& getIp();
    int getPort() const;
    IClient* getUdpClient();
    bool networkAction();
private:
	IWindow *window;
	Animation 		*player;
	Audio			*sound;
    std::string     _ip;
    int             _port;
    IThread*        _networkThread;
    IClient*        _udpClient;
	bool			left;
	bool			up;
	bool			right;
	bool			down;
	float 			x;
	float			y;
    int             _id;
  Timer			shootTime;
	//bool			none;
};


#endif /* GameEngine_HH_ */
