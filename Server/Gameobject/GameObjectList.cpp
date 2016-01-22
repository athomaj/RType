/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameObjectList.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 * 
 * Created on 15 décembre 2015, 14:32
 */

#include <vector>
#include <stdexcept>

#include "GameObjectList.hh"

GameObjectList::GameObjectList()
{
}

GameObjectList::GameObjectList(const GameObjectList& orig)
{
}

GameObjectList::~GameObjectList()
{
}

void GameObjectList::addNewEmptyCycle()
{
	GO_vector go;
	
	this->cygo.push_back(go);
}

void GameObjectList::addGameObjectToCycle(int cycle, GameObject* go)
{
	unsigned long size = this->cygo.size();

	while (size >= cycle)
	{
		this->addNewEmptyCycle();
		++size;
	}
	this->cygo[cycle].push_back(go);
}

void GameObjectList::moveGameObjectToCycle(int cycle, int tocycle, GameObject* go)
{
	this->cygo[tocycle].push_back(go);
	
	GO_vector::iterator	it = std::find(cygo[cycle].begin(), cygo[cycle].end(), go);
	if (it != cygo.end())
		throw std::runtime_error("Object introuvable un cycle.");
	this->cygo[cycle].erase(it);
}

//GO_vector GameObjectList::getCycleGameObjectList()
//{
//	return (this->objectlist);
//}

void GameObjectList::clearCycle(int cycle)
{
	if (this->cygo[cycle].size() > 0)
		this->cygo[cycle].clear();
}
