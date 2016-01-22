/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Level.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 * 
 * Created on 27 novembre 2015, 16:19
 */

#include "Level.hh"

Level::Level()
{
	this->name = "Level";
	this->nbToken = 4;
}

Level::~Level()
{
}

bool Level::saveLine(std::string line)
{
	this->getTokens(line);
	this->checkNbTokens();
	
//	int i = 0;
//	while (i < tokens.size())
//	{
//		std::cout << tokens[i] << std::endl;
//		++i;
//	}
	this->numcycle = atoi(tokens[1].c_str());
	this->type = tokens[0];
	this->posX = atoi(tokens[2].c_str());
	this->posY = atoi(tokens[3].c_str());
	
	return (true);
}
