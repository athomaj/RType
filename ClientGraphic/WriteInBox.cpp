//
// WriteInBox.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Fri Dec 11 17:42:41 2015 Timothy Burdairon
// Last update Fri Dec 11 17:42:42 2015 Timothy Burdairon
//


#include "WriteInBox.hh"


WriteInBox::WriteInBox(sf::Vector2f pos, int _size, int _maxSize)
{
	size = _size;
	position = pos;
	std::string res("resources/");
	res.append("imagine_font.ttf");
	writeFont.loadFromFile(res.c_str());
	writeText.setFont(writeFont);
	writeText.setCharacterSize(size);
	writeText.setPosition(position.x, position.y);
	writeText.setColor(sf::Color(96, 96, 96, 255));
	maxSize = _maxSize;
}

WriteInBox::~WriteInBox()
{

}

std::string &WriteInBox::getText()
{
	return (str);
}

void	WriteInBox::clear()
{
	str.clear();
}

void	WriteInBox::addString(const std::string &name)
{
	for (int i = 0; i < name.size(); ++i)
	{
		addCharacter(name[i]);
	}
}

void	WriteInBox::addCharacter(char c)
{
	if (str.size() < maxSize && (c >= 30 && c < 127))
		str.append(1, c);
	if (c == 8 && str.size() > 0)
		str.erase(str.size() - 1, 1);
}

sf::Text &WriteInBox::drawString()
{
	writeText.setString(str);
	return (writeText);
}
