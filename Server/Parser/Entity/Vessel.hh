/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vessel.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 2 décembre 2015, 12:02
 */

#ifndef VESSEL_HH
#define VESSEL_HH

#include "Entity.hh"

class Vessel : public Entity
{
private:
public:
	Vessel();
//	Vessel(const Vessel& orig);
	virtual ~Vessel();

	bool	saveLine(std::string line);
};

#endif /* VESSEL_HH */

