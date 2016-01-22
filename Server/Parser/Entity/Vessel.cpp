/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vessel.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 * 
 * Created on 2 décembre 2015, 12:02
 */

#include "Vessel.hh"

/*
 * Cycle début, cycle fin, orientation, weapon.
 */
Vessel::Vessel()
{
	this->name = "Vessel";
	this->nbToken = 4;
}

Vessel::~Vessel()
{
}

bool Vessel::saveLine(std::string line)
{
	this->getTokens(line);
	this->checkNbTokens();
	
	this->numcycle = atoi(tokens[0].c_str());
	this->type = tokens[3];
	return (true);
}
