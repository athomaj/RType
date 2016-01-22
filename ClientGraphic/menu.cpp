#include "menu.hh"

Menu::Menu(int _width, int _height)
{



   sf::Texture *texture2  = new sf::Texture;
  if (!texture2->loadFromFile("resources/selectOption.png"))
  std::cerr << "Image not found" << std::endl;
  this->spriteOption.setTexture(*texture2);
  width = _width;
  height = _height;
  if (!font.loadFromFile("imagine_font.ttf"))
    {
      std::cerr << "Typo not load" << std::endl;
    }

  loadSpritesShip("resources/back.png", "default");
  setSpriteSpaceShip("default");
  loadSpritesShip("resources/back_option.png", "option");
  loadSpritesShip("resources/back_scores.png", "score");
  loadSpritesShip("resources/backPlay.png", "play");
  loadSpritesShip("resources/backExit.png", "exit");

  spritePlay.setPosition(width/4.2,height/4.5);
  spriteExit.setPosition(width/3.3, height/1.37);
  spriteOption.setPosition(width/3.6, height/2.16);

  float b = (float)width * (float)height;
  float i = 0.00005f;
  double d = b / 100000;
  d = d * (i/27);
  float c = b * (i - d);

  text[0].setFont(font);
  text[0].setString("Options  >");
  text[0].setCharacterSize(c);
  text[0].setPosition(sf::Vector2f((float)width * 0.2f , (float)height * 0.83f));

  text[1].setFont(font);
  text[1].setColor(sf::Color::White);
  text[1].setString("Scores");
  text[1].setCharacterSize(c);
  text[1].setPosition(sf::Vector2f((float)width * 0.65f, (float)height * 0.45f));
  
  text[2].setFont(font);
  text[2].setColor(sf::Color::White);
  text[2].setString("Play");
  text[2].setCharacterSize(c);
  text[2].setPosition(sf::Vector2f((float)width * 0.4f, (float)height * 0.33f));

  text[3].setFont(font);
  text[3].setColor(sf::Color::White);
  text[3].setString("Exit");
  text[3].setCharacterSize(c);
  text[3].setPosition(sf::Vector2f((float)width * 0.9f, (float)height * 0.33f));

  text[4].setFont(font);
  text[4].setColor(sf::Color::White);
  text[4].setString(">");
  text[4].setCharacterSize(c);
  text[4].setPosition(sf::Vector2f((float)width * 0.70f, (float)height * 0.49f));
  text[4].setRotation(70);
  
  selectedItemIndex = 0;  
}

Menu::~Menu()
{

}

void		Menu::loadSpritesShip(const std::string &fileName, const std::string &name)
{
	sf::Texture *texture4 = new sf::Texture;
	sf::Sprite  *tmp = new sf::Sprite;
	if (!texture4->loadFromFile(fileName.c_str()))
		std::cerr << "Logo.png is not found" << std::endl;
	tmp->setTexture(*texture4);
	tmp->setTextureRect(sf::IntRect(0,0, texture4->getSize().x, texture4->getSize().y));
	tmp->setScale((float)width / (float)(texture4->getSize().x), (float)height / (float)(texture4->getSize().y));
	mapSprite[name] = tmp;
}

sf::Sprite *Menu::getSprite(const std::string &name)
{
  return (mapSprite[name]);
}

bool Menu::setSpriteSpaceShip(sf::Sprite &tmp)
{
  spriteSpaceShip = tmp;
  return (true);
}

bool Menu::setSpriteSpaceShip(const std::string &tmp)
{
  spriteSpaceShip = *(mapSprite[tmp]);
  return (true);
}


void Menu::drawBackGround(sf::RenderWindow &window)
{
  window.draw(spriteSpaceShip);
  // window.draw(sprite2);
  for (int i = 0; i < MAX_NB_ITEMS; i++)
    {
      window.draw(text[i]);
    }
}

void Menu::MoveUp()
{
 /* if (selectedItemIndex - 1 >= 0)
    {
      text[selectedItemIndex].setColor(sf::Color::White);
      selectedItemIndex--;
      text[selectedItemIndex].setColor(sf::Color::Red);
    }*/
}

void Menu::MoveDown()
{
 /* if (selectedItemIndex + 1 < MAX_NB_ITEMS)
    {
      text[selectedItemIndex].setColor(sf::Color::White);
      selectedItemIndex++;
      text[selectedItemIndex].setColor(sf::Color::Red);
    }*/
}
