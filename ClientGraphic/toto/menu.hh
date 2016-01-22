#include "SFML/Graphics.hpp"



#include <iostream>
#include <string>
#include <map>
# define MAX_NB_ITEMS 4
class Menu
{
public :
  Menu(int width, int height);
  ~Menu();

  void draw(sf::RenderWindow &window);
  void MoveUp();
  void MoveDown();
  int GetPressedItem() { return selectedItemIndex; }
  bool setSpriteSpaceShip(sf::Sprite &tmp);
  bool setSpriteSpaceShip(const std::string &tmp);

  sf::Sprite *getSprite(const std::string &name);
  void	loadSpritesShip(const std::string &fileName, const std::string &name);




private:
  int selectedItemIndex;
  sf::Font font;
  sf::Text text[MAX_NB_ITEMS];
  sf::Sprite spritePlay;
  sf::Sprite spriteOption;
  sf::Sprite spriteExit;
  sf::Sprite spriteSpaceShip;

  std::map<std::string, sf::Sprite*> mapSprite;
  int	width;
  int	height;
};
