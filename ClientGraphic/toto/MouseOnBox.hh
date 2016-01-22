//
// MouseOnBox.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic/toto
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Tue Dec  8 17:53:54 2015 Timothy Burdairon
// Last update Tue Dec  8 18:41:29 2015 Timothy Burdairon
//

#ifndef MOUSEONBOX_HH_
# define MOUSEONBOX_HH_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>


class MouseOnBox
{
public:
  MouseOnBox(sf::Sprite *, sf::Vector2<int>, sf::Vector2<int>);
  ~MouseOnBox();
  sf::Sprite	*getNextSprite() const;
  bool		isOnObject(sf::Vector2<int> &);
private:
  sf::Sprite		*nextSprite;
  sf::Vector2<int>	position;
  sf::Vector2<int>	size;
  int			middleX;
  int			middleY;

};


#endif /*MOUSEONBOX_HH_*/
