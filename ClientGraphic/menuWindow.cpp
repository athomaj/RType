
#include "menuWindow.hh"
#ifdef WIN32
#include "WindowsWindow.hh"
#else
#include "LinuxWindow.hh"
#endif

MenuWindow::MenuWindow(int x, int y, const std::string &name)
  : width(x), height(y), windowName(name), _mutex(new Mutex()), _connected(false), _actionManager(*this), _playerId(-1)
{
    _mutex->init();
  speed = 1;
  c = 0;
 // acessRoom = false;
  play = false;
  exit = false;
  currentPage = MenuWindow::NONE;
#ifdef WIN32
	windowGame = new WindowsWindow(x, y, "R-Type", "basic.map");
#else
  windowGame = new LinuxWindow(x, y, "R-Type", "basic.map");
#endif
  window =  windowGame->getWindow();
  load = new Loader(x,y);
//<<<<<<< HEAD
//  game = new GameEngine(linuxWindow, "", 0, -1);
//=======
  game = new GameEngine(windowGame, "", 0, -1);
//>>>>>>> 8a34be98f8c90bccc1a10cb2eae51cac9b020045
  game->setDefaultSettings();
  currentPositionWindowSprite = 0;
  menu = new Menu(x, y);
  netEvent = new NetworkEvent(this);
  scorePage = new ScorePage(x, y, *netEvent);
  conectPage = new ConnectionPage(x, y, *netEvent);
  room = new RoomPage(x, y, *netEvent);
  level = new LevelPage(x, y, *netEvent);
  optionPage = new OptionPage(x, y, *netEvent);
  deadPage = new DeadPage(x, y, *netEvent);
  endPage = new EndPage(x, y, *netEvent);
  waitPage = new WaitingPage(x, y);
  std::cout << "aze" << std::endl;
  sizeXspriteBackground = this->load->getSequenceBackGroundSize();
  sf::Vector2f pos;
  sf::Vector2f size;
  pos.x = /*522*/ 0.32 * (float)x;
  pos.y = /*760 */ 0.72 * (float)y;
  size.x = /*220*/  0.13 * (float)x;
  size.y = /*264*/  0.25 * (float)y;
  listMouseOnBox.push_back(new MouseOnBox(menu->getSprite("option"), pos, size, "option"));
  pos.x = /*990*/ 0.53 * (float)x;
  pos.y = /*560*/ 0.53 * (float)y;
  size.x = /*340*/ 0.25 * (float)x;
  size.y = /*140*/ 0.130 * (float)y;
  listMouseOnBox.push_back(new MouseOnBox(menu->getSprite("score"), pos, size, "score"));
  pos.x = /*500 */	0.29 * (float)x;
  pos.y = /*120 */	0.11 * (float)y;
  size.x = /*440*/ 	0.26 * (float)x;
  size.y = /*500*/ 	0.47 * (float)y;
  listMouseOnBox.push_back(new MouseOnBox(menu->getSprite("play"), pos, size, "play"));
  pos.x = /*1350*/	0.79 * (float)x;
  pos.y = /*30*/	0.03 * (float)y;
  size.x = /*350*/ 	0.2 * (float)x;
  size.y = /*600*/ 	0.57 * (float)y;
  listMouseOnBox.push_back(new MouseOnBox(menu->getSprite("exit"), pos, size, "exit"));
  mouseClicked = false;
  Audio::coefVolume(15);

      if (!textureLogo.loadFromFile("resources/logo.png"))
	{
	  std::cerr << "Logo.png is not found" << std::endl;
	  std::cout << "je ne trouve pas l'image" << std::endl;
	}
      //      sf::Sprite sprite;
      sprite.setTexture(textureLogo);
      sprite.setScale(sf::Vector2f(((float)width / textureLogo.getSize().x) * 0.25f  ,  ((float)height / textureLogo.getSize().y) * 0.1f  ));
      sprite.setPosition(sf::Vector2f(0.02f * (float)width, 0.33f * (float)height));
      std::cout << "end construct" << std::endl;
      _tcpClient = NULL;
}

MenuWindow::~MenuWindow()
{
  
}

IWindow*    MenuWindow::getWindowGame()
{
    return windowGame;
}

NetworkEvent* MenuWindow::getNetEvent()
{
    return (netEvent);
}

IMutex* MenuWindow::getMutex()
{
    return _mutex;
}

void MenuWindow::setConnected(const bool connected)
{
    _connected = connected;
}

void	MenuWindow::checkMouseEvent()
{
  int	cnt = 0;

  if (currentPage == MenuWindow::NONE)
  for (std::list<MouseOnBox*>::iterator it = listMouseOnBox.begin(); it != listMouseOnBox.end(); ++it)
    {
      sf::Vector2<int> tmpV;

      tmpV.x = mouse.getPosition(*window).x;
      tmpV.y = mouse.getPosition(*window).y;
      if ((*it)->isOnObject(tmpV) == true)
      {
    	  cnt = 1;
    	  menu->setSpriteSpaceShip(*((*it)->getNextSprite()));
    	  if (this->mouseClicked == true && (*it)->getName().find("play") != std::string::npos)
    	  {
    		  restartMenuPages();
    		  currentPage = MenuWindow::CONNECTION;
    	  }
    	  if (this->mouseClicked == true && (*it)->getName().find("exit") != std::string::npos)
    	  {
    		  exit = true;
    		  window->close();
    		  return ;
    	  }
	  if (this->mouseClicked == true && (*it)->getName().find("score") != std::string::npos)
	    {
	      	  restartMenuPages();
    		  currentPage = MenuWindow::SCORE;
    	
	    }
	  if (this->mouseClicked == true && (*it)->getName().find("option") != std::string::npos)
	    {
		  restartMenuPages();
		  currentPage = MenuWindow::OPTION;
	    }
      }
    }
  if (cnt == 0)
    menu->setSpriteSpaceShip("default");
}


void MenuWindow::setGameWidth(int x)
{
  this->width = x;
}

void MenuWindow::setGameHeight(int y)
{
  this->height = y;
}

bool MenuWindow::isOpen()

{
  if (window->isOpen())
    return (true);
  return (false);
}

bool MenuWindow::windowEventTrigger()
{
  if (window->pollEvent(this->event))
    return (true);
  return (false);
}


RoomPage& MenuWindow::getRoom()
{
    return *room;
}

bool MenuWindow::eventTrigger(sf::Event::EventType eventType)
{
  if (this->event.type == eventType)
    return (true);
  return (false);
}

bool MenuWindow::keyTrigger(sf::Keyboard::Key keyType)
{
  if (this->event.key.code == keyType)
    return (true);
  return (false);
}

void MenuWindow::close()
{
  window->close();
}

void MenuWindow::clear()
{
  window->clear(sf::Color(0, 0, 0));
}

void MenuWindow::restartMenuPages()
{
	conectPage->restart();
	room->restart();
	level->restart();
	optionPage->restart();
}

bool MenuWindow::canPlay() const
{
    bool connected;
    _mutex->lock();
    connected = _connected;
    _mutex->unlock();
    return (connected);
}

void MenuWindow::checkEvent()
{
	while (exit == false)
	{
		while (isOpen() == true)
		{
			mouseClicked = false;
			while(windowEventTrigger() == true)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
					mouseClicked = true;
				if (event.type == sf::Event::TextEntered)
				{
				    if (event.text.unicode < 128)
				        c =  static_cast<char>(event.text.unicode);
				}
			}
            
			display();
			_actionManager.checkAction(_tcpClient);
			if (play == true)
				break;
            usleep(10000);
		}
		if (play == true)
		{
			game = new GameEngine(windowGame, netEvent->getIp(), _port, _playerId);
			game->setDefaultSettings();
			game->playGame();
			play = false;
			restartMenuPages();
//            currentPage = MenuWindow::DEAD;
            netEvent->endGame();
		}

	}
}

void MenuWindow::drawBack()
{
  this->currentPositionWindowSprite = (this->currentPositionWindowSprite + this->speed) %
    (this->width * this->load->getNumberOfBackGroundImages());
  for (std::map<sf::Sprite *, sf::Vector2<unsigned int> >::iterator it = this->load->getMapBackGround().begin();
       it != this->load->getMapBackGround().end(); ++it)
    {
      	  int x = (*it).second.x;
	  x = x - this->currentPositionWindowSprite;
	  if (x <= -(sizeXspriteBackground))
	    x = x + (this->width * this->load->getNumberOfBackGroundImages());
	  ((*it).first)->setPosition(x, (*it).second.y);
	  window->draw(*((*it).first));
    }
}

void MenuWindow::display()
{
      drawBack();
      window->draw(sprite);
      checkMouseEvent();
      menu->drawBackGround(*window);

      if (currentPage == MenuWindow::LEVEL)
    	 level->drawBackGround(*window, mouseClicked);
      if (currentPage == MenuWindow::OPTION)
	optionPage->drawBackGround(*window, mouseClicked);
      if (currentPage == MenuWindow::WAIT)
	waitPage->drawBackGround(*window);
      if (currentPage == MenuWindow::SCORE)
	scorePage->drawBackGround(*window, mouseClicked);
      if (currentPage == MenuWindow::CONNECTION)
    	  conectPage->drawBackGround(*window, mouseClicked);
      if (c != 0 && currentPage == MenuWindow::CONNECTION)
    	  conectPage->writeCharacter(c);
      if (currentPage == MenuWindow::ROOM)
	room->drawBackGround(*window, mouseClicked);
      if (currentPage == MenuWindow::DEAD)
	deadPage->drawBackGround(*window, mouseClicked);
      if (currentPage == MenuWindow::END)
	endPage->drawBackGround(*window, mouseClicked);
      if (c != 0 && currentPage == MenuWindow::ROOM)
      {
    	  room->writeCharacter(c);
      }
      window->display();
      c = 0;
}

void MenuWindow::setTcpClient(IClient *client)
{
    _tcpClient = client;
}

bool MenuWindow::getConnected() const
{
    return (_connected);
}

LevelPage& MenuWindow::getLevel()
{
    return (*level);
}

EndPage*     MenuWindow::getEndPage()
{
    return endPage;
}

