#include "Parser.hh"

Parser::Parser(const std::string & _name)
{
	name = _name;
	//pointer;
	pointer["OBJECT"] = &Parser::setObject;
	pointer["ID"] = &Parser::setID;
	pointer["SPAWN"] = &Parser::setSpawn;
	pointer["HP"] = &Parser::setHP;
	pointer["POSITION"] = &Parser::setPosition;
	pointer["SHOT"] = &Parser::setShot;
	pointer["SPEED"] = &Parser::setSpeed;
	pointer["SIZE"] = &Parser::setSize;
	pointer["MISSILESIZE"] = &Parser::setMissileSize;
	pointer["MISSILESPEED"] = &Parser::setMissileSpeed;
	currentAction = Parser::NOTHING;
	open(_name);
}

Parser::~Parser()
{
	
}

int		Parser::stringToInt(std::string &str)
{
	float f;
	
	std::stringstream tmp(str);
	tmp >> f;
	return (f);
}

void Parser::setObject(std::string &arg)
{
	currentAction = Parser::OBJECT;
	currentObject = new GameObject;
    currentObject->setState(WAITING);
	objectList.push_back(currentObject);
	currentObject->setType(arg);
}

void Parser::setID(std::string &arg)
{
	currentAction = Parser::ID;
	currentObject->setId(stringToInt(arg));
}

void Parser::setSpawn(std::string &arg)
{
	currentAction = Parser::SPAWN;
	currentObject->setSpawn(stringToInt(arg));
}

void Parser::setHP(std::string &arg)
{
	currentAction = Parser::HP;
	currentObject->setHP(stringToInt(arg));
}

void Parser::setPosition(std::string &arg)
{
	currentAction = Parser::POSITION;
}

void Parser::AddPosition(std::string &args)
{
	if (currentAction == Parser::POSITION)
	{
		size_t z = 0;
		size_t n = 0;
		unsigned int cnt = 0;
		int pos[2];
		while (z <= args.size())
			{
			n = args.find_first_of(',', z);
			if (n > args.size())
				n = args.size();
			std::string sub(args.substr(z, n-z).c_str());
			std::stringstream tmp(sub.c_str());
			tmp >> pos[cnt];
			z = n + 1;
			++cnt;
		}
	currentObject->setPath(pos[0], pos[1]);
	}
}

void Parser::setSize(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	unsigned int cnt = 0;
	int pos[2];
	currentAction = Parser::SIZE;
	while (z <= args.size())
	{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		std::string sub(args.substr(z, n-z).c_str());
		std::stringstream tmp(sub.c_str());
		tmp >> pos[cnt];
		z = n + 1;
		++cnt;
	}
	//currentObject->setPath(pos[0], pos[1]);
	currentObject->setSize(pos[0], pos[1]);
}


void Parser::setMissileSize(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	currentAction = Parser::MISSILESIZE;
	unsigned int cnt = 0;
	int pos[2];
	while (z <= args.size())
		{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		std::string sub(args.substr(z, n-z).c_str());
		std::stringstream tmp(sub.c_str());
		tmp >> pos[cnt];
		z = n + 1;
		++cnt;
	}
	currentObject->setMissileSize(pos[0], pos[1]);
	//currentObject->setPath(pos[0], pos[1]);
}

void Parser::setMissileSpeed(std::string &arg)
{
	currentAction = Parser::MISSILESPEED;
	//currentObject->setShotFrequency(stringToInt(arg));
	currentObject->setMissileSpeed(stringToInt(arg));
}


void Parser::setShot(std::string &arg)
{
	currentAction = Parser::SHOT;
	currentObject->setShotFrequency(stringToInt(arg));
}

void Parser::setSpeed(std::string &arg)
{
	currentAction = Parser::SPEED;
	currentObject->setSpeed(stringToInt(arg));
}


void Parser::open(const std::string &file)
{
	std::string line;
	std::ifstream myfile(file.c_str());
	if (myfile)  // same as: if (myfile.good())
	    {
			while (getline( myfile, line))  // same as: while (getline( myfile, line ).good())
			  {
				size_t equal = line.find(':');
				if (equal < line.size())
				{
					std::string firstString = line.substr(0, equal);
					std::string lastString = line.substr(equal + 1, line.size() - equal);
					parseLine(firstString, lastString);
				}
				else
					AddPosition(line);
			  }
			myfile.close();
		}
	else
	{
		std::cout << "fail open" << std::endl;
	}
}


void	Parser::parseLine(std::string &name, std::string &args)
{
	if (pointer.find(name) != pointer.end())
	{
		type t = (pointer[name]);
		(this->*t)(args);
	}
}

std::list<GameObject*> &Parser::getObjectList()
{
	return (objectList);
}

// int	main()
// {
// 	Parser tmp("basic.txt");
// 	std::list<GameObject*> &t = tmp.getObjectList();
// 	for (std::list<GameObject*>::iterator it = t.begin(); it != t.end(); ++it)
// 	{
// 		std::cout << "type:" << (*it)->getType() << std::endl;
// 		std::cout << "id:" << (*it)->getId() << std::endl;
// 		std::cout << "Spawn:" << (*it)->getSpawn() << std::endl;
// 		std::cout << "Hp:" << (*it)->getHP() << std::endl;
// 		std::cout << "Shot:" << (*it)->getShotFrequency() << std::endl;
// 		std::cout << "Speed:" << (*it)->getSpeed() << std::endl;
// 		std::list<t_coord *> list = (*it)->getPath();
// 		for (std::list<t_coord *>::iterator it = list.begin(); it != list.end(); ++it)
// 		{
// 			std::cout << "x:" << (*it)->x << " y:" << (*it)->y << std::endl;
// 		}

// 	}
// }
