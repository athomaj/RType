//
//  ManageAction.cpp
//  ClientRType
//
//  Created by Julien Athomas on 14/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ManageAction.hpp"

std::string actionUnser(const char* data)
{
    std::string action(data);
    return action;
}

ManageAction::ManageAction(MenuWindow& win) :
    _win(win)
{
    actions[1] = &ManageAction::connected;
    actions[2] = &ManageAction::roomList;
    actions[3] = &ManageAction::roomCreate;
    actions[4] = &ManageAction::joinRoom;
    actions[5] = &ManageAction::leaveRoom;
    actions[6] = &ManageAction::gameReady;
    actions[7] = &ManageAction::gameStart;
    actions[8] = &ManageAction::dataMap;
    actions[9] = &ManageAction::endGame;
    actions[10] = &ManageAction::score;

}

void ManageAction::roomCreate(Packet* packet)
{
    std::cout << "create room" << std::endl;
}

void ManageAction::connected(Packet* packet)
{
    _win.getNetEvent()->menuRoom();
    std::cout << "connected" << std::endl;
    unsigned char* data = Packet::toBuf(packet->getData());
    std::string name(reinterpret_cast<char*>(data));
    _win.getRoom().addPlayerName(name);
    _win.getNetEvent()->setName(name);
    _win.setConnected(true);
    packet->getData();
    _win.getNetEvent()->roomList();
    free(data);
}

void ManageAction::roomList(Packet * packet)
{
    std::string roomName("");
    auto data = packet->getData();
    for (unsigned int i=3;i<data.size() - 1; ++i)
    {
        roomName += data[i];
    }
    std::cout << "roomName: " << roomName << std::endl;
    _win.getRoom().addListRoom(roomName, data[1], data[2]);
}

void ManageAction::joinRoom(Packet * packet)
{
    std::string roomName("");
    auto data = packet->getData();
    for (unsigned int i=0;i<data.size() - 1; ++i)
    {
        roomName += data[i];
    }
    _win.getRoom().addPlayerToRoom(roomName);
    std::cout << "joinRoom" << std::endl;
}

void ManageAction::leaveRoom(Packet * packet)
{
    std::string roomName("");
    auto data = packet->getData();
    for (unsigned int i=0;i<data.size() - 1; ++i)
    {
        roomName += data[i];
    }
    _win.getRoom().removePlayerFromRoom(roomName);
    std::cout << "leaveRoom" << std::endl;
}

void ManageAction::gameReady(Packet * packet)
{
    _win.getNetEvent()->waitingPage();
}

void ManageAction::gameStart(Packet * packet)
{
    auto& data = packet->getData();
    int id = data[0];
    std::string tmpPort("");
    std::string mapName("");
    for (unsigned int i=2; i<data.size() - 5; ++i)
        mapName.push_back(data[i]);
    for (unsigned long i=data.size() - 4; i<data.size(); ++i)
    {
        tmpPort += data[i];
    }
    _win.getLevel().setCurrentFocusMap(mapName);
    _win.getWindowGame()->loadNewGame(mapName);
    _win.play = true;
    _win._port = static_cast<int>(std::stoi(tmpPort));
    _win._playerId = id;
}

void ManageAction::dataMap(Packet * packet)
{
    std::stringstream ss(reinterpret_cast<char *>(Packet::toBuf(packet->getData())));
    std::string tmp;
    std::vector<std::string> playerNames;
    
    while (ss.good())
    {
        ss >> tmp;
        _win.getLevel().addListPlayer(tmp);
        std::cout << tmp << std::endl;
        tmp.clear();
    }
    _win.getNetEvent()->menuLevel();
}

void ManageAction::endGame(Packet * packet)
{
    std::stringstream ss(reinterpret_cast<char *>(Packet::toBuf(packet->getData())));

    _win.getEndPage()->restart();
    int nbPlayer;
    ss >> nbPlayer;
    
    std::string name;
    std::string score;
    for (int i=0; i<nbPlayer; ++i)
    {
        ss >> name;
        ss >> score;
        _win.getEndPage()->addScore(name + " - " + score);
        name.clear();
        score.clear();
    }
    _win.getNetEvent()->endPage();
}

void ManageAction::score(Packet * packet)
{
    std::cout << "score" << std::endl;
}

void ManageAction::checkAction(IClient* client)
{
    if (!client)
        return ;
    try
    {
        Packet *action = reinterpret_cast<ASocket *>(client->getSocket())->getData<Packet *>(&unserPacket);
        (this->*actions[action->getType()])(action);
    }
    catch (std::exception const& e)
    {
    }
}