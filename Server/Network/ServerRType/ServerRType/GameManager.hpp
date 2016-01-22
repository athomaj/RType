//
//  ManageClient.hpp
//  ServerRType
//
//  Created by Julien Athomas on 09/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ManageClient_hpp
#define ManageClient_hpp

# include "IGameManager.h"
# include "ActionManager.hpp"
# include "Room.hpp"
# include "ISocket.h"
# include "ThreadPool.hpp"
# include "Packet.hpp"

class GameManager : public IGameManager
{
public:
    GameManager(IServer* serv);
    virtual void run();
    virtual void addRoom(std::string const&, int const, ISocket*);
    virtual std::vector<Room *>::iterator removeRoom(std::string const&);
    virtual void removeFromRoom(std::string const& roomName, ISocket*);
    virtual void addToRoom(std::string const& roomName, ISocket*);
    virtual void sendRooms();
    virtual unsigned long getRoomSize(std::string const& roomName) const;
    virtual int getAvailablePort();
    virtual void setAvailablePort(int const);
    virtual void checkDeadClients();
    virtual IServer* getServ();
    virtual std::vector<Room *>& getRooms();
    virtual void launchGame(Room *);
private:
    virtual void launchAction(std::pair<ISocket*, Packet *>&);
private:
    IServer*        _serv;
    IMutex*         _mutex;
    ActionManager   _actionManager;
    std::vector<Room *> _rooms;
    std::map<int, bool> _ports;
    int _playerByRoom;
    ThreadPool          _pool;
};

#endif /* ManageClient_hpp */
