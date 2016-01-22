#pragma once
#ifndef WindowsWindow_H_
#define WindowsWindow_H_


#include "IWindow.hh"


class WindowsWindow : public IWindow
{
public:
	WindowsWindow(int, int, const std::string &, const std::string &);
	virtual ~WindowsWindow();
	virtual void setGameHeight(int);
	virtual void setGameWidth(int);
	virtual void setSize(int, int);
	virtual void setVerticalSyncEnabled(bool);
	virtual bool isOpen();
	virtual bool windowEventTrigger();
	virtual   bool eventTrigger(sf::Event::EventType);
	virtual   bool keyTrigger(sf::Keyboard::Key);
	virtual   void close();
	virtual   void drawBackGround();
	virtual   void pause();
	virtual   void clear();
	virtual   void display();

	virtual void	drawPlayerLives();
	virtual   void SwitchGameOrientation();

	virtual   Animation *getObject(const std::string &, int);

	virtual   void drawGameObjects();
	virtual   void MoveObjects();
	virtual   Animation *getPlayer();
	virtual   Animation	*getLastObjectCreated();
	virtual   int	getGameWidth();
	virtual   int	getGameHeight();
	virtual   sf::RenderWindow *getWindow();
	virtual   void loadNewGame(const std::string &);
	virtual   void drawScore();
	virtual   sf::Event &getEvent();
	virtual   void setKeyRepeatEnabled(bool);

	virtual   void	setHp(const std::string &name, int id, int Hp);
	virtual   void	setPosition(int id, float x, float y);
	virtual   void 	fireWeapon(int, const std::string &weapon, int);
	virtual   void	setForce(int id, const std::string &name, int idForce);

	virtual void	addScoreToPlayer(int id, int);




private:
	sf::Text 												liveText;
	sf::Font 												liveFont;
	sf::Sprite												*heart;
	sf::Texture												*heartTexture;
	Animation *getAnimation(int id);
	int gameWidth;
	Animation *mainPlayer;

	int gameHeight;
	sf::RenderWindow *window;
	Loader		*loadInfo;
	sf::Event event;
	bool		isPaused;
	int		currentPositionWindowSprite;
	int		sizeXspriteBackGround;
	int		speedWindow;
	std::string windowName;
	bool 		windowOrientationChange;
	std::list<Animation*> gameObjects;
	std::list<Score*> scores;
	Animation				*lastObjectCreated;
	sf::Vector2<int>			posScore;
};


#endif /* */

