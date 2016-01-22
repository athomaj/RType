#ifndef _MENUWINDOW_HH_
# define _MENUWINDOW_HH_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../Loader.hh"
#include "menu.hh"
#include "MouseOnBox.hh"

class MenuWindow
{
public:
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
private:
  bool	mouseClicked;
  sf::Mouse	mouse;
  int width;
  int height;
  sf::RenderWindow *window;
  Loader                *load;
  Menu			*menu;
  sf::Event event;
  int           currentPositionWindowSprite;
  int           sizeXspriteBackground;
  int           speed;
  std::string windowName;
  std::list<MouseOnBox*> listMouseOnBox;
};

#endif
