//
// MapParsing.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Sat Dec 12 16:38:03 2015 Timothy Burdairon
// Last update Sat Dec 12 16:38:03 2015 Timothy Burdairon
//


#include "MapParsing.hh"

MapParsing::MapParsing(Loader *_load, const std::string &_fileName)
{
	loadInfo = _load;
	fileName = _fileName;
	std::string resource("map/");
	resource.append(fileName);
	fileName = resource;
	pointer["BackGround"] = &MapParsing::loadBackGroundMap;
	pointer["GameObjects"] = &MapParsing::loadGameObjectsMap;
	pointer["ImageBackGround"] = &MapParsing::loadImageBackGroundMap;
	parseFile();
}


MapParsing::~MapParsing()
{

}

void MapParsing::loadImageBackGroundMap(std::string &file)
{
	size_t z = 0;
	size_t n = 0;
	int 	pos;
	float 	time;
	float	scale;
	std::string name;
	int cnt = 0;

	while (z <= file.size())
	{
		n = file.find_first_of(',', z);
		if (n > file.size())
			n = file.size();
		std::string sub(file.substr(z, n).c_str());
		std::stringstream tmp(sub.c_str());
		if (cnt == 0)
			tmp >> name;
		else if (cnt == 1)
			tmp >> pos;
		else if (cnt == 2)
			tmp >> time;
		else
			tmp >> scale;
		z = n + 1;
		++cnt;
	}
	std::cout << "name:" << name << "pos:" << pos << "time" << time << "scale:" << scale << std::endl;
	loadInfo->loadImageBackGround(name,sf::Vector2f(100, pos), time, scale);
}

void MapParsing::loadBackGroundMap(std::string &file)
{
	std::cout << "file:" << file << std::endl;
	loadInfo->loadBackGround(file);
}

void MapParsing::loadGameObjectsMap(std::string &file)
{
	size_t z = 0;
	size_t n = 0;
	int 	nb;
	bool 	state;
	std::string stateBool;
	std::string name;
	int cnt = 0;

	while (z <= file.size())
		{
			n = file.find_first_of(',', z);
			if (n > file.size())
				n = file.size();
			std::string sub(file.substr(z, n).c_str());
			std::stringstream tmp(sub.c_str());
			if (cnt == 0)
				tmp >> name;
			else if (cnt == 1)
				tmp >> nb;
			else
				{
					tmp >> stateBool;
					if (stateBool.find("true") != std::string::npos)
						state = true;
					else
						state = false;
				}
			z = n + 1;
			++cnt;
		}
	std::cout << "name:" << name << "nb:" << nb << "state:" << state << std::endl;
	loadInfo->loadGameObjects(name, nb, state);
}


void  MapParsing::parseFile()
{
	std::string line;
	std::ifstream myfile(fileName.c_str());
	std::cout << fileName<< std::endl;
    // char buf[123];
    // getcwd(buf, 123);
    // std::cout << buf << std::endl;
	if (myfile)
	{
		while (getline( myfile, line ))
		  {
			std::cout << line << std::endl;
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
	else
	std::cout << "Fail open" << std::endl;
}

void MapParsing::whatIsTheLine(std::string &name, std::string &args)
{
	if (pointer.find(name) != pointer.end())
		{
			type t = (pointer[name]);
			(this->*t)(args);
		}
}


