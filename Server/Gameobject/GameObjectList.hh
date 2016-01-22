/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameObjectList.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 15 décembre 2015, 14:32
 */

#ifndef GAMEOBJECTLIST_HH
#define GAMEOBJECTLIST_HH

#include "GameObject.hh"

typedef std::vector<GameObject*>	GO_vector;
typedef std::vector<GO_vector>		CYGO_vector;

class GameObjectList
{
private:
	/**
	 * GameObject list par cycle
	 */
	CYGO_vector		cygo;

	void		addNewEmptyCycle();
public:
	GameObjectList();
	GameObjectList(const GameObjectList& orig);
	virtual ~GameObjectList();
	
	void		clearCycle(int cycle);
	void		addGameObjectToCycle(int cycle, GameObject* go);
	void		moveGameObjectToCycle(int cycle, int tocycle, GameObject* go);
	CYGO_vector	getCycleGameObjectList();
};

#endif /* GAMEOBJECTLIST_HH */

