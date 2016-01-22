#include "scorePage.hh"

ScorePage::ScorePage(int _width, int _height, NetworkEvent &_netEvent) : netEvent(_netEvent)
{
  width = _width;
  height = _height;
  back = false;
  currentFocus = "";
  sf::Texture *textureScore = new sf::Texture;
  if (!textureScore->loadFromFile("resources/scorePage.png"))
    std::cerr << "scorePage.png is not found" << std::endl;
  scorePages.setTexture(*textureScore);
  scorePages.setColor(sf::Color(255, 255, 255, 200));
  defaultPos.x = 0.17 * width;
  defaultPos.y = 0.15 * height;
  scorePages.setPosition(defaultPos);

  sf::Texture *textureButtonBack = new sf::Texture();
  if (!textureButtonBack->loadFromFile("resources/back_button.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  backButton.setTexture(*textureButtonBack);
  backButton.setPosition(sf::Vector2f((float)width * 0.2f, (float)height/ 1.35));
  backButton.setScale(1.5f, 1.5f);

  sf::Vector2f backPos(backButton.getPosition().x , backButton.getPosition().y);
  sf::Vector2f backSize(textureButtonBack->getSize().x * 1.5f, textureButtonBack->getSize().y * 1.5f);
  mouseBox["back"] = new MouseOnBox(NULL, backPos, backSize, "back");

  if (!fontScore.loadFromFile("imagine_font.ttf"))
    {
      std::cerr << "Typo not found" << std::endl;
    }
  textScore[0].setFont(fontScore);
  textScore[0].setColor(sf::Color::White);
  textScore[0].setString("1 - ");
  textScore[0].setPosition(sf::Vector2f((float)width * 0.33f, (float)height * 0.36f));

   textScore[1].setFont(fontScore);
  textScore[1].setColor(sf::Color::White);
  textScore[1].setString("2 - ");
  textScore[1].setPosition(sf::Vector2f((float)width * 0.33f, (float)height * 0.43f));

   textScore[2].setFont(fontScore);
  textScore[2].setColor(sf::Color::White);
  textScore[2].setString("3 - ");
  textScore[2].setPosition(sf::Vector2f((float)width * 0.33f, (float)height * 0.50f));

  textScore[3].setFont(fontScore);
  textScore[3].setColor(sf::Color::White);
  textScore[3].setString("4 - ");
  textScore[3].setPosition(sf::Vector2f((float)width * 0.33f, (float)height * 0.57f));

   textScore[4].setFont(fontScore);
  textScore[4].setColor(sf::Color::White);
  textScore[4].setString("5 - ");
  textScore[4].setPosition(sf::Vector2f((float)width * 0.33f, (float)height * 0.64f));

   textScore[5].setFont(fontScore);
  textScore[5].setColor(sf::Color::White);
  textScore[5].setString("6 - ");
  textScore[5].setPosition(sf::Vector2f((float)width * 0.57f, (float)height * 0.36f));

   textScore[6].setFont(fontScore);
  textScore[6].setColor(sf::Color::White);
  textScore[6].setString("7 - ");
  textScore[6].setPosition(sf::Vector2f((float)width * 0.57f, (float)height * 0.43f));

   textScore[7].setFont(fontScore);
  textScore[7].setColor(sf::Color::White);
  textScore[7].setString("8 - ");
  textScore[7].setPosition(sf::Vector2f((float)width * 0.57f, (float)height * 0.50f));

  textScore[8].setFont(fontScore);
  textScore[8].setColor(sf::Color::White);
  textScore[8].setString("9 - ");
  textScore[8].setPosition(sf::Vector2f((float)width * 0.57f, (float)height * 0.57f));

   textScore[9].setFont(fontScore);
  textScore[9].setColor(sf::Color::White);
  textScore[9].setString("10 - ");
  textScore[9].setPosition(sf::Vector2f((float)width * 0.57f, (float)height * 0.64f));
  
}

ScorePage::~ScorePage()
{
  
}

void ScorePage::drawScorePage(sf::RenderWindow &window, bool mouseClicked)
{
  window.draw(scorePages);
  window.draw(backButton);
  mousePositionBox(window, mouseClicked);
  for(int i =0; i < MAX_TXTSS; i++)
    {
      window.draw(textScore[i]);
    }
}

void ScorePage::mousePositionBox(sf::RenderWindow &window, bool mouseClicked)
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

bool ScorePage::checkBack()
{
  return(back);
}

void ScorePage::restart()
{
  back = false;
  currentFocus = "";
}
