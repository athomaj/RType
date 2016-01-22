#ifndef IMENU_H
# define IMENU_H

class IMenu
{
  virtual ~IMenu() {};
  virtual void drawBackGround(sf::RenderWindow &, bool);
  virtual void drawBackground(sf::RenderWindow &);
};

#endif
