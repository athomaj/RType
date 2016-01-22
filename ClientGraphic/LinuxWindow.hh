#ifdef WIN32
#else
#ifndef LinuxWindow_H_
#define LinuxWindow_H_


#include "IWindow.hh"


class LinuxWindow : public IWindow
{
public:
  LinuxWindow(int, int, const std::string &, const std::string &);
 virtual ~LinuxWindow();
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
virtual   void SwitchGameOrientation();

virtual   Animation *getObject(const std::string &, int);

virtual   void drawGameObjects();
virtual   void MoveObjects();
virtual void	drawPlayerLives();
virtual   Animation *getPlayer();
virtual void addScoreToPlayer(int, int);
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
virtual Animation *getAnimation(int id);
    virtual void setMainPlayer(Animation*);



private:
	sf::Text 												liveText;
	sf::Font 												liveFont;
	sf::Sprite												*heart;
	sf::Texture												*heartTexture;

  int gameWidth;
  int gameHeight;
  sf::RenderWindow *window;
  Loader		*loadInfo;
  sf::Event event;
  Animation *mainPlayer;
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
#endif
