//
// Score.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Fri Dec 11 14:09:53 2015 Timothy Burdairon
// Last update Fri Dec 11 14:09:53 2015 Timothy Burdairon
//


#include "Score.hh"


Score::Score(Animation *_player, float x, float y)
{
	player = _player;
	score = 18;
	std::string res("resources/");
	res.append("imagine_font.ttf");
	if (!scoreFont.loadFromFile(res.c_str()))
	        return ;
	    scoreText.setFont(scoreFont);
	    scoreText.setCharacterSize(35);
	    scoreText.setPosition(x, y);
	    scoreText.setColor(sf::Color(96, 96, 96, 255));
}

Score::~Score()
{

}

void Score::setScore(int newScore)
{
	score = newScore;
}


sf::Text	&Score::drawScore()
{
    scoreText.setString(getScoreString());
    return (scoreText);
}


std::string Score::getScoreString()
{
	std::stringstream str("");
	std::string name = player->getName();
	size_t n = 0;
	size_t z = 0;
	n = name.find_first_of('.', z);
			if (n > name.size())
				n = name.size();
		std::string sub(name.substr(z, n).c_str());
	str << sub.c_str();
	str <<  " ";
	str << score;
	return (str.str());
}

Animation *Score::getAnimation()
{
	return (player);
}
int Score::getScore() const
{
	return (score);
}

