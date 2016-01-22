/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IGameObject.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 3 décembre 2015, 17:48
 */

#ifndef IGAMEOBJECT_HH
#define IGAMEOBJECT_HH

enum State
{
    WAITING,
    SPAWNED,
    DEAD
};

class IGameObject
{
public:
	virtual void		setId(int value) = 0;
	virtual int			getId() const = 0;
	virtual void		setHP(int value) = 0;
	virtual int			getHP() const = 0;
	virtual void		setType(const std::string& value) = 0;
	virtual const std::string& getType() const = 0;
	virtual void		setPositionX(int value) = 0;
	virtual	int			getPositionX() const = 0;
	virtual void		setPositionY(int value) = 0;
	virtual	int			getPositionY() const = 0;
	virtual void		setSpeed(int value) = 0;
	virtual int			getSpeed() const = 0;
	virtual void		setOwner(int value) = 0;
	virtual int			getOwner() const = 0;
    virtual void        setSpawnCycle(int const) = 0;
    virtual void        setShootCycle(int const) = 0;
    virtual int        getSpawnCycle() const = 0;
    virtual int        getShootCycle() const = 0;
    virtual State         getState() const = 0;
    virtual void        setState(State const) = 0;
};

#endif /* IGAMEOBJECT_HH */

