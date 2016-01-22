#ifndef _LEVELPAGE_
# define _LEVELPAGE_

#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/types.h>
#include <dirent.h>

#include "SFML/Graphics.hpp"

#include "MouseOnBox.hh"
#include "WriteInBox.hh"
#include "NetworkEvent.hh"
#include "IMenu.h"

# define MAX_TXT 2

class LevelPage
{
public:
  LevelPage(int, int, NetworkEvent &);
  ~LevelPage();
  void drawBackGround(sf::RenderWindow &window, bool);
  void mousePositionBox(sf::RenderWindow &window, bool mouseClicked);
  void restart();
  bool checkBack();
  void addListMap(const std::string &roomName);
  void addListPlayer(const std::string &mapName);
  void removeListPlayer(const std::string &playerName);
  void setPlayerName(const std::string &);
  bool checkPlay();
  void  		mapsInDirectory();
  std::string &getCurrentFocusMap();
    void setCurrentFocusMap(std::string const&);

private:
  NetworkEvent& netEvent;
  std::string playerName;
  int           width;
  int           height;
  sf::Vector2f defaultPos;
  sf::Vector2f backPos;
  sf::Vector2f readyPos;
  sf::Font fontLevel;
  sf::Text textLevel[MAX_TXT];
  sf::Sprite levelBack;
  sf::Sprite readyButton;
  sf::Sprite backButton;
  bool back;
  bool canPlay;
  sf::Mouse mouse;
  std::string currentFocus;
  std::string currentFocusMap;
  std::map<std::string, MouseOnBox *> mouseBox;
  std::map<std::string, WriteInBox *> writeBox;

  std::map<MouseOnBox *, WriteInBox *>	mapList;
  sf::RectangleShape currentMap;
};


#endif
