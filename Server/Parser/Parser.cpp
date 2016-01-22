/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 * 
 * Created on 26 novembre 2015, 11:53
 */

#include "Parser.hh"

Parser::Parser()
{
	this->levelName = "";
	this->typeName = "";
	this->extensionFile = ".txt";
	this->isLevel = false;
	this->nbLine = 0;
	this->nbLineOk = 0;
	this->scenario = new Scenario();
}

Parser::Parser(const Parser& orig)
{
	(void)orig;
}

Parser::~Parser()
{
}

void Parser::removeEndLine()
{
	if (*(this->line.rbegin()) == '\r')
	{
//		std::cout << "ARG" << std::endl;
		line.erase(line.length() - 1);
	}
}


void Parser::reset()
{
	this->nbLine = 0;
	this->nbLineOk = 0;
	this->line.clear();
	this->typeName = "";
}

bool Parser::isCommentLine()
{
	if (this->line.compare(0,2, "//") == 0)
		return (true);
	return (false);
}

void Parser::getParseEntity()
{
	if (this->nbLineOk == 0)
		std::cout << "check : [" << line << "]" << std::endl;
	if (line.compare("Level") == 0 || typeName.compare("Level") == 0)
	{
		this->entity = new Level();
		this->levelName = this->tmpName;
		this->typeName = "Level";
		this->isLevel = true;
	}
	else if (line.compare("Vessel") == 0 || typeName.compare("Vessel") == 0)
	{
		this->entity = new Vessel();
		this->typeName = "Vessel";
	}
}

void		Parser::parseLine()
{
	if (this->isCommentLine())
		return ;
	if (this->nbLineOk == 0)
	{
		this->getParseEntity();
	}
	else
	{
		this->getParseEntity();
//		this->entity = new Level();
		this->entity->saveLine(this->line);
		if (isLevel == true)
		{
			this->scenario->addToCycle(this->entity->getNumCycle(), this->entity);
		}
		else
		{
			this->scenario->addToEntityCycle(this->entity->getNumCycle(), this->entity);
		}
	}
	this->nbLineOk += 1;
}

void Parser::tryLoadEntity()
{
	CY_vector cycle = scenario->getCycle();
	int size = cycle.size();
	int i = -1;
	int	size2;
	int j;
	EC_map entityCycle = scenario->getEntityCycle();
	
	while (++i <= size)
	{
		size2 = cycle[i].size();
		j = -1;
		while (++j < size2)
		{
			if (entityCycle.find(cycle[i][j]->getType()) == entityCycle.end())
			{
				std::cout << "tryLoadEntity : " << cycle[i][j]->getType() << std::endl;
				this->reset();
				this->load(cycle[i][j]->getType());
				entityCycle = scenario->getEntityCycle();
				scenario->showEntityCycle();
			}
		}
	}
}

void		Parser::load(std::string _levelName)
{
	std::string filename = SCRIPTDIR + std::string("/") + _levelName + extensionFile;
	std::ifstream	file(filename.c_str());
	this->tmpName = _levelName;
	std::cout << std::endl << "Load of : " << _levelName << " in " << filename << std::endl;
//	std::string		line;
	
	if (file.is_open())
	{
		while (getline(file, line))
		{
			this->nbLine += 1;
			this->removeEndLine();
//			std::cout << "Parse line : [" << line << "]" << std::endl;
//			std::cout << line << std::endl;
			this->parseLine();
		}
		if (this->isLevel)
			this->scenario->showCycle();
	}
	file.close();
	if (this->isLevel == true)
	{
		this->isLevel = false;
		this->tryLoadEntity();
	}
}

//std::string Parser::getLevelName() const
//{
//	return (this->levelName);
//}

Scenario* Parser::getScenario() const
{
	return (this->scenario);
}
