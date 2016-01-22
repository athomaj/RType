//
// GameObject.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Thu Dec  3 13:32:12 2015 Timothy Burdairon
// Last update Thu Dec  3 13:32:14 2015 Timothy Burdairon
//

#include "GameObject.hh"

GameObject::GameObject(int posX, int posY, int _rotation) : rotation(_rotation)
{
	position = sf::Vector2<int>(posX, posY);
}

GameObject::GameObject(int posX, int posY)
{
	position = sf::Vector2<int>(posX, posY);
	rotation = 0;
}

GameObject::~GameObject()
{

}

float GameObject::getRotation()
{
	return (this->rotation);
}

sf::Vector2<int> GameObject::getPosition()
{
	return (this->position);
}

void GameObject::setPosition(int posX, int posY)
{
	position = sf::Vector2<int>(posX, posY);
}

void GameObject::setRotation(int rot)
{
	rotation = rot;
}
