#ifndef _CONNECTIONPAGE_HH_
# define _CONNECTIONPAGE_HH_

#include "SFML/Graphics.hpp"
#include "WriteInBox.hh"
#include "MouseOnBox.hh"
#include "NetworkEvent.hh"

#include <iostream>
#include <string>
#include "IMenu.h"

# define MAX_TXT 2


class ConnectionPage
{
public:
   ConnectionPage(int, int, NetworkEvent &);
  ~ConnectionPage();
  void 	drawBackGround(sf::RenderWindow &window, bool);
  void 	mousePositionBox(sf::RenderWindow &, bool);
  void	writeCharacter(char c);
  bool 	checkBack();
  bool 	checkConnect();
  void	restart();
  std::string &getName();
    std::string &getIP();

private:
  //  int selectedItemIndex;
  sf::Font fontConnect;
  sf::Text textConnect[MAX_TXT];
  sf::Sprite tmp;
  sf::Sprite connectButton;
  sf::Sprite BackButton;
  sf::Vector2f defaultPos;
  sf::Vector2f connectPos;
  sf::Vector2f backPos;

  sf::RectangleShape rectName;
  sf::RectangleShape rectIP;

  sf::Vector2f writeNamePos;
  sf::Vector2f writeIPPos;
  std::map<std::string, MouseOnBox *> mouseBox;
  std::map<std::string, WriteInBox *> writeBox;
  sf::Mouse mouse;
  int width;
  int height;
  std::string currentFocus;
  bool		back;
  bool 		connect;
  NetworkEvent&	netEvent;
};

#endif
