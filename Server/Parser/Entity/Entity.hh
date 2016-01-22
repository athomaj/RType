/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 27 novembre 2015, 16:15
 */

#ifndef ENTITY_HH
#define ENTITY_HH

#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Entity
{
private:
protected:
	std::string					name;//nom de lobjet
	std::vector<std::string>	tokens;//
	int							nbToken;//
	int							numcycle;//
	std::string					type;//enfant
	int							posX;
	int							posY;
public:
	Entity();
	Entity(const Entity& orig);
	virtual ~Entity();
	std::string to_string(int value)
	{
		std::ostringstream s;
		s << value;
		return (s.str());
	}
	bool		checkNbTokens();
	std::string getName() const;
	void		getTokens(std::string line);
	int			getNumCycle() const;
	std::string getType() const;
	int			getPosX() const;
	int			getPosY() const;
    virtual bool saveLine(std::string line){ return true; };
};

#endif /* ENTITY_HH */

