#include "menu.hh"

Menu::Menu(int _width, int _height)
{


  // Load the sprite image from a file
  //  sf::Image selection;
  // if (!selection.LoadFromFile("select.tga"))
  // std::cerr << "image not found" << std::endl;

  // Create the sprite
  // sf::Sprite Sprite(selection);

  // Change its properties
  // Sprite.SetColor(sf::Color(0, 255, 255, 128));
  // Sprite.SetPosition(200.f, 100.f);
  // Sprite.SetScale(2.f, 2.f);

  sf::Texture *texture = new sf::Texture;
  if (!texture->loadFromFile("select.png"))
  std::cerr << "Image not found" << std::endl;
  this->spritePlay.setTexture(*texture);
  // spritePlay.setPosition(145, 130);
  this->spriteExit.setTexture(*texture);
  // spriteExit.setPosition(140, 430);
  sf::Texture *texture2  = new sf::Texture;
  if (!texture2->loadFromFile("selectOption.png"))
  std::cerr << "Image not found" << std::endl;
  this->spriteOption.setTexture(*texture2);
  //  spriteOption.setPosition(120, 270);
  width = _width;
  height = _height;
  if (!font.loadFromFile("airstrike.ttf"))
    {
      std::cerr << "Typo not load" << std::endl;
    }

  loadSpritesShip("fondrtype.png", "default");
  /*sf::Texture *texture4 = new sf::Texture;
  sf::Sprite  *tmp = new sf::Sprite;
  if (!texture4->loadFromFile("fondrtype.png"))
    std::cerr << "Logo.png is not found" << std::endl;
  tmp->setTexture(*texture4);
  tmp->setTextureRect(sf::IntRect(0,0, texture4->getSize().x, texture4->getSize().y));
  tmp->setScale((float)width / (float)(texture4->getSize().x), (float)height / (float)(texture4->getSize().y));
  mapSprite["default"] = tmp;
  std::string tmp2("default");*/
  setSpriteSpaceShip("default");
  loadSpritesShip("fondrtypeselect1.png", "option");
  loadSpritesShip("fondrtypeselect2.png", "score");
  loadSpritesShip("fondrtypeselect3.png", "play");
  loadSpritesShip("fondrtype4.png", "exit");

 /* texture = new sf::Texture;
  tmp = new sf::Sprite;
  if (!texture->loadFromFile("fondrtypeselect1.png"))
    std::cerr << "Logo.png is not found" << std::endl;
  tmp->setTexture(*texture);
  tmp->setTextureRect(sf::IntRect(0,0, texture->getSize().x, texture->getSize().y));
  tmp->setScale((float)width / (float)(texture->getSize().x), (float)height / (float)(texture->getSize().y));
  mapSprite["test"] = tmp;*/


  spritePlay.setPosition(width/4.2,height/4.5);
  spriteExit.setPosition(width/3.3, height/1.37);
  spriteOption.setPosition(width/3.6, height/2.16);
  //  float i;
  //i= ((float)width / (float)height * 30) / 1.61;
  float b = (float)width * (float)height;
  float i = 0.00005f;
  //  float w = -1;
  //while (b/100000)
  double d = b / 100000;
  //if (b > )
  d = d * (i/27);
  std::cout << d << std::endl;
  float c = b * (i - d);
  //float d = c / 1.5;
  std::cout << width << std::endl;
  std::cout << height * width<< std::endl;
  std::cout << b << std::endl;
  std::cout <<  "c" << c << std::endl;
  //  std::cout << d << std::endl;
  
  //std::cout << i << std::endl;
  text[0].setFont(font);
  //text[0].setColor(sf::Color::Red);
  text[0].setString("Options  >");
  text[0].setCharacterSize(c);
  std::cout << width << std::endl;
  std::cout << height << std::endl;
  text[0].setPosition(sf::Vector2f((float)width * 0.2f , (float)height * 0.83f));
  // text[0].setPosition(width/2, height/4);

  text[1].setFont(font);
  text[1].setColor(sf::Color::White);
  text[1].setString("<  Scores");
  text[1].setCharacterSize(c);
  text[1].setPosition(sf::Vector2f((float)width * 0.8f, (float)height * 0.55f));
  // text[1].setPosition(width/2, height/3);
  
  text[2].setFont(font);
  text[2].setColor(sf::Color::White);
  text[2].setString("Play");
  text[2].setCharacterSize(c);
  text[2].setPosition(sf::Vector2f((float)width * 0.4f, (float)height * 0.33f));
  //  text[2].setPosition(width/2, height/2);

    text[3].setFont(font);
    text[3].setColor(sf::Color::White);
    text[3].setString("Exit");
      text[3].setCharacterSize(c);
      text[3].setPosition(sf::Vector2f((float)width * 0.9f, (float)height * 0.33f));
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
	//setSpriteSpaceShip(name);

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


void Menu::draw(sf::RenderWindow &window)
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
