//
// GameTime.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Thu Dec  3 21:27:31 2015 Timothy Burdairon
// Last update Thu Dec  3 21:27:32 2015 Timothy Burdairon
//

#include "GameTime.hh"


GameTime::GameTime() /*: gameTime(sf::Clock)*/
{

	//this->gameTime = sf::Clock;
}

GameTime::~GameTime()
{

}

float GameTime::getTime()
{
	static sf::Clock gameTime;

	sf::Time time = gameTime.getElapsedTime();
	return (time.asSeconds());
}
