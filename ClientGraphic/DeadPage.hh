#ifndef DEADPAGE_HH
# define DEADPAGE_HH

#include "SFML/Graphics.hpp"
#include "WriteInBox.hh"
#include "MouseOnBox.hh"
#include "NetworkEvent.hh"

#include <iostream>
#include <string>
#include <sstream>

#include "IMenu.h"

# define MAX_TXTE 4

class DeadPage
{
public:
  DeadPage(int, int, NetworkEvent &);
  ~DeadPage();
  void  drawBackGround(sf::RenderWindow &window, bool);
  void mousePositionBox(sf::RenderWindow &, bool);
  bool checkBack();
  void restart();
  void addTime(const std::string);
  void addScore(const std::string);
  void addMissile(const std::string);
  void addKill(const std::string);
  
private:
  sf::Font fontDead;
  sf::Text textDead[MAX_TXTE];
  sf::Sprite deadPages;
  sf::Sprite backButton;
  sf::Vector2f backPosi;
  NetworkEvent& netEvent;
  std::map<std::string, MouseOnBox *> mouseBox;
  sf::Mouse mouse;
  std::string currentFocus;
  bool back;

  int width;
  int height;
  sf::Vector2f defaultPos;
  std::map<std::string, WriteInBox *> writeBox;
};

#endif
