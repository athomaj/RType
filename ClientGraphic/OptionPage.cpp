#include "OptionPage.hh"
#include "Audio.hh"

OptionPage::OptionPage(int _width, int _height, NetworkEvent &_netEvent) : netEvent(_netEvent)
{
  width = _width;
  height = _height;
  // std::cout << "ok" << std::endl;
  sf::Texture *textureBack = new sf::Texture();
  if (!textureBack->loadFromFile("resources/optionPage.png"))
    std::cerr << "connect.png is not found" << std::endl;
  tmp.setTexture(*textureBack);
  tmp.setColor(sf::Color(255, 255, 255, 230));
  defaultPos.x = 0.17 * width;
  defaultPos.y = 0.15 * height;
  tmp.setPosition(defaultPos);

  sf::Texture *textureButtonSave = new sf::Texture();
  if (!textureButtonSave->loadFromFile("resources/buttonsave.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  saveButton.setTexture(*textureButtonSave);
  savePos.x = 0.72 * width;
  savePos.y = 0.738 * height;
  saveButton.setPosition(savePos);
  saveButton.setScale(1.5f, 1.5f);
  sf::Vector2f savePos(saveButton.getPosition().x , saveButton.getPosition().y);
  sf::Vector2f saveSize(textureButtonSave->getSize().x * 1.5f,  textureButtonSave->getSize().y * 1.5f);
  mouseBox["save"] = new MouseOnBox(NULL, savePos, saveSize, "save");
  

  /* sf::Texture *textureButtonBack = new sf::Texture();
  if (!textureButtonBack->loadFromFile("back_button.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  backButton.setTexture(*textureButtonBack);
  // backPos.x = 0.21 * width;
  backPos.y = 0.75 * height;
  backButton.setPosition(backPos);
  backButton.setScale(1.5f, 1.5f);*/

  /*sf::Vector2f t(0.048 * (float)width * backButton.getScale().x, 0.024 * (float)height * backButton.getScale().y);
  std::cout  << "x:" << t.x << std::endl;
  std::cout  << "y:" << t.y << std::endl;
  mouseBox["back"] = new MouseOnBox(NULL, backPos, t, "back");*/

  sf::Texture *textureButtonBack = new sf::Texture();
  if (!textureButtonBack->loadFromFile("resources/back_button.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  backButton.setTexture(*textureButtonBack);
  backButton.setPosition(sf::Vector2f((float)width * 0.2f, (float)height/ 1.35));
  backButton.setScale(1.5f, 1.5f);

  
  sf::Vector2f backPos(backButton.getPosition().x , backButton.getPosition().y);
  sf::Vector2f backSize(textureButtonBack->getSize().x * 1.5f, textureButtonBack->getSize().y * 1.5f);
  mouseBox["back"] = new MouseOnBox(NULL, backPos, backSize, "back");
  

  back = false;
  currentFocus = "";
  // std::cout << "ok2" << std::endl;
  if (!fontOption.loadFromFile("imagine_font.ttf"))
    std::cerr << "Typo not found" << std::endl;
  textOption[0].setFont(fontOption);
  textOption[0].setColor(sf::Color::White);
  textOption[0].setString("Sound");
  textOption[0].setPosition(0.48 * width, 0.34 * height);

  textOption[1].setFont(fontOption);
  textOption[1].setColor(sf::Color(96, 96, 96,255));
  textOption[1].setString("Activate");
  textOption[1].setPosition(0.40 * width, 0.41 * height);

 sf::Vector2f t2(textOption[1].getPosition().x , textOption[1].getPosition().y);
 sf::Vector2f  sizet((float)width *0.38f, (float)height *0.026f);
 mouseBox["Activate"] = new MouseOnBox(NULL, t2, sizet, "Activate");
  
  textOption[2].setFont(fontOption);
  textOption[2].setColor(sf::Color::White);
  textOption[2].setString("Desactivate");
  textOption[2].setPosition(0.53 * width, 0.41 * height);

  t2.x = textOption[2].getPosition().x;
  t2.y = textOption[2].getPosition().y;
  mouseBox["Desactivate"] = new MouseOnBox(NULL, t2, sizet, "Desactivate");
  
  textOption[3].setFont(fontOption);
  textOption[3].setColor(sf::Color::White);
  textOption[3].setString("Size of the screen");
  textOption[3].setPosition(0.42 * width, 0.60 * height);

  textOption[4].setFont(fontOption);
  textOption[4].setColor(sf::Color(96, 96, 96, 255));
  textOption[4].setString("Full Screen");
  textOption[4].setPosition(0.40 * width, 0.67 * height);

  sizet.x = (float)width * 0.40f;
  sizet.y = (float)height * 0.026f;
  t2.x = textOption[4].getPosition().x;
  t2.y = textOption[4].getPosition().y;
  mouseBox["Full"] = new MouseOnBox(NULL, t2, sizet, "Full");
  
  textOption[5].setFont(fontOption);
  textOption[5].setColor(sf::Color::White);
  textOption[5].setString("Window");
  textOption[5].setPosition(0.57 * width, 0.67 * height);
  t2.x = textOption[5].getPosition().x;
  t2.y = textOption[5].getPosition().y;
  mouseBox["Window"] = new MouseOnBox(NULL, t2, sizet, "Window");

  textOption[6].setPosition(sf::Vector2f((float)width *0.48f , (float)height * 0.55));
  textOption[6].setFont(fontOption);
  textOption[6].setColor(sf::Color(96, 96, 96, 255));
  textOption[6].setString("<");
  //textOption[6].setCharacterSize(60);
  //textRoom[2].setScale(1.f, 1.f);
  sizet.x = (float)width *0.026f;
  sizet.y = (float)height *0.026f + 0.01f * (float)height;
  t2.x = textOption[6].getPosition().x;
  t2.y = textOption[6].getPosition().y;
  mouseBox["<"] = new MouseOnBox(NULL, t2, sizet, "<");

  textOption[7].setPosition(sf::Vector2f((float)width *0.56f , (float)height * 0.55));
  textOption[7].setFont(fontOption);
  textOption[7].setColor(sf::Color(96, 96, 96, 255));
  textOption[7].setString(">");
  //  textOption[7].setCharacterSize(60);

  sizet.x = (float)width *0.026f;
  sizet.y = (float)height *0.026f;
  t2.x = textOption[7].getPosition().x;
  t2.y =  textOption[7].getPosition().y + 0.01f * (float)height;
  // sizet.x = (float)width *0.05f;
  //sizet.y = (float)height *0.05f;
  mouseBox[">"] = new MouseOnBox(NULL, t2, sizet, ">");


  textOption[8].setPosition(sf::Vector2f((float)width *0.51f , (float)height * 0.55));
  textOption[8].setFont(fontOption);
  textOption[8].setColor(sf::Color::White);
  textOption[8].setString("15");
  // textOption[8].setCharacterSize(60);

  tmp_sound = 20;
  sound = 20;

  textOption[9].setFont(fontOption);
  textOption[9].setColor(sf::Color::White);
  textOption[9].setString("Adjust the sound");
  textOption[9].setPosition(0.42* width, 0.48 * height);
}

OptionPage::~OptionPage()
{
  
}

/*void   OptionPage::mousePositionBox(sf::RenderWindow &window, bool mouseClicked)
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
	      std::string  tmps = (*it).first;
	      currentFocus = tmps;
	    }
	}
    }
  if (currentFocus.find("back") != std::string::npos)
	  netEvent.mainMenu();
    //back = true;
  // if (currentFocus.find("save") != std::string::npos)
  // std::cout << "Save Button Working" << std::endl;
  }*/

void OptionPage::mousePositionBox(sf::RenderWindow &window, bool mouseClicked)
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
	      if (currentFocus.find(">") != std::string::npos && mouseClicked)
		{
		  sound++;
		  tmp_sound++;
		}
	      if (currentFocus.find("<") != std::string::npos && mouseClicked)
		{
		  sound--;
		  tmp_sound--;
		}
	      if ((currentFocus.find("save") != std::string::npos && mouseClicked) ||
		  (currentFocus.find("back") != std::string::npos && mouseClicked))
		{
		  Audio::coefVolume(sound);
		  netEvent.mainMenu();
		  //back =true;
		}
	      if (currentFocus.find("Activate") != std::string::npos && mouseClicked)
		{
		  sound = tmp_sound;
		  // Audio::coefVolume(sound);
		  textOption[1].setColor(sf::Color(96, 96, 96, 255));
		  textOption[2].setColor(sf::Color::White);
		}
	      if (currentFocus.find("Desactivate") != std::string::npos && mouseClicked)
		{
		  tmp_sound = sound;
		  sound = 0;
		   textOption[1].setColor(sf::Color::White);
		   textOption[2].setColor(sf::Color(96, 96, 96, 255));
		}
	      if (currentFocus.find("Full") != std::string::npos && mouseClicked)
		{
		  textOption[4].setColor(sf::Color(96, 96, 96, 255));
		  textOption[5].setColor(sf::Color::White);
		}
	      else if (currentFocus.find("Window") != std::string::npos && mouseClicked)
		{
		  textOption[4].setColor(sf::Color::White);
		  textOption[5].setColor(sf::Color(96, 96, 96, 255));
		}
	      std::stringstream sstr;
	      sstr << sound;
	      textOption[8].setString(sstr.str());
	    }
	}
    }
}


void OptionPage::restart()
{
  back = false;
  // full = false;
  currentFocus = "";
}

bool OptionPage::checkBack()
{
  return (back);
}

void    OptionPage::drawBackGround(sf::RenderWindow &window, bool mouseClick)
{
  // tmp->setTextureRect(sf::IntRect(0,0, texture4->getSize().x, texture4->getSize().y));
  // tmp->setScale((float)width / (float)(texture4->getSize().x), (float)height / (float)(texture4->getSize().y));
    window.draw(tmp);
    window.draw(saveButton);
    window.draw(backButton);
    mousePositionBox(window, mouseClick);
    for(int i =0; i < MAX_TXTS; i++)
      {
	window.draw(textOption[i]);
      }
}
