#ifndef OPTIONPAGE_HH
# define OPTIONPAGE_HH

#include "SFML/Graphics.hpp"
#include "MouseOnBox.hh"
#include "NetworkEvent.hh"

#include <iostream>
#include <string>
#include <sstream>
#include "IMenu.h"

# define MAX_TXTS 10

class OptionPage
{
public:
  OptionPage(int, int, NetworkEvent &);
  ~OptionPage();
  void  drawBackGround(sf::RenderWindow &window, bool);
  void  mousePositionBox(sf::RenderWindow &, bool);
  bool checkBack();
  void  restart();



private:
  //  int selectedItemIndex;
  sf::Font fontOption;
  sf::Text textOption[MAX_TXTS];
  sf::Sprite saveButton;
  sf::Sprite backButton;
  sf::Sprite tmp;
  sf::Vector2f defaultPos;
  sf::Vector2f savePos;
  sf::Vector2f backPos;
  NetworkEvent& netEvent;

  std::map<std::string, MouseOnBox *> mouseBox;
  sf::Mouse mouse;
  int width;
  int height;
  int sound;
  int tmp_sound;
  std::string currentFocus;
  //  bool		full;
  bool          back;
};


#endif
