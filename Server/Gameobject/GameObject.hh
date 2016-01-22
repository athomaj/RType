/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameObject.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 7 décembre 2015, 15:27
 */

#ifndef GAMEOBJECT_HH
#define GAMEOBJECT_HH

#include <iostream>
#include "IGameObject.hh"
#include "../Parser/Entity/Entity.hh"

class GameObject : public IGameObject, public Entity
{
private:
protected:
	int		id;
	int		hp;
	int		owner;
	int		posx;
	int		posy;
	int		speed;
	std::string	type;
    int spawnCycle;
    int shootCycle;
    State   state;
public:
	GameObject();
//	GameObject(const GameObject& orig);
	virtual ~GameObject();
	virtual void affiche() const;

	//Debut IGameObject
	virtual void setId(int value);
	virtual int getId() const;
	virtual void setHP(int value);
	virtual int getHP() const;
	virtual void setOwner(int value);
	virtual int getOwner() const;
	virtual void setPositionX(int value);
	virtual int getPositionX() const;
	virtual void setPositionY(int value);
	virtual int getPositionY() const;
	virtual void setSpeed(int value);
	virtual int getSpeed() const;
	virtual const std::string& getType() const;
	virtual void setType(const std::string& value);
    virtual void        setSpawnCycle(int const);
    virtual void        setShootCycle(int const);
    virtual int        getSpawnCycle() const;
    virtual int        getShootCycle() const;
    virtual State         getState() const;
    virtual void        setState(State const);

	//Fin IGameObject
};

#endif /* GAMEOBJECT_HH */

