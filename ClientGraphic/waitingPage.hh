#ifndef WAITINGPAGE_HH
# define WAITINGPAGE_HH

#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>
#include <sstream>

#include "IMenu.h"

class WaitingPage
{
public:
  WaitingPage(int, int);
  ~WaitingPage();
  void  drawBackGround(sf::RenderWindow &window);

private:
  sf::Sprite waitPage;

  int width;
  int height;
  sf::Vector2f defaultPos;
};

#endif






