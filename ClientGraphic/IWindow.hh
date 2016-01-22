#pragma once
#ifndef IWindow_H_
#define IWindow_H_


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "Loader.hh"
#include "Score.hh"


class IWindow
{
public:
	virtual ~IWindow() {};
	virtual void setGameHeight(int) = 0;
	virtual void setGameWidth(int) = 0;
	virtual void setSize(int, int) = 0;
	virtual void setVerticalSyncEnabled(bool) = 0;
	virtual bool isOpen() = 0;
	virtual bool windowEventTrigger() = 0;
	virtual bool eventTrigger(sf::Event::EventType) = 0;
	virtual bool keyTrigger(sf::Keyboard::Key) = 0;
	virtual void close() = 0;
	virtual void drawBackGround() = 0;
	virtual void pause() = 0;
	virtual void clear() = 0;
	virtual void display() = 0;
	virtual void SwitchGameOrientation() = 0;
	virtual void	addScoreToPlayer(int, int) = 0;
    virtual void setMainPlayer(Animation*) = 0;

 
	virtual Animation				 *getObject(const std::string &, int) = 0;

	virtual		void				drawGameObjects() = 0;
	virtual		void				MoveObjects() = 0;
	virtual		Animation			*getPlayer() = 0;
	virtual		Animation			*getLastObjectCreated() = 0;
	virtual		int					getGameWidth() = 0;
	virtual		int					getGameHeight() = 0;
	virtual		sf::RenderWindow	*getWindow() = 0;
	virtual		void				loadNewGame(const std::string &) = 0;
	virtual		void				drawScore() = 0;
	virtual		sf::Event			&getEvent() = 0;
	virtual		void				setKeyRepeatEnabled(bool) = 0;

	virtual 	void				setHp(const std::string &name, int id, int Hp) = 0;
	virtual 	void				setPosition(int id, float x, float y) = 0;
	virtual		void 				fireWeapon(int, const std::string &weapon, int) = 0;
	virtual		void				setForce(int id, const std::string &name, int idForce) = 0;
    virtual Animation *getAnimation(int id) = 0;
};

#endif /* */