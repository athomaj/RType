//
//  ManageAction.hpp
//  ClientRType
//
//  Created by Julien Athomas on 14/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ManageAction_hpp
#define ManageAction_hpp

#include <map>
#include "Packet.hpp"

class IClient;
class MenuWindow;
class ManageAction;

typedef void (ManageAction::*actionType)(Packet *);

class ManageAction
{
public:
    ManageAction(MenuWindow&);
    void checkAction(IClient* client);
private:
    void connected(Packet*);
    void roomList(Packet *);
    void joinRoom(Packet *);
    void leaveRoom(Packet *);
    void gameReady(Packet *);
    void gameStart(Packet *);
    void dataMap(Packet *);
    void endGame(Packet *);
    void score(Packet *);
    void roomCreate(Packet *);
    MenuWindow& _win;
    std::map<int, actionType> actions;
};

#include "IClient.h"
#include "menuWindow.hh"

#endif /* ManageAction_hpp */
