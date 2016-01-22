#include "LevelPage.hh"

LevelPage::LevelPage(int _width, int _height, NetworkEvent &_netEvent) : netEvent(_netEvent)
{
  width = _width;
  height = _height;
  sf::Texture *textureLevel = new sf::Texture();
  if (!textureLevel->loadFromFile("resources/level.png"))
    std::cerr << "level.png is not found" << std::endl;
  levelBack.setTexture(*textureLevel);
  levelBack.setColor(sf::Color(255, 255, 255, 200));
  defaultPos.x = 0.17 * width;
  defaultPos.y = 0.15 * height;
  levelBack.setPosition(defaultPos);
  
  sf::Texture *textureButtonReady = new sf::Texture();
  if (!textureButtonReady->loadFromFile("resources/ready_button.png"))
    std::cerr << "ready_button.png is not found" << std::endl;
  readyButton.setTexture(*textureButtonReady);
  readyButton.setScale(1.5f, 1.5f);
  readyPos.x = 0.68 * width;
  readyPos.y = 0.65 * height;
  readyButton.setPosition(readyPos);

  sf::Vector2f tt(textureButtonReady->getSize().x * backButton.getScale().x, textureButtonReady->getSize().y * backButton.getScale().y);
   mouseBox["ready"] = new MouseOnBox(NULL, readyPos, tt, "ready");


  sf::Texture *textureButtonBack = new sf::Texture();
  if (!textureButtonBack->loadFromFile("resources/back_button.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  backButton.setTexture(*textureButtonBack);
  backPos.x = 0.21 * width;
  backPos.y = 0.75 * height;
  backButton.setPosition(backPos);
  backButton.setScale(1.5f, 1.5f);


  sf::Vector2f t(0.048 * (float)width * backButton.getScale().x, 0.024 * (float)height * backButton.getScale().y);
  mouseBox["back"] = new MouseOnBox(NULL, backPos, t, "back");

  back = false;
  canPlay = false;
  
  if (!fontLevel.loadFromFile("imagine_font.ttf"))
    {
      std::cerr << "Typo not found" << std::endl;
    }
  textLevel[0].setFont(fontLevel);
  textLevel[0].setColor(sf::Color::White);
  textLevel[0].setString("Choose a level");
  textLevel[0].setPosition(sf::Vector2f((float)width * 0.225f, (float)height/3.5));

  textLevel[1].setPosition(sf::Vector2f((float)width *0.65f , (float)height /3.5));
  textLevel[1].setFont(fontLevel);
  textLevel[1].setColor(sf::Color::White);
  textLevel[1].setString("Players");
  
  currentMap.setFillColor(sf::Color(255,255,255,122));
  currentMap.setPosition(textLevel[0].getPosition().x + 0.007 * float(width), textLevel[0].getPosition().y + 0.05 * (float)height);
  sf::Vector2f currentMapSize(0.375f * width, 0.03f * height);
  currentMap.setSize(currentMapSize);
  mapsInDirectory();
  //addListMap("basicRoom.map");
  //addListMap("StarWarslevel.map");
//  addListPlayer("toto");
//  addListPlayer("titi");
}

LevelPage::~LevelPage()
{
  
}

void LevelPage::restart()
{
  back = false;
 currentFocus = "";
 canPlay = false;
  //roomFull = false;
}

bool LevelPage::checkPlay()
{
	return (canPlay);
}

std::string &LevelPage::getCurrentFocusMap()
{
	return (currentFocusMap);
}


void    LevelPage::mousePositionBox(sf::RenderWindow &window, bool mouseClicked)
{
  for (std::map<std::string, MouseOnBox*>::iterator it = mouseBox.begin(); it != mouseBox.end(); ++it)
    {
      sf::Vector2<int> tmpV;

      tmpV.x = mouse.getPosition(window).x;
      tmpV.y = mouse.getPosition(window).y;
      if ((*it).second->isOnObject(tmpV) == true)
      {
	  if (mouseClicked == true)
	    {
	      std::string  tmp = (*it).first;
	      currentFocus = tmp;
	    }
      }
    }
  if (currentFocus.find("back") != std::string::npos)
  {
	  netEvent.menuRoom();
  }
  if (currentFocus.find("ready") != std::string::npos)
    {
        std::cout << "playing" << std::endl;
	  netEvent.play(this->currentFocusMap);
        currentFocus.clear();
    }


  for (std::map<MouseOnBox*, WriteInBox*>::iterator it = mapList.begin(); it != mapList.end(); ++it)
		{
			sf::Vector2<int> tmpV;

			tmpV.x = mouse.getPosition(window).x;
			tmpV.y = mouse.getPosition(window).y;
			if ((*it).first->isOnObject(tmpV) == true)
			{
			    	//  menu->setSpriteSpaceShip(*((*it)->getNextSprite()));
				if (mouseClicked == true)
				{
					std::string  tmp = (*it).first->getName();
					//currentFocus = tmp;
					currentFocusMap = tmp;
					sf::Vector2f sizetmp;
					sizetmp.x =  (*it).first->getPosition().x;
					sizetmp.y =  (*it).first->getPosition().y;
					currentMap.setPosition(sizetmp);
					std::cout << tmp << std::endl;
				}
			}
		}

}

void LevelPage::addListMap(const std::string &mapName)
{
	sf::Vector2f sizeLine(0.376f * width, 0.03f * height);
	sf::Vector2f pos(textLevel[0].getPosition().x + 0.007 * float(width) , (float)mapList.size() * 0.03f * (float)height + (textLevel[0].getPosition().y  * 1.15));

	MouseOnBox *tmp =  new MouseOnBox(NULL, pos ,sizeLine, mapName);
	WriteInBox *tmpW = new  WriteInBox (pos, 20, 20);

	tmpW->addString(mapName);
	mapList[tmp] = tmpW;
	currentFocusMap = mapName;
	currentMap.setPosition(pos);
}

void LevelPage::removeListPlayer(const std::string &playerName)
{
	if (playerName != "" && writeBox.find(playerName) != writeBox.end())
	{
		writeBox.erase(writeBox.find(playerName));
	}
}


void LevelPage::setPlayerName(const std::string &_playerName)
{
	playerName = _playerName;
	addListPlayer(playerName);
}

void LevelPage::addListPlayer(const std::string &playerName)
{
	sf::Vector2f pos(textLevel[1].getPosition().x, (float)writeBox.size() * 0.03f * (float)height + (textLevel[1].getPosition().y  * 1.15));

	//MouseOnBox *tmp =  new MouseOnBox(NULL, pos ,sizeLine, roomName);
	if (playerName != "" && writeBox.find(playerName) == writeBox.end())
	{
		WriteInBox *tmpW = new  WriteInBox (pos, 20, 14);
		tmpW->addString(playerName);
		writeBox[playerName] = tmpW;
	}
}


void  		LevelPage::mapsInDirectory()
{
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("./map/")) != NULL)
	{
	  while ((ent = readdir (dir)) != NULL)
	  {
		  std::string str(ent->d_name);
		  if (str.find(".map") != std::string::npos)
			  addListMap(str);
	  }
	  closedir (dir);
	}

}

bool LevelPage::checkBack()
{
  return (back);
}

void LevelPage::drawBackGround(sf::RenderWindow &window, bool mouseClick)
{
  window.draw(levelBack);
  window.draw(readyButton);
  window.draw(backButton);
  // window.draw(okButton);
  // window.draw(joinButton);
  mousePositionBox(window, mouseClick);
  window.draw(currentMap);
  for(int i =0; i < MAX_TXT; i++)
    {
      window.draw(textLevel[i]);
    }
  for (std::map<std::string, WriteInBox *>::iterator it = writeBox.begin() ; it != writeBox.end(); ++it)
  	{
  	  window.draw((*it).second->drawString());
  	}
  for (std::map<MouseOnBox *, WriteInBox *>::iterator it = mapList.begin() ; it != mapList.end(); ++it)
     {
     	  window.draw((*it).second->drawString());
     }
}

void LevelPage::setCurrentFocusMap(std::string const& map)
{
    currentFocusMap = map;
}
