//
// Parsing.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Fri Dec  4 00:43:47 2015 Timothy Burdairon
// Last update Sun Jan  3 22:05:35 2016 Timothy Burdairon
//

#include "Parsing.hh"

Parsing::Parsing(std::map<std::string, std::list<Animation*> *> *typeGameObjects) : map(typeGameObjects)
{
	currentAnimation = NULL;
	pointer["NORMAL"] = &Parsing::setTypeAnimationNormal;
	pointer["ATTACK"] = &Parsing::setTypeAnimationAttack;
	pointer["MOVEMENT"] = &Parsing::setTypeAnimationMovement;
	pointer["DEATH"] = &Parsing::setTypeAnimationDeath;
	pointer["SOUND"] = &Parsing::setCurrentSound;
	pointer["scale"] = &Parsing::setScale;
	pointer["distanceMove"] = &Parsing::setDistanceMove;
	pointer["frequencyMove"] = &Parsing::setFrequencyMove;
	pointer["frequencyAnimation"] = &Parsing::setFrequencyAnimation;
	pointer["position"] = &Parsing::setSpawningPos;
	pointer["spritePosition"] = &Parsing::setSpritePosition;
	pointer["nextPosition"] = &Parsing::setNextPos;
	pointer["rotation"] = &Parsing::setRotation;
	pointer["positionShoot"] = &Parsing::setPositionShoot;
	pointer["volume"] = &Parsing::setVolume;
	pointer["pitch"] = &Parsing::setPitch;
	pointer["loop"] = &Parsing::setLoop;
	typeAnimation = Animation::NORMAL;
	currentAudio = NULL;
}

Parsing::~Parsing()
{

}


std::map<std::string, std::list<Animation*> *> Parsing::parseFiles()
{
	for (std::map<std::string, std::list<Animation*> *>::iterator it = map->begin(); it != map->end(); ++it)
	{
		std::string resource("parsing/");
		resource.append((*it).first);
		resource.append(".txt");
		for (std::list<Animation *>::iterator ita = (*it).second->begin(); ita != (*it).second->end(); ++ita)
		{
			currentAudio = NULL;
			currentAnimation = (*ita);
			open(resource);
			currentAnimation->setOffset((int)((float)(currentAnimation->getOffsetX()) * currentAnimation->getScale()),
					(int)((float)(currentAnimation->getOffsetY()) * currentAnimation->getScale()));
			if (currentAudio != NULL)
				currentAnimation->setSound(currentAudio);
		}
	}
	return (*map);
}


void Parsing::setTypeAnimationNormal(std::string &args)
{
	//std::cout << "NORMAL" << std::endl;
	typeAnimation = Animation::NORMAL;
	args = args;
}

void Parsing::setTypeAnimationAttack(std::string &args)
{
	//std::cout << "ATTACL" << std::endl;

	typeAnimation = Animation::ATTACK;
	args = args;
}

void Parsing::setTypeAnimationMovement(std::string &args)
{
	//std::cout << "MOVEMENT" << std::endl;
	typeAnimation = Animation::MOVEMENT;
	args = args;
}

void Parsing::setTypeAnimationDeath(std::string &args)
{
	typeAnimation = Animation::DEATH;
	args = args;
}


void Parsing::setVolume(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	float pos;
	while (z <= args.size())
	{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		std::string sub(args.substr(z, n).c_str());
		std::stringstream tmp(sub.c_str());
		tmp >> pos;
		z = n + 1;
		}
	currentAudio->setVolume(pos);
}

void Parsing::setPitch(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	float pos;
	while (z <= args.size())
	{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		std::string sub(args.substr(z, n).c_str());
		std::stringstream tmp(sub.c_str());
		tmp >> pos;
		z = n + 1;
	}
	currentAudio->setPitch(pos);
}

void Parsing::setLoop(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	//float pos;
	std::string sub("");
	while (z <= args.size())
	{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		sub.append(args.substr(z, n).c_str());
		//std::stringstream tmp(sub.c_str());
		//tmp >> pos;
		z = n + 1;
	}
	if (sub.find("true",0) != std::string::npos)
		currentAudio->setLoop(true);
	else
		currentAudio->setLoop(true);
}




void Parsing::setNextPos(std::string &args)
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
		//n = args.find_first_of(',',n);
	}
//	std::cout << "made it" << std::endl;
	currentAnimation->setNextPosition(pos[0], pos[1]);
}

void Parsing::setSpawningPos(std::string &args)
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
		//n = args.find_first_of(',',n);
	}
	//currentAnimation->setPositionAnim(pos[0], pos[1]);
}

void Parsing::setPositionShoot(std::string &args)
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
		//n = args.find_first_of(',',n);
	}
	currentAnimation->setPositionShoot(pos[0], pos[1]);

}

void Parsing::setSpritePosition(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	size_t t = 0;
	unsigned int cnt = 0;
	sf::Vector2<int> pos[3];
	while (z <= args.size())
	{

		n = args.find_first_of(',', z);
		t = args.find_first_of('|', z);
		if (n > args.size())
			n = args.size();
		if (t > args.size())
			t = args.size();
		if (t < n)
			n = t;
		std::string sub(args.substr(z, n-z).c_str());
		std::stringstream tmp(sub.c_str());
		if (cnt % 2 == 0)
			tmp >> pos[cnt / 2].x;
		else
			tmp >> pos[cnt / 2].y;
		z = n + 1;
		++cnt;
		//n = args.find_first_of(',',n);
	}
	if (typeAnimation == Animation::NORMAL)
	(*currentAnimation).setOffset((int)(pos[2].x) / 2, (int)(pos[2].y) / 2);
	(*currentAnimation).loadSprites(pos[0], pos[1], pos[2], typeAnimation);
}

void Parsing::setScale(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	float pos;
	while (z <= args.size())
	{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		std::string sub(args.substr(z, n).c_str());
		std::stringstream tmp(sub.c_str());
		tmp >> pos;
		z = n + 1;
	}

	currentAnimation->setScale(pos, typeAnimation);
//	currentAnimation->setOffset((float)(currentAnimation->getOffsetX()) * pos, (float)(currentAnimation->getOffsetY()) * pos);
}

void Parsing::setCurrentSound(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	std::string sub("");
	if (currentAudio != NULL)
		currentAnimation->setSound(currentAudio);
	while (z <= args.size())
	{

		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		sub.append(args.substr(z, n).c_str());
		z = n + 1;
	}
//	std::cout << "audio::" << sub << std::endl;
	currentAudio = new Audio(sub);
}


void Parsing::setFrequencyAnimation(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	float pos;
	while (z <= args.size())
	{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		std::string sub(args.substr(z, n).c_str());
		std::stringstream tmp(sub.c_str());
		tmp >> pos;
		z = n + 1;
	}
	currentAnimation->setFrequencyAnimation(pos, typeAnimation);
}

void Parsing::setDistanceMove(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	float pos;
	while (z <= args.size())
	{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		std::string sub(args.substr(z, n).c_str());
		std::stringstream tmp(sub.c_str());
		tmp >> pos;
		z = n + 1;
	}
	currentAnimation->setDistanceMove(pos);
}

void Parsing::setFrequencyMove(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	float pos;
	while (z <= args.size())
	{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		std::string sub(args.substr(z, n).c_str());
		std::stringstream tmp(sub.c_str());
		tmp >> pos;
		z = n + 1;
	}
	currentAnimation->setFrequencyMove(pos);
}

void Parsing::setRotation(std::string &args)
{
	size_t z = 0;
	size_t n = 0;
	float pos;
	while (z <= args.size())
	{
		n = args.find_first_of(',', z);
		if (n > args.size())
			n = args.size();
		std::string sub(args.substr(z, n).c_str());
		std::stringstream tmp(sub.c_str());
		tmp >> pos;
		z = n + 1;
	}
	currentAnimation->setRotation(pos);
}

void Parsing::open(std::string &file)
{
	std::string line;
	  std::ifstream myfile(file.c_str());
	  if (myfile)  // same as: if (myfile.good())
	    {
			while (getline( myfile, line ))  // same as: while (getline( myfile, line ).good())
			  {
				size_t equal = line.find(':');
				if (equal < line.size())
				{
					std::string firstString = line.substr(0, equal);
					std::string lastString = line.substr(equal + 1, line.size() - equal);
					whatIsTheLine(firstString, lastString);
				}
			  }
				myfile.close();
		}
}


void	Parsing::whatIsTheLine(std::string &name, std::string &args)
{
	if (pointer.find(name) != pointer.end())
	{
		type t = (pointer[name]);
		(this->*t)(args);
	}
}
