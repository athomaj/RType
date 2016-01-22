/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 * 
 * Created on 27 novembre 2015, 16:15
 */

#include "Entity.hh"

Entity::Entity()
{
	this->name = "None";
	this->type = "None";
}

Entity::Entity(const Entity& orig)
{
}

Entity::~Entity()
{
}

bool Entity::checkNbTokens()
{
	if (this->tokens.size() != this->nbToken)
	{
		std::string error;
		error.append("Nombre de token invalide : ");
		error += this->to_string(this->tokens.size());
		error += " / ";
		error += this->to_string(this->nbToken);
		throw std::runtime_error(error);
	}
	return (true);
}

std::string Entity::getName() const
{
	return (this->name);
}


void Entity::getTokens(std::string line)
{
	tokens.clear();
	std::string delimiters("\t");
	// Skip delimiters at beginning.
    std::string::size_type lastPos = line.find_first_not_of(delimiters, 0);
	
	// Find first "non-delimiter".
    std::string::size_type pos     = line.find_first_of(delimiters, lastPos);
	
	while (std::string::npos != pos || std::string::npos != lastPos)
    {
//		std::cout << "lastPos=" << lastPos << " diff" << (pos - lastPos) << std::endl;
        // Found a token, add it to the vector.
        tokens.push_back(line.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = line.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = line.find_first_of(delimiters, lastPos);
    }
}

int Entity::getNumCycle() const
{
	return (this->numcycle);
}

std::string Entity::getType() const
{
	return (this->type);
}

int Entity::getPosX() const
{
	return (this->posX);
}

int Entity::getPosY() const
{
	return (this->posY);
}


