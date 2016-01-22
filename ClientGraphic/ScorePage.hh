#ifndef SCOREPAGE_HH
# define SCOREPAGE_HH

#include "SFML/Graphics.hpp"
#include "MouseOnBox.hh"
#include "WriteInBox.hh"

#include <iostream>
#include <string>
#include <sstream>
#include "IMenu.h"

# define MAX_TXTSS 11

#include "NetworkEvent.hh"

class ScorePage
{
public:
  ScorePage(int, int, NetworkEvent &);
  ~ScorePage();
  void  drawBackGround(sf::RenderWindow &window, bool);
  void  mousePositionBox(sf::RenderWindow &, bool);
  bool checkBack();
  void  restart();
  void addScore(const std::string nameScore);

private:
  //  int selectedItemIndex;
  sf::Font fontScore;
  sf::Text textScore[MAX_TXTSS];
  sf::Sprite saveButton;
  sf::Sprite backButton;
  sf::Sprite scorePages;
  sf::Vector2f defaultPos;
  sf::Vector2f savePos;
  sf::Vector2f backPos;

  std::map<std::string, MouseOnBox *> mouseBox;
  sf::Mouse mouse;
  int width;
  int height;
  int sound;
  std::string currentFocus;
  bool          back;
  NetworkEvent &netEvent;
  std::map<std::string, WriteInBox *> writeBox;
};


#endif
