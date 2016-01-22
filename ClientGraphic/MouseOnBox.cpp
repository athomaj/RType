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

MouseOnBox::MouseOnBox(sf::Sprite *_nextSprite, sf::Vector2f &_pos, sf::Vector2f &_size, const std::string &_name):
  nextSprite(_nextSprite), position(_pos), size(_size)
{
  middleX = _size.x / 2;
  middleY = _size.y / 2;
  name = _name;
}


std::string &MouseOnBox::getName()
{
	return (name);
}

MouseOnBox::~MouseOnBox()
{

}

sf::Sprite *MouseOnBox::getNextSprite() const
{
  return (nextSprite);
}


sf::Vector2<int> &MouseOnBox::getPosition()
{
	return (position);
}


bool MouseOnBox::isOnObject(sf::Vector2<int> &mousePos)
{

  if (abs(mousePos.x - (position.x + middleX)) < middleX &&
      abs(mousePos.y - (position.y + middleY)) < middleY)
    return (true);
  return (false);
}


