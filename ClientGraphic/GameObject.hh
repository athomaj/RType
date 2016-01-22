//
// GameObject.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Thu Dec  3 13:32:18 2015 Timothy Burdairon
// Last update Thu Dec  3 13:32:19 2015 Timothy Burdairon
//

#ifndef GAMEOBJECT_HH_
#define GAMEOBJECT_HH_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <list>

class GameObject
{

public:
	GameObject(int posX, int posY);
	GameObject(int posX, int posY, int rotation);
	GameObject();
	~GameObject();
	sf::Vector2<int> getPosition();
	float getRotation();
	void setPosition(int x, int y);
	void setRotation(int);

protected:
	sf::Vector2<int> position;
	std::list<sf::Sprite*> animationSprites;
	float		rotation;
};

#endif /* !GAMEOBJECT_HH_ */
