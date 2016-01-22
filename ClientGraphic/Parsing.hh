//
// Parsing.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Fri Dec  4 00:43:50 2015 Timothy Burdairon
// Last update Fri Dec  4 00:43:51 2015 Timothy Burdairon
//

#ifndef PARSING_HH_
#define PARSING_HH_

#include "Animation.hh"
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>

class Parsing
{
public:
	typedef void (Parsing::*type)(std::string &);
	Parsing(std::map<std::string, std::list<Animation*> *>*);
	~Parsing();
	std::map<std::string, std::list<Animation*> *>  parseFiles();
	void open(std::string &);
	void setScale(std::string &);
	void setFrequencyMove(std::string &args);
	void setDistanceMove(std::string &args);
	void setFrequencyAnimation(std::string &args);
	void whatIsTheLine(std::string &name, std::string &args);
	void setSpawningPos(std::string &args);
	void setSpritePosition(std::string &args);
	void setNextPos(std::string &args);
	void setTypeAnimationNormal(std::string &args);
	void setTypeAnimationAttack(std::string &args);
	void setTypeAnimationMovement(std::string &args);
	void setTypeAnimationDeath(std::string &args);
	void setRotation(std::string &args);
	void setPositionShoot(std::string &args);
	void setCurrentSound(std::string &args);
	void setVolume(std::string &args);
	void setPitch(std::string &args);
	void setLoop(std::string &args);

private:
	std::map<std::string, std::list<Animation*> *> *map;
	Animation *currentAnimation;
	std::map<std::string, type> pointer;
	Animation::typeAnimation typeAnimation;
	std::list<Audio*>   audioList;
	Audio				*currentAudio;
};

#endif /* ! PARSING_HH_ */
