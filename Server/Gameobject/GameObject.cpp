/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameObject.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 * 
 * Created on 26 novembre 2015, 12:00
 */

#include "GameObject.hh"

GameObject::GameObject()
{
	this->type = "None";
}

//GameObject::GameObject(const GameObject& orig):Entity(orig)
//{
//	(void)orig;
//}

GameObject::~GameObject()
{
}

void GameObject::affiche() const
{
	std::cout << "test" << std::endl;
}

void GameObject::setId(int value)
{
	this->id = value;
}

int GameObject::getId() const
{
	return (this->id);
}

void GameObject::setHP(int value)
{
	this->hp = value;
}

int GameObject::getHP() const
{
	return (this->hp);
}

void GameObject::setOwner(int value)
{
	this->owner = value;
}

int GameObject::getOwner() const
{
	return (this->owner);
}

void GameObject::setPositionX(int value)
{
	this->posx = value;
}

int GameObject::getPositionX() const
{
	return (this->posx);
}

void GameObject::setPositionY(int value)
{
	this->posy = value;
}

int GameObject::getPositionY() const
{
	return (this->posy);
}

void GameObject::setSpeed(int value)
{
	this->speed = value;
}

int GameObject::getSpeed() const
{
	return (this->speed);
}

void GameObject::setType(const std::string& value)
{
	this->type = value;
}

const std::string& GameObject::getType() const
{
	return (this->type);
}

void        GameObject::setSpawnCycle(int const cycle)
{
    spawnCycle = cycle;
}

void        GameObject::setShootCycle(int const cycle)
{
    shootCycle = cycle;
}

int        GameObject::getSpawnCycle() const
{
    return spawnCycle;
}

int        GameObject::getShootCycle() const
{
    return shootCycle;
}

State GameObject::getState() const
{
    return state;
}

void GameObject::setState(const State status)
{
    state = status;
}
