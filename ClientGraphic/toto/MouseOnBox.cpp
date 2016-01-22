//
// MouseOnBox.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic/toto
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Tue Dec  8 17:53:41 2015 Timothy Burdairon
// Last update Tue Dec  8 18:41:39 2015 Timothy Burdairon
//

#include "MouseOnBox.hh"

MouseOnBox::MouseOnBox(sf::Sprite *_nextSprite, sf::Vector2<int> _pos, sf::Vector2<int> _size):
  nextSprite(_nextSprite), position(_pos), size(_size)
{
  middleX = _size.x / 2;
  middleY = _size.y / 2;
}


MouseOnBox::~MouseOnBox()
{

}

sf::Sprite *MouseOnBox::getNextSprite() const
{
  return (nextSprite);
}



bool MouseOnBox::isOnObject(sf::Vector2<int> &mousePos)
{

  if (abs(mousePos.x - (position.x + middleX)) < middleX &&
      abs(mousePos.y - (position.y + middleY)) < middleY)
    return (true);
  return (false);
}


