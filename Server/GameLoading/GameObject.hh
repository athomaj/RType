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
#include <list>
#include "IGameObject.hh"

class GameObject : public IGameObject
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
	int			spawn;
	int			shotFrequency;
	std::list<t_coord*>	path;
    State   state;
    int			sizeX;
    int			sizeY;
    int			missileSizeX;
    int			missileSizeY;
    int			missileSpeed;
    int			iteratorPosition;

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

	virtual void setSpawn(int);
	virtual void setShotFrequency(int);
	virtual void setPath(int, int);

	virtual int getSpawn() const;
	virtual int getShotFrequency() const;
	virtual std::list<t_coord*> &getPath();

    virtual State         getState() const;
    virtual void        setState(State const);

    virtual	void setMissileSpeed(int);
    virtual	void setMissileSize(int, int);
    virtual	void setSize(int, int);

    virtual	int getMissileSpeed() const;
    virtual	int getMissileSizeX() const;
    virtual	int getMissileSizeY() const;
    virtual	int getSizeX() const;
    virtual	int getSizeY() const;

    virtual int getCurrentIterator() const;
    virtual void setCurrentIterator(int);




	//Fin IGameObject
};

#endif /* GAMEOBJECT_HH */

