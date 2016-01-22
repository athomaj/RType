/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Level.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 27 novembre 2015, 16:19
 */

#ifndef LEVEL_HH
#define LEVEL_HH

//
#include "Entity.hh"

class Level : public Entity
{
private:

public:
	Level();
//	Level(const Level& orig);
	virtual ~Level();
	
	bool	saveLine(std::string line);
};

#endif /* LEVEL_HH */

