/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scenario.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 * 
 * Created on 1 décembre 2015, 17:07
 */

#include "Scenario.hh"

Scenario::Scenario()
{
}

Scenario::Scenario(const Scenario& orig)
{
	(void)orig;
}

Scenario::~Scenario()
{
}

void Scenario::addCycle()
{	
	std::cout << "addcycle start" << std::endl;
	std::vector< Entity* > *toto = new std::vector< Entity* >;
	this->cycle.push_back(*toto);
}

void Scenario::addToCycle(int numcycle, Entity *entity)
{
	std::cout << "addtocycle start" << std::endl;
	int size = cycle.size();
	
	while (size <= numcycle)
	{
		this->addCycle();
		++size;
	}
	std::cout << "ajout entity " << entity->getType() << " sur " << numcycle << std::endl;
	this->cycle[numcycle].push_back(entity);
	std::cout << this->cycle[numcycle].size() << std::endl;
	std::cout << this->cycle[numcycle][0]->getType() << std::endl;
}

void Scenario::addEntityCycle(std::string type)
{
	if (entityCycle.find(type) == entityCycle.end())
	{
//		std::map<std::string, std::vector< Entity* > >	entity = new std::map<std::string, std::vector< Entity* > >;
		std::cout << "create map for " << type << std::endl;
		std::vector< Entity* > *toto = new std::vector< Entity* >;
		entityCycle.insert(std::pair<std::string, std::vector<Entity* > >(type, *toto));
	}
	else
	{
		Entity *entity = new Entity();
		entityCycle[type].push_back(entity);		
	}
}

void Scenario::addToEntityCycle(int numcycle, Entity *entity)
{
	std::cout << "addToEntityCycle start " << std::endl;
	std::string type = entity->getName();
	int size = entityCycle[type].size();
	
	while (size < numcycle)
	{
		this->addEntityCycle(type);
		++size;
	}
	std::cout << "ajout entity " << entity->getType() << " à " << numcycle << " sur " << 
			this->entityCycle[type].size() << std::endl;
	this->entityCycle[type].push_back(entity);
	std::cout << "entityCycle : " << this->entityCycle[type].size() << std::endl;
//	std::cout << this->cycle[numcycle][0]->getType() << std::endl;
}

void Scenario::showCycle()
{
	std::cout << "showcycle start" << std::endl;
	int	i = -1;
	int size = cycle.size();
	int j;
	int size2;
	
	while (++i < size)
	{
		std::cout << "cycle [" << i << "] :" << std::endl;
		size2 = cycle[i].size();
		j = -1;
		while (++j < size2)
		{
			std::cout << "entity [" << j << "] :" << cycle[i][j]->getType()
					<< " posY : " << cycle[i][j]->getPosY() << std::endl;
		}
	}
}

void Scenario::showEntityCycle()
{
	EC_map::iterator it = entityCycle.begin();
	int i;
	int size;
	
	while (it != entityCycle.end())
	{
		i = -1;
		size = it->second.size();
		while (++i < size)
		{
			std::cout << it->first << " [" << i << "] :" << it->second[i]->getType() << std::endl;
		}
		++it;
	}
}


CY_vector Scenario::getCycle() const
{
	return (this->cycle);
}

EC_map Scenario::getEntityCycle() const
{
	return (this->entityCycle);
}
