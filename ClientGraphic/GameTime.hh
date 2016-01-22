//
// GameTime.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Thu Dec  3 21:27:34 2015 Timothy Burdairon
// Last update Thu Dec  3 21:27:35 2015 Timothy Burdairon
//

#ifndef GAMETIME_HH_
#define GAMETIME_HH_


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class GameTime
{
public:
	GameTime();
	~GameTime();
static float getTime();
};

#endif /* ! GAMETIME_HH_ */
