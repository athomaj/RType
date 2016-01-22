#include "SFML/Graphics.hpp"
#include <iostream>
//#include "menu.hh"
#include "../Loader.hh"
#include "menuWindow.hh"

int main()
{
  //  sf::RenderWindow window(sf::VideoMode(800, 800), "R-TYPE");

  MenuWindow win(1700, 1056, "R-TYPE");
  // Menu menu(win.window.getSize().x, win.window.getSize().y);

  win.checkEvent();
  /*while (window.isOpen())
    {
      sf::Event event;

      while (window.pollEvent(event))
	{
	  switch (event.type)
	    {
	    case sf::Event::KeyReleased:
	      switch (event.key.code)
		{
		case sf::Keyboard::Up:
		  menu.MoveUp();
		  break;
		case sf::Keyboard::Down:
		  menu.MoveDown();
		  break;
		default:
		  break;
		case sf::Keyboard::Return:
		  switch (menu.GetPressedItem())
		    {
		    case 0:
		      std::cout << "Play button has been pressed" << std::endl;
		      break;
		    case 1:
		      std::cout << "Option button has been pressed" << std::endl;
		      break;
		    case 2:
		      window.close();
		      break;
		    default:
		      break;
		    }
		  break;
		}
	      break;
	    default:
	      break;
	    case sf::Event::Closed:
	      window.close();

	      break;

	    }
	    }*/

      
  /* window.clear();
sf::Texture texture3;
      if (!texture3.loadFromFile("logo.png"))
	std::cerr << "Logo.png is not found" << std::endl;
      // Create a sprite
      sf::Sprite sprite;
      sprite.setTexture(texture3);
      sprite.setPosition(220, 60);
      // Draw it
      window.draw(sprite);
      menu.draw(window);

      window.display();
      }*/
}
