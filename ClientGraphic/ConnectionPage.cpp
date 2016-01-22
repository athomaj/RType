#include "ConnectionPage.hh"

ConnectionPage::ConnectionPage(int _width, int _height, NetworkEvent &_netEvent) : netEvent(_netEvent)
{
  width = _width;
  height = _height;

  //netEvent = _netEvent;
  sf::Texture *textureBack = new sf::Texture();
  if (!textureBack->loadFromFile("resources/connection.png"))
    std::cerr << "connect.png is not found" << std::endl;
  tmp.setTexture(*textureBack);
  tmp.setColor(sf::Color(255, 255, 255, 230));
  defaultPos.x = 0.17 * width;
  defaultPos.y = 0.15 * height;
  tmp.setPosition(defaultPos);
  //std::cout << 0.001 * (float)width << std::endl;
  sf::Texture *textureButtonConnect = new sf::Texture();
  if (!textureButtonConnect->loadFromFile("resources/connect_button.png"))
    std::cerr << "connect_button.png is not found" << std::endl;
  connectButton.setTexture(*textureButtonConnect);
  connectPos.x = 0.45 * width;
  connectPos.y = 0.645 * height;
  connectButton.setPosition(connectPos);
  connectButton.setScale(1.5f, 1.5f);
  sf::Vector2f tt(0.094 * (float)width * BackButton.getScale().x, 0.048 * (float)height * BackButton.getScale().y);
  mouseBox["connect"] = new MouseOnBox(NULL, connectPos, tt, "back");


  sf::Texture *textureButtonBack = new sf::Texture();
  if (!textureButtonBack->loadFromFile("resources/back_button.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  BackButton.setTexture(*textureButtonBack);
  backPos.x = 0.21 * width;
  backPos.y = 0.75 * height;
  BackButton.setPosition(backPos);
  BackButton.setScale(1.5f, 1.5f);

  sf::Vector2f t(0.048 * (float)width * BackButton.getScale().x, 0.024 * (float)height * BackButton.getScale().y);
  std::cout  << "x:" << t.x << std::endl;
  std::cout  << "y:" << t.y << std::endl;
  mouseBox["back"] = new MouseOnBox(NULL, backPos, t, "back");

  back = false;
  connect = false;


  if (!fontConnect.loadFromFile("imagine_font.ttf"))
      std::cerr << "Typo not found" << std::endl;
  textConnect[0].setFont(fontConnect);
  textConnect[0].setColor(sf::Color::White);
  textConnect[0].setString("Name");
  textConnect[0].setPosition(0.45 * width, 0.36 * height);

  textConnect[1].setFont(fontConnect);
  textConnect[1].setColor(sf::Color::White);
  textConnect[1].setString("IP Address");
  textConnect[1].setPosition(0.45 * width, 0.49 * height);

  rectIP.setFillColor(sf::Color(255,255,255,122));
  writeIPPos.x = 0.2 * width;
  writeIPPos.y = 0.05 * height;
  this->rectIP.setSize(writeIPPos);
  this->rectIP.setPosition(0.45 * width, 0.55 * height);

  //sf::Vector2f pname(0.45 * width, 0.55 * height);
  sf::Vector2f rectPos = rectIP.getPosition();
  mouseBox["ip"] = new MouseOnBox(NULL, rectPos, writeIPPos, "ip");
  writeBox["ip"] = new WriteInBox(rectPos, 40, 15);

  rectName.setFillColor(sf::Color(255,255,255,122));
  writeNamePos.x = 0.2 * width;
  writeNamePos.y = 0.05 * height;
  this->rectName.setSize(writeNamePos);
  this->rectName.setPosition(0.45 * width, 0.42 * height);
 // pname.x = 0.45 * width;
  //pname.y =	0.42 * height;
  rectPos = rectName.getPosition();
  mouseBox["name"] = new MouseOnBox(NULL, rectPos, writeNamePos, "name");
  writeBox["name"] = new WriteInBox(rectPos, 40, 10);

  currentFocus = "name";
}

ConnectionPage::~ConnectionPage()
{
  
}

std::string &ConnectionPage::getName()
{
	return (writeBox["name"]->getText());
}

std::string &ConnectionPage::getIP()
{
    return (writeBox["ip"]->getText());
}

void	ConnectionPage::mousePositionBox(sf::RenderWindow &window, bool mouseClicked)
{
	  for (std::map<std::string, MouseOnBox*>::iterator it = mouseBox.begin(); it != mouseBox.end(); ++it)
	    {
	      sf::Vector2<int> tmpV;

	      tmpV.x = mouse.getPosition(window).x;
	      tmpV.y = mouse.getPosition(window).y;
	      if ((*it).second->isOnObject(tmpV) == true)
	      {
	    	//  menu->setSpriteSpaceShip(*((*it)->getNextSprite()));
	    	  if (mouseClicked == true)
	    	  {
	    		  std::string  tmp = (*it).first;
	    		  currentFocus = tmp;
	    	 }
	      }
	    }
 	  if (currentFocus.find("name") != std::string::npos)
	    {
 		  rectName.setFillColor(sf::Color::White);
 		  rectIP.setFillColor(sf::Color(255,255,255,122));
	    }
 	  else if (currentFocus.find("ip") != std::string::npos)
 	  {
 		  rectName.setFillColor(sf::Color(255,255,255,122));
 		  rectIP.setFillColor(sf::Color::White);
 	  }

 	 if (currentFocus.find("back") != std::string::npos)
 	 {
 		 netEvent.mainMenu();
 		 back = true;
 	 }
 	 if (currentFocus.find("connect") != std::string::npos)
 	 {
 		 netEvent.connection(writeBox["ip"]->getText(), writeBox["name"]->getText());
 		// connect = true;

 		 /* While server not working */
 		// netEvent.menuRoom();
 		 netEvent.setHostName(writeBox["name"]->getText());
         currentFocus.clear();
 	 }
}

void ConnectionPage::restart()
{
	back = false;
	currentFocus = "name";
	connect = false;
}

void	ConnectionPage::writeCharacter(char c)
{
	if (currentFocus.size() > 1)
		writeBox[currentFocus]->addCharacter(c);
}

bool ConnectionPage::checkBack()
{
	return (back);
}

bool ConnectionPage::checkConnect()
{
	return (connect);
}

void	ConnectionPage::drawBackGround(sf::RenderWindow &window, bool mouseClick)
{
   // tmp->setTextureRect(sf::IntRect(0,0, texture4->getSize().x, texture4->getSize().y));
  // tmp->setScale((float)width / (float)(texture4->getSize().x), (float)height / (float)(texture4->getSize().y));
  window.draw(tmp);
  window.draw(connectButton);
  window.draw(BackButton);
  for(int i =0; i < MAX_TXT; i++)
    {
      window.draw(textConnect[i]);
    }
  window.draw(rectIP);
  window.draw(rectName);
  mousePositionBox(window, mouseClick);
  for (std::map<std::string, WriteInBox *>::iterator it = writeBox.begin() ; it != writeBox.end(); ++it)
	{
	  window.draw((*it).second->drawString());
	}
}
