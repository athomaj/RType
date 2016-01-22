/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameEngine.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 11 décembre 2015, 13:35
 */

#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH

#include "ServerUDP.hpp"
#include "ThreadCond.hpp"
#ifdef _WIN32
#include "ThreadCondWin.h"
#include "ThreadWin.h"
#endif
#include "Room.hpp"
#include "Thread.hpp"
# include "Parser.hh"
# include "CrossLoader.hh"

enum PacketType
{
    POS,
    POSMISPLAYER,
    
};

class IThread;

class GameEngine
{
private:
    IThreadCond	*_cond;
    Room		*_room;
    IThread*	_thread;
    IServer*	_servUdp;
    std::vector<GameObject> _objects;
    int         _curCycle;
    int         shotId;
public:
    GameEngine();
	GameEngine(const GameEngine& orig);
	virtual ~GameEngine();
	
    void            createPlayers(int const);
    void            checkActions();
    void            setServerUdp(IServer *);
	IThreadCond*		getThreadCond();
    void			setRoom(Room *);
    void			launch();
    IServer*		getServer();
    Room*			getRoom();
    void            movePlayer(Packet *);
    void            playerShoot(Packet *);
    void            playerLeave(Packet *);
    void            activateStrenght(Packet *);
    GameObject&     getObjectById(int const);
    void            sendNewData();
    void            moveObjects();
    bool            checkShootCollisions(GameObject&, int const, int const);
    void            addMobs();
    void            checkMobs();
    void 			moveObjectsToPosition(GameObject *it);
    int				getXValue(GameObject *obj);
    int				getYValue(GameObject *obj);


};

#endif /* GAMEENGINE_HH */

