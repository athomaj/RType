//
// Timer.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Thu Dec  3 21:46:39 2015 Timothy Burdairon
// Last update Thu Dec  3 21:46:39 2015 Timothy Burdairon
//

#include "Timer.hh"


Timer::Timer(float _rate): rate(_rate)
{

}

Timer::Timer()
{
	rate = 0;
}

Timer::~Timer()
{

}

void Timer::setTimer(float _rate)
{
	rate = _rate;
}

void Timer::restart()
{
	time.restart();
}


float Timer::getTime()
{
	//std::cout << "Time" << std::endl;
	sf::Time tmp = time.getElapsedTime();
	return (tmp.asSeconds());
}

bool Timer::checkTime()
{
	if (GameTime::getTime() + rate < getTime() + GameTime::getTime())
		return (true);
	return (false);
}

bool Timer::isTime()
{
	//std::cout << "isTime" << std::endl;
	if (rate < this->getTime())
	{
		restart();
		return (true);
	}
	return (false);
}


