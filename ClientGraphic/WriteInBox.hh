//
// WriteInBox.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Fri Dec 11 17:43:07 2015 Timothy Burdairon
// Last update Fri Dec 11 17:43:07 2015 Timothy Burdairon
//

#ifndef WRITEINBOX_HH_
#define WRITEINBOX_HH_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <list>

class WriteInBox
{
public:
	WriteInBox(sf::Vector2f, int size, int);
	~WriteInBox();
	sf::Text &drawString();
	void	addCharacter(char c);
	void	addString(const std::string &name);
	std::string &getText();
	void	clear();





private:
	std::string 		str;
	sf::Text 			writeText;
	sf::Font			writeFont;
	sf::Vector2f		position;
	int					size;
	size_t 				maxSize;
};

#endif /*  WRITEINBOX_HH_ */
