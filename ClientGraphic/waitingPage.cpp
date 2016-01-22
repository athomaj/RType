#include "waitingPage.hh"

WaitingPage::WaitingPage(int _width, int _height)
{
  width = _width;
  height = _height;
  sf::Texture *textureWait = new sf::Texture;
  if (!textureWait->loadFromFile("resources/waiting.png"))
    std::cerr << "waiting.png is not found" << std::endl;
  waitPage.setTexture(*textureWait);
  waitPage.setColor(sf::Color(255, 255, 255, 200));
  defaultPos.x = 0.17 * width;
  defaultPos.y = 0.30 * height;
  waitPage.setPosition(defaultPos);
}

WaitingPage::~WaitingPage()
{

}

void WaitingPage::drawBackGround(sf::RenderWindow &window)
{
  window.draw(waitPage);
}
