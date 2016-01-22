//
// Score.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Fri Dec 11 14:09:57 2015 Timothy Burdairon
// Last update Fri Dec 11 14:09:57 2015 Timothy Burdairon
//

#ifndef SCORE_HH_
# define SCORE_HH_

#include "Animation.hh"
#include <iostream>
#include <sstream>

class Score
{
public:
				Score(Animation *, float x, float y);
				~Score();
void 			setScore(int);
std::string 	getScoreString();
sf::Text		&drawScore();
Animation *getAnimation();
int getScore() const;




private:
	Animation *player;
	int			score;
	 sf::Text 												scoreText;
	 sf::Font 												scoreFont;
};



#endif /* SCORE_HH_ */
