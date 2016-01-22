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
	this->missileSpeed = 0;
	this->missileSizeX = 0;
	this->missileSizeY = 0;
	this->sizeX = 0;
	this->sizeY = 0;
	this->iteratorPosition = 0;
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

void GameObject::setSpawn(int sp)
{
	spawn = sp;
}

void GameObject::setShotFrequency(int shot)
{
	shotFrequency = shot;
}

void GameObject::setPath(int _x, int _y)
{
	t_coord *tmp = new t_coord;
	tmp->x = _x;
	tmp->y = _y;
	path.push_back(tmp);
}

const std::string& GameObject::getType() const
{
	return (this->type);
}

int GameObject::getSpawn() const
{
	return (spawn);
}

int  GameObject::getShotFrequency() const
{
	return (shotFrequency);
}

std::list<t_coord*>  &GameObject::getPath()
{
	return (path);
}

State GameObject::getState() const
{
    return state;
}

void GameObject::setState(const State status)
{
    state = status;
}

void GameObject::setMissileSpeed(int value)
{
	missileSpeed = value;
}
void GameObject::setMissileSize(int _x, int _y)
{
	missileSizeX = _x;
	missileSizeY = _y;
}
void GameObject::setSize(int _x, int _y)
{
	sizeX = _x;
	sizeY = _y;
}

int GameObject::getMissileSpeed() const
{
	return (missileSpeed);
}
int GameObject::getMissileSizeX() const
{
	return (missileSizeX);
}
int GameObject::getMissileSizeY() const
{
	return (missileSizeY);
}
int GameObject::getSizeX() const
{
	return (sizeX);
}
int GameObject::getSizeY() const
{
	return (sizeY);
}
int GameObject::getCurrentIterator() const
{
	return (iteratorPosition);
}

void GameObject::setCurrentIterator(int value)
{
	iteratorPosition = value;
}

