
#ifndef PARSER_HH_
#define PARSER_HH_

#include <list>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include "GameObject.hh"

class Parser
{
public:
	enum ACTION {OBJECT, ID, SPAWN, HP, POSITION,SHOT, SPEED, SIZE, MISSILESIZE,MISSILESPEED, NOTHING};
public:
	Parser(const std::string &);
	~Parser();
	void 	open(const std::string &file);
	void	parseLine(std::string &name, std::string &args);
	void 	setObject(std::string &arg);
	void 	setID(std::string &arg);
	void 	setSpawn(std::string &arg);
	void 	setHP(std::string &arg);
	void 	setPosition(std::string &arg);
	void 	setShot(std::string &arg);
	void 	setSpeed(std::string &arg);
	void 	setSize(std::string &args);
	void 	setMissileSpeed(std::string &args);
	void 	setMissileSize(std::string &args);


	
	int		stringToInt(std::string &str);
	void 	AddPosition(std::string &arg);
	std::list<GameObject*> &getObjectList();



		
private:
	typedef void (Parser::*type)(std::string &);
	std::string name;
	std::map<std::string, type> pointer;
	std::list<GameObject*> objectList;
	GameObject				*currentObject;
	ACTION					currentAction;
};


#endif /* */
