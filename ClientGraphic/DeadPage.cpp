#include "DeadPage.hh"

DeadPage::DeadPage(int _width, int _height, NetworkEvent &_netEvent) : netEvent(_netEvent)
{
  width = _width;
  height = _height;
  back = false;
  currentFocus = "";
  sf::Texture *textureDead = new sf::Texture;
  if (!textureDead->loadFromFile("resources/deadPage.png"))
    std::cerr << "scorePage.png is not found" << std::endl;
  deadPages.setTexture(*textureDead);
  deadPages.setColor(sf::Color(255, 255, 255, 200));
  defaultPos.x = 0.17 * width;
  defaultPos.y = 0.30 * height;
  deadPages.setPosition(defaultPos);

  sf::Texture *textureBack = new sf::Texture();
  if (!textureBack->loadFromFile("resources/back_button.png"))
    std::cerr << "connect.png is not found" << std::endl;
  backButton.setTexture(*textureBack);
  backButton.setColor(sf::Color(255, 255, 255, 230));
  backPosi.x = 0.17 * width;
  backPosi.y = 0.15 * height;
  backButton.setPosition(backPosi);

  sf::Vector2f backPos(backButton.getPosition().x , backButton.getPosition().y);
  sf::Vector2f backSize(textureBack->getSize().x * 1.5f, textureBack->getSize().y * 1.5f);
  mouseBox["back"] = new MouseOnBox(NULL, backPos, backSize, "back");
  
  
  if (!fontDead.loadFromFile("imagine_font.ttf"))
    {
      std::cerr << "Typo not found" << std::endl;
    }
  textDead[0].setFont(fontDead);
  textDead[0].setColor(sf::Color::White);
  textDead[0].setString("Survived Time");
  textDead[0].setPosition(sf::Vector2f((float)width * 0.33f, (float)height * 0.45f));

  textDead[1].setFont(fontDead);
  textDead[1].setColor(sf::Color::White);
  textDead[1].setString("Score");
  textDead[1].setPosition(sf::Vector2f((float)width * 0.33f, (float)height * 0.50f));

  textDead[2].setFont(fontDead);
  textDead[2].setColor(sf::Color::White);
  textDead[2].setString("Missile launched");
  textDead[2].setPosition(sf::Vector2f((float)width * 0.33f, (float)height * 0.55f));

  textDead[3].setFont(fontDead);
  textDead[3].setColor(sf::Color::White);
  textDead[3].setString("Ship killed");
  textDead[3].setPosition(sf::Vector2f((float)width * 0.33f, (float)height * 0.60f));

  addTime("2:50 min");
  addScore("150");
  addMissile("20");
  addKill("12");
}

DeadPage::~DeadPage()
{
  
}

void DeadPage::mousePositionBox(sf::RenderWindow &window, bool mouseClicked)
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
	      if ((currentFocus.find("save") != std::string::npos && mouseClicked) ||
		  (currentFocus.find("back") != std::string::npos && mouseClicked))
		{
		  netEvent.mainMenu();
		}
	    }
	}
    }
}

void DeadPage::restart()
{
  back = false;
  // full = false;
  currentFocus = "";
}

bool DeadPage::checkBack()
{
  return (back);
}

void DeadPage::drawBackGround(sf::RenderWindow & window, bool mouseClicked)
{
  window.draw(deadPages);
  window.draw(backButton);
  for (int i= 0; i < MAX_TXTE; i++)
    {
      window.draw(textDead[i]);
    }
  for (std::map<std::string, WriteInBox *>::iterator it = writeBox.begin(); it != writeBox.end(); it++)
    {
      window.draw((*it).second->drawString());
    }
  /*  for (std::map<std::string, WriteInBox *>::iterator it1 = writeBox.begin(); it1 != writeBox.end(); it1++)
    {
      window.draw((*it1).second->drawString());
      }*/
}

void DeadPage::addTime(const std::string timeAlive)
{
  sf::Vector2f pos(textDead[writeBox.size()].getPosition().x + 0.3f * (float)width, textDead[writeBox.size()].getPosition().y \
		       - 0.001f * (float)height);
      writeBox[timeAlive] = new WriteInBox(pos, 30, 11);
      writeBox[timeAlive]->addString(timeAlive);
}

void DeadPage::addScore(const std::string lastScore)
{
  sf::Vector2f pos(textDead[writeBox.size()].getPosition().x + 0.3f * (float)width, textDead[writeBox.size()].getPosition().y \
		   - 0.001f * (float)height);
  writeBox[lastScore] = new WriteInBox(pos, 30, 11);
  writeBox[lastScore]->addString(lastScore);
  
}

void DeadPage::addMissile(const std::string missile)
{
  sf::Vector2f pos(textDead[writeBox.size()].getPosition().x + 0.3f * (float)width, textDead[writeBox.size()].getPosition().y \
		   - 0.001f * (float)height);
  writeBox[missile] = new WriteInBox(pos, 30, 11);
  writeBox[missile]->addString(missile);
  
}

void DeadPage::addKill(const std::string kill)
{
  sf::Vector2f pos(textDead[writeBox.size()].getPosition().x + 0.3f * (float)width, textDead[writeBox.size()].getPosition().y \
		   - 0.001f * (float)height);
  writeBox[kill] = new WriteInBox(pos, 30, 11);
  writeBox[kill]->addString(kill);
  
}
