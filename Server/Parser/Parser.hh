/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 26 novembre 2015, 11:53
 */

#ifndef PARSER_HH
#define PARSER_HH

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Scenario.hh"
#include "Entity/Entity.hh"
#include "Entity/Level.hh"
#include "Entity/Vessel.hh"

#define SCRIPTDIR "Script" 

class Parser
{
private:
	std::string		levelName;
	std::string		typeName;
	std::string		extensionFile;
	std::string		tmpName;
	bool			isLevel;
	std::string		line;
	int				nbLine;
	int				nbLineOk;
	Entity			*entity;
	Scenario		*scenario;
	
	void		tryLoadEntity();
	void		reset();
	void		removeEndLine();
	void		parseLine();
	bool		isCommentLine();
	void		getParseEntity();
public:
	Parser();
	Parser(const Parser& orig);
	virtual ~Parser();
	
	void		load(std::string _levelName);
//	std::string	getLevelName() const;
	Scenario*	getScenario() const;
};

#endif /* PARSER_HH */

