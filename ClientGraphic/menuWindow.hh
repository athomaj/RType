#ifndef _MENUWINDOW_HH_
# define _MENUWINDOW_HH_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Loader.hh"
#include "menu.hh"
#include "MouseOnBox.hh"
#include "OptionPage.hh"
#include "IClient.h"
#include "Mutex.hpp"
#include "ManageAction.hpp"
#include "IWindow.hh"

class NetworkEvent;
class ConnectionPage;
class RoomPage;
class LevelPage;
class OptionPage;
class GameEngine;
class LinuxWindow;
class ScorePage;
class DeadPage;
class EndPage;
class WaitingPage;

class MenuWindow
{
public:
  enum windowPage {CONNECTION, ROOM, LEVEL, OPTION, SCORE, WAIT, END, DEAD, NONE};
  MenuWindow(int x, int y, const std::string &name);
  ~MenuWindow();
  void setGameWidth(int x);
  void setGameHeight(int y);
  bool isOpen();
  bool windowEventTrigger();
  bool eventTrigger(sf::Event::EventType evenType);
  bool keyTrigger(sf::Keyboard::Key keyType);
  void close();
  void clear();
  void checkEvent();
  void drawBack();
  void display();
  void checkMouseEvent();
    IWindow*    getWindowGame();
    bool canPlay() const;
    void setTcpClient(IClient*);
    void setConnected(bool const);
    bool getConnected() const;
    NetworkEvent* getNetEvent();
    IMutex* getMutex();
    RoomPage& getRoom();
    LevelPage& getLevel();
    EndPage*    getEndPage();
    IClient*    _tcpClient;
  void restartMenuPages();
  windowPage	currentPage;
  bool			play;
    int _port;
    int                     _playerId;
private:
  sf::Sprite				sprite;
  bool						mouseClicked;
  sf::Mouse					mouse;
  int 						width;
  int 						height;
  sf::RenderWindow 			*window;
  Loader               		*load;
  Menu						*menu;
  ConnectionPage			*conectPage;
  RoomPage					*room;
  LevelPage					*level;
  ScorePage				*scorePage;
  OptionPage				*optionPage;
  DeadPage				*deadPage;
  EndPage				*endPage;
  WaitingPage				*waitPage;
  sf::Event 				event;
  int           			currentPositionWindowSprite;
  int           			sizeXspriteBackground;
  int           			speed;
  std::string 				windowName;
  std::list<MouseOnBox*> 	listMouseOnBox;
  IWindow 				*windowGame;
  GameEngine				*game;
  bool						exit;
  NetworkEvent				*netEvent;
  char						c;
  sf::Texture				textureLogo;
  IMutex*                 _mutex;
  bool                    _connected;
  ManageAction            _actionManager;
};


#include "NetworkEvent.hh"
#include "RoomPage.hh"
#include "ConnectionPage.hh"
#include "LevelPage.hh"
#include "ScorePage.hh"
#include "DeadPage.hh"
#include "EndPage.hh"
#include "GameEngine.hh"
#include "waitingPage.hh"

#endif
