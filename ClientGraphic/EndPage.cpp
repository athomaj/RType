#include "EndPage.hh"

EndPage::EndPage(int _width, int _height, NetworkEvent &_netEvent) : netEvent(_netEvent)
{
  width = _width;
  height = _height;
  back = false;
  currentFocus = "";
  sf::Texture *textureEnd = new sf::Texture;
  if (!textureEnd->loadFromFile("resources/end.png"))
    std::cerr << "end.png is not found" << std::endl;
  endPage.setTexture(*textureEnd);
  endPage.setColor(sf::Color(255, 255, 255, 200));
  defaultPos.x = 0.17 * width;
  defaultPos.y = 0.15 * height;
  endPage.setPosition(defaultPos);

  sf::Texture *textureButtonBack = new sf::Texture();
  if (!textureButtonBack->loadFromFile("resources/back_button.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  backButton.setTexture(*textureButtonBack);
  backButton.setPosition(sf::Vector2f((float)width * 0.2f, (float)height/ 1.35));
  backButton.setScale(1.5f, 1.5f);
  sf::Vector2f backPos(backButton.getPosition().x , backButton.getPosition().y);
  sf::Vector2f backSize(textureButtonBack->getSize().x * 1.5f, textureButtonBack->getSize().y * 1.5f);
  mouseBox["back"] = new MouseOnBox(NULL, backPos, backSize, "back");

  if (!fontEnd.loadFromFile("imagine_font.ttf"))
    {
      std::cerr << "Typo not found" << std::endl;
    }
  
textName[0].setFont(fontEnd);
  textName[0].setColor(sf::Color::White);
  textName[0].setString("Scores");
  textName[0].setPosition(sf::Vector2f((float)width * 0.45f, (float)height * 0.36f));

  textEnd[0].setFont(fontEnd);
  textEnd[0].setColor(sf::Color::White);
  textEnd[0].setString("1 -");
  textEnd[0].setPosition(sf::Vector2f((float)width * 0.42f, (float)height * 0.43f));

  textEnd[1].setFont(fontEnd);  
  textEnd[1].setColor(sf::Color::White);
  textEnd[1].setString("2 -");
  textEnd[1].setPosition(sf::Vector2f((float)width * 0.42f, (float)height * 0.50f));

  textEnd[2].setFont(fontEnd);
  textEnd[2].setColor(sf::Color::White);
  textEnd[2].setString("3 -");
  textEnd[2].setPosition(sf::Vector2f((float)width * 0.42f, (float)height * 0.57f));

  textEnd[3].setFont(fontEnd);
  textEnd[3].setColor(sf::Color::White);
  textEnd[3].setString("4 -");
  textEnd[3].setPosition(sf::Vector2f((float)width * 0.42f, (float)height * 0.64f));
  
//  addScore("Juju - 0");
//  addScore("Sophie - 100");
//  addScore("Tim - 50");
//  addScore("Marvin - 20");
}

EndPage::~EndPage()
{
  
}

void	EndPage::drawBackGround(sf::RenderWindow &window, bool mouseClicked)
{
  window.draw(endPage);
  window.draw(backButton);
  mousePositionBox(window, mouseClicked);
  window.draw(textName[0]);
    for(int i =0; i < MAX_TXTEND; i++)
  {
      window.draw(textEnd[i]);
     }
  for (std::map<std::string, WriteInBox *>::iterator it = writeBox.begin() ; it != writeBox.end(); ++it)
    {
      window.draw((*it).second->drawString());
    }
  
}

void	EndPage::mousePositionBox(sf::RenderWindow &window, bool mouseClicked)
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
	      if (currentFocus.find("back") != std::string::npos && mouseClicked)
		{
		  netEvent.menuRoom();
		}
	    }
	}
    }  
}

bool	EndPage::checkBack()
{
  return(back);
}

void	EndPage::restart()
{
  back = false;
  currentFocus = "";
  for (std::map<std::string,  WriteInBox*>::iterator it = writeBox.begin(); it != writeBox.end(); ++it)
    {
      (*it).second->clear();
    }
}

void	EndPage::addScore(const std::string &scores)
{
  if (writeBox.size() < 4)
    {
      sf::Vector2f pos(textEnd[writeBox.size()].getPosition().x + 0.05f * (float)width, textEnd[writeBox.size()].getPosition().y - 0.003f * (float)height);
        std::cout << "height "<< writeBox.size()<< std::endl;
      writeBox[scores] = new WriteInBox(pos, 30, 11);
      writeBox[scores]->addString(scores);
    }
}
