#ifndef ENDPAGE_HH
# define ENDPAGE_HH

#include "SFML/Graphics.hpp"
#include "WriteInBox.hh"
#include "MouseOnBox.hh"
#include "NetworkEvent.hh"

#include <iostream>
#include <string>
#include <sstream>

#include "IMenu.h"

# define MAX_TXTEND 5

class EndPage
{
public:
  EndPage(int, int, NetworkEvent &);
  ~EndPage();
  void  drawBackGround(sf::RenderWindow &window, bool);
  void	mousePositionBox(sf::RenderWindow &window, bool);
  bool	checkBack();
  void	restart();
  void addScore(const std::string &);
  
private:
  sf::Font fontEnd;
  sf::Text textEnd[MAX_TXTEND];
  sf::Text textName[1];
  sf::Sprite endPage;
  sf::Sprite backButton;
  sf::Vector2f	backPos;
  NetworkEvent	netEvent;
  std::map<std::string, MouseOnBox *> mouseBox;
  std::string currentFocus;
  bool back;
  sf::Mouse mouse;
  
  int width;
  int height;
  sf::Vector2f defaultPos;
  std::map<std::string, WriteInBox *> writeBox;
};

#endif
