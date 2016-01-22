#include "menuWindow.hh"

MenuWindow::MenuWindow(int x, int y, const std::string &name)
  : width(x), height(y), windowName(name)
{
  speed = 1;
  window = new sf::RenderWindow(sf::VideoMode(width, height, 32), name.c_str(),
				sf::Style::Titlebar | sf::Style::Close);
  load = new Loader(x,y);
  currentPositionWindowSprite = 0;
  menu = new Menu(x, y);
  sizeXspriteBackground = this->load->getSequenceBackGroundSize();
  /*if (!texture.loadFromFile("fondrtype.png"))
    std::cerr << "Logo.png is not found" << std::endl;
  spriteSpaceShip.setTexture(texture4);
  spriteSpaceShip.setTextureRect(sf::IntRect(0,0, texture4.getSize().x, texture4.getSize().y));
  spriteSpaceShip.setScale((float)width / (float)(texture4.getSize().x), (float)height / (float)(texture4.getSize().y));*/
  sf::Vector2<int> pos;
  sf::Vector2<int> size;
  pos.x = /*522*/ 0.32 * (float)x;
  pos.y = /*760 */ 0.72 * (float)y;
  size.x = /*220*/  0.13 * (float)x;
  size.y = /*264*/  0.25 * (float)y;
  listMouseOnBox.push_back(new MouseOnBox(menu->getSprite("option"), pos, size));
  pos.x = /*990*/ 0.53 * (float)x;
  pos.y = /*560*/ 0.53 * (float)y;
  size.x = /*340*/ 0.25 * (float)x;
  size.y = /*140*/ 0.130 * (float)y;
  listMouseOnBox.push_back(new MouseOnBox(menu->getSprite("score"), pos, size));
  pos.x = /*500 */	0.29 * (float)x;
  pos.y = /*120 */	0.11 * (float)y;
  size.x = /*440*/ 	0.26 * (float)x;
  size.y = /*500*/ 	0.47 * (float)y;
  listMouseOnBox.push_back(new MouseOnBox(menu->getSprite("play"), pos, size));
  pos.x = /*1350*/	0.79 * (float)x;
  pos.y = /*30*/	0.03 * (float)y;
  size.x = /*350*/ 	0.2 * (float)x;
  size.y = /*600*/ 	0.57 * (float)y;
  listMouseOnBox.push_back(new MouseOnBox(menu->getSprite("exit"), pos, size));
  mouseClicked = false;
}

MenuWindow::~MenuWindow()
{
  
}

void	MenuWindow::checkMouseEvent()
{
  int	cnt = 0;

  for (std::list<MouseOnBox*>::iterator it = listMouseOnBox.begin(); it != listMouseOnBox.end(); ++it)
    {
      sf::Vector2<int> tmpV;

      tmpV.x = mouse.getPosition(*window).x;
      tmpV.y = mouse.getPosition(*window).y;
      if ((*it)->isOnObject(tmpV) == true)
      {
	//  std::cout << "Should Work" << std::endl;
	  cnt = 1;
	  menu->setSpriteSpaceShip(*((*it)->getNextSprite()));
      }
    }
  if (cnt == 0)
    menu->setSpriteSpaceShip("default");
}


void MenuWindow::setGameWidth(int x)
{
  this->width = x;
}

void MenuWindow::setGameHeight(int y)
{
  this->height = y;
}

bool MenuWindow::isOpen()

{
  if (window->isOpen())
    return (true);
  return (false);
}

bool MenuWindow::windowEventTrigger()  //std::cout << "addresse" << loadInfo->getAnimationList(_name) << std::endl;

{
  if (window->pollEvent(this->event))
    return (true);
  return (false);
}

bool MenuWindow::eventTrigger(sf::Event::EventType eventType)
{
  if (this->event.type == eventType)
    return (true);
  return (false);
}

bool MenuWindow::keyTrigger(sf::Keyboard::Key keyType)
{
  if (this->event.key.code == keyType)
    return (true);
  return (false);
}

void MenuWindow::close()
{
  window->close();
}

void MenuWindow::clear()
{
  window->clear(sf::Color(0, 0, 0));
}



void MenuWindow::checkEvent()
{
  while (isOpen() == true)
  {
	  mouseClicked = false;
    while(windowEventTrigger() == true)
      {
    /* */
    		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
    			mouseClicked = true;
	/*switch(this->event.type)
	  {
	  case sf::Event::KeyReleased:
	    switch (this->event.key.code)
	      {
	       case sf::Keyboard::Return:
		switch (menu->GetPressedItem())
		  {
		  case 0:
		    std::cout << "Play button has been pressed" << std::endl;
		    break;
		  case 1:
		    std::cout << "Option button has been pressed" << std::endl;
		    break;
		  case 2:
		    std::cout << "Score button has been pressed" << std::endl;
		    break;
		  case 3:
		    close();
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
	    close();
	    break;
	  }
      }*/
      }
    display();
  }
}

void MenuWindow::drawBack()
{
  this->currentPositionWindowSprite = (this->currentPositionWindowSprite + this->speed) %
    (this->width * this->load->getNumberOfBackGroundImages());
  for (std::map<sf::Sprite *, sf::Vector2<unsigned int> >::iterator it = this->load->getMapBackGround().begin();
       it != this->load->getMapBackGround().end(); ++it)
    {
      	  int x = (*it).second.x;
	  x = x - this->currentPositionWindowSprite;
	  if (x <= -(sizeXspriteBackground))
	    x = x + (this->width * this->load->getNumberOfBackGroundImages());
	  ((*it).first)->setPosition(x, (*it).second.y);
	  window->draw(*((*it).first));
    }
}

void MenuWindow::display()
{
  // checkEvent();
      drawBack();
      sf::Texture texture3;
      if (!texture3.loadFromFile("logo.png"))
	std::cerr << "Logo.png is not found" << std::endl;
      // Create a sprite
      sf::Sprite sprite;
      sprite.setTexture(texture3);
      sprite.setScale(sf::Vector2f(((float)width / texture3.getSize().x) * 0.25f  ,  ((float)height / texture3.getSize().y) * 0.1f  ));
      sprite.setPosition(sf::Vector2f(0.02f * (float)width, 0.33f * (float)height));
      //  sprite.setPosition(sf::Vector2f());
      // Draw it
      window->draw(sprite);
      /* sf::Texture texture4;
      if (!texture4.loadFromFile("rtupes.png"))
	std::cerr << "Logo.png is not found" << std::endl;
      // Create a sprite
      sf::Sprite sprite2;
      sprite.setTexture(texture4);
      sprite.setPosition(700, 700);
      // Draw it
      window->draw(sprite2); */
      checkMouseEvent();
      menu->draw(*window);
      window->display();
}
