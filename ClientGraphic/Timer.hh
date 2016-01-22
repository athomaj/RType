//
// Timer.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Thu Dec  3 21:46:43 2015 Timothy Burdairon
// Last update Thu Dec  3 21:46:43 2015 Timothy Burdairon
//

#ifndef Timer_HH_
# define Timer_HH_

# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Graphics.hpp>
# include "GameTime.hh"

class Timer
{
public:
	Timer();
	Timer(float );
	~Timer();
	void setTimer(float);
	void restart();
	float getTime();
	bool isTime();
	bool checkTime();
private:
	sf::Clock time;
	float rate;
};


#endif /* ! Timer_HH_ */
