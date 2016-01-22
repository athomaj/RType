/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scenario.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 1 décembre 2015, 17:07
 */

#ifndef SCENARIO_HH
#define SCENARIO_HH

#include <iostream>
#include <map>
#include "Entity/Entity.hh"

typedef std::vector<std::vector<Entity*> >			CY_vector;
typedef std::map<std::string, std::vector<Entity*> > EC_map;

/** 
 * Scenario contient le scénario entier d'un niveau ainsi que le scénario des games objects\n
 * Les indices de vector correspondent au cycle n\n
 * Les cycles d'entité (e.n) s'additionne au cycle principale de création n soit n + e.n\n
 * @Exemple
 * cycle[3] == Entity<Trooper>\n
 * Trooper[2] <= Action au cycle 5 car 3 + 2 = 5
 */
class Scenario
{
private:
	/**
	 * List des entité par cycle
	 * cycle[numcycle][entitylist]
	 */
	std::vector<std::vector<Entity*> >				cycle;
	/**
	 * Sous-cycles d'une entité
	 * entitycycle[entité][action]
	 */
	std::map<std::string, std::vector<Entity*> >	entityCycle;	
	
	void	addCycle();
	void	addEntityCycle(const std::string type);
public:
	Scenario();
	Scenario(const Scenario& orig);
	virtual ~Scenario();
	
	/**
	 * Ajoute une entité a un cycle spécifique a partir du niveau lu
	 * 
	 * @param numcycle
	 * @param entity (entité)
	 */
	void		addToCycle(int numcycle, Entity *entity);
	
	/**
	 * Aujoute une entité lié à un cycle
	 * 
	 * @param numcycle
	 * @param entity exemple (arme)
	 */
	void		addToEntityCycle(int numcycle, Entity *entity);
	void		showCycle();
	void		showEntityCycle();
	CY_vector	getCycle() const;
	EC_map		getEntityCycle() const;
};

#endif /* SCENARIO_HH */

