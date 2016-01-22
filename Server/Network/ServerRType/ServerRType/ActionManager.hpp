//
//  ActionManager.hpp
//  ServerRType
//
//  Created by Julien Athomas on 09/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ActionManager_hpp
#define ActionManager_hpp

# include <map>
#include <iostream>
# include "IGameManager.h"
# include "Packet.hpp"

#include <sstream>

class ActionManager;

typedef void (ActionManager::*actionType)(std::pair<ISocket*, Packet *>&);

class ActionManager
{
public:
    ActionManager(IGameManager*);
    void runAction(std::pair<ISocket*, Packet *>&);
private:
    void newRoom(std::pair<ISocket*, Packet *>&);
    void joinRoom(std::pair<ISocket*, Packet *>&);
    void leaveRoom(std::pair<ISocket*, Packet *>&);
    void roomList(std::pair<ISocket*, Packet *>&);
    void play(std::pair<ISocket*, Packet *>&);
    void setName(std::pair<ISocket*, Packet *>&);
    void dataMap(std::pair<ISocket*, Packet *>&);
    void endGame(std::pair<ISocket*, Packet *>&);
private:
    IGameManager* _gameManager;
    std::map<int, actionType> actions;
};

#endif /* ActionManager_hpp */
