#include "WindowsWindow.hh"

WindowsWindow::WindowsWindow(int x, int y, const std::string &name, const std::string &mapName)
	: gameWidth(x), gameHeight(y), isPaused(false), windowName(name)
{
	speedWindow = 2;
	windowOrientationChange = false;
	window = new sf::RenderWindow(sf::VideoMode(gameWidth, gameHeight, 32), name.c_str(),
		sf::Style::Titlebar | sf::Style::Close);
	loadInfo = new Loader(x, y, true, mapName);
	currentPositionWindowSprite = 0;
	lastObjectCreated = NULL;
	sizeXspriteBackGround = this->loadInfo->getSequenceBackGroundSize();
	posScore.x = gameWidth / 5;
	posScore.y = gameHeight / 11;
	std::string res("resources/");
	res.append("airstrike.ttf");
	if (!liveFont.loadFromFile(res.c_str()))
		return;
	liveText.setFont(liveFont);
	liveText.setCharacterSize(55);
	liveText.setPosition(0.2f * (float)x, -0.007f * (float)y);
	liveText.setColor(sf::Color::White);
	std::string resour("resources/");
	resour.append("heart.png");
	heartTexture = new sf::Texture;
	if (!heartTexture->loadFromFile(resour))
		return;
	heart = new sf::Sprite;
	heart->setTexture(*heartTexture);
	heart->setTextureRect(sf::IntRect(0, 0, heartTexture->getSize().x, heartTexture->getSize().y));
	heart->setPosition(0.231 * (float)x, 0.015f * (float)y);
	heart->setScale(0.03f, 0.03f);
}

Animation *WindowsWindow::getPlayer()
{
	return (loadInfo->getPlayer());
}

sf::RenderWindow *WindowsWindow::getWindow()
{
	return (window);
}

void WindowsWindow::loadNewGame(const std::string &file)
{
	speedWindow = 2;
	windowOrientationChange = false;
	loadInfo = new Loader(gameWidth, gameHeight, true, file);
	currentPositionWindowSprite = 0;
	lastObjectCreated = NULL;
	sizeXspriteBackGround = this->loadInfo->getSequenceBackGroundSize();
	gameObjects.clear();
	scores.clear();
}

WindowsWindow::~WindowsWindow()
{
}

int	WindowsWindow::getGameWidth()
{
	return (gameWidth);
}

int	WindowsWindow::getGameHeight()
{
	return (gameHeight);
}


void WindowsWindow::fireWeapon(int id, const std::string &weapon, int idWeapon)
{
	Animation *obj = getAnimation(id);
	Animation *wep = getObject(weapon, idWeapon);
	if (obj != NULL)
		obj->fire(wep);
}

void	WindowsWindow::setForce(int id, const std::string &forceName, int idForce)
{
	Animation *obj = getAnimation(id);
	Animation *force = getObject(forceName, idForce);
	if (obj != NULL)
		obj->setForce(force);
}

void	WindowsWindow::setHp(const std::string &name, int id, int Hp)
{
	Animation *anim = getObject(name, id);
	anim->setHp(Hp);
}

void	WindowsWindow::setPosition(int id, float x, float y)
{
	Animation *obj = getAnimation(id);
	if (obj->getPosition().x == 0 && obj->getPosition().y == 0)
		obj->setPositionAnim(x, y);
	obj->setNextPosition(x, y);
}


Animation *WindowsWindow::getAnimation(int id)
{
	for (std::list<Animation*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if ((*it)->getID() == id)
			return (*it);
	}
	return (NULL);
}


void WindowsWindow::addScoreToPlayer(int id, int score)
{
	Animation *tmp = NULL;

	if ((tmp = getAnimation(id)) != NULL)
	{
		for (std::list<Score*>::iterator it = scores.begin(); it != scores.end(); ++it)
		{
			if (tmp == (*it)->getAnimation())
			{
				(*it)->setScore((*it)->getScore() + score);
			}
		}

	}
}


Animation *WindowsWindow::getObject(const std::string &_name, int ID)
{
	Animation *tmp = NULL;
	if ((tmp = getAnimation(ID)) == NULL)
	{
		tmp = loadInfo->getAnimationList(_name);
		tmp->setID(ID);
		lastObjectCreated = tmp;
		size_t i;
		if ((i = _name.find("player")) != std::string::npos && i == 0)
		{
			mainPlayer = tmp;
			Score *tmpScore = new Score(tmp, posScore.x, gameHeight - posScore.y - (30 * scores.size()));
			this->scores.push_back(tmpScore);
		}
		this->gameObjects.push_back(tmp);
	}
	return (tmp);
}

Animation *WindowsWindow::getLastObjectCreated()
{
	return (lastObjectCreated);
}


void WindowsWindow::SwitchGameOrientation()
{
	int tmp;
	tmp = gameHeight;
	gameHeight = gameWidth;
	gameWidth = tmp;
	windowOrientationChange = !windowOrientationChange;
	window = new sf::RenderWindow(sf::VideoMode(gameWidth, gameHeight, 32), windowName.c_str(),
		sf::Style::Titlebar | sf::Style::Close);
	loadInfo = new Loader(gameWidth, gameHeight, (!windowOrientationChange), "basic.map");
	currentPositionWindowSprite = 0;
	sizeXspriteBackGround = this->loadInfo->getSequenceBackGroundSize();
}

void WindowsWindow::setKeyRepeatEnabled(bool state)
{
	window->setKeyRepeatEnabled(state);
}


sf::Event &WindowsWindow::getEvent()
{
	return (this->event);
}

void WindowsWindow::setSize(int x, int y)
{
	sf::Vector2<unsigned int>   vec(x, y);
	window->setSize(vec);
}

void WindowsWindow::setGameWidth(int x)
{
	this->gameWidth = x;
}

void WindowsWindow::setGameHeight(int y)
{
	this->gameHeight = y;
}

void WindowsWindow::setVerticalSyncEnabled(bool state)
{
	window->setVerticalSyncEnabled(state);
}

bool WindowsWindow::isOpen()

{
	if (window->isOpen())
		return (true);
	return (false);
}

bool WindowsWindow::windowEventTrigger()
{
	if (window->pollEvent(this->event))
		return (true);
	return (false);
}

bool WindowsWindow::eventTrigger(sf::Event::EventType eventType)
{
	if (this->event.type == eventType)
		return (true);
	return (false);
}

bool WindowsWindow::keyTrigger(sf::Keyboard::Key keyType)
{
	if (this->event.key.code == keyType)
		return (true);
	return (false);
}

void WindowsWindow::close()
{
	window->close();
}

void WindowsWindow::clear()
{
	window->clear(sf::Color(0, 0, 0));
}

void WindowsWindow::pause()
{
	isPaused = !isPaused;
}

void WindowsWindow::drawBackGround()
{
	if (windowOrientationChange == false)
		this->currentPositionWindowSprite = (this->currentPositionWindowSprite + this->speedWindow) %
		(this->gameWidth * this->loadInfo->getNumberOfBackGroundImages());
	else
		this->currentPositionWindowSprite = (this->currentPositionWindowSprite + (this->speedWindow)) %
		(this->gameWidth * this->loadInfo->getNumberOfBackGroundImages());
	for (std::map<sf::Sprite *, sf::Vector2<unsigned int> >::iterator it = this->loadInfo->getMapBackGround().begin();
	it != this->loadInfo->getMapBackGround().end(); ++it)
	{
		if (windowOrientationChange == false)
		{
			int x = (*it).second.x;
			x = x - this->currentPositionWindowSprite;
			if (x <= -(sizeXspriteBackGround))
				x = x + (this->gameWidth * this->loadInfo->getNumberOfBackGroundImages());
			((*it).first)->setPosition(x, (*it).second.y);
		}
		else
		{
			int y = (*it).second.y;
			//y = y + this->currentPositionWindowSprite;
			if (y >  this->gameWidth *  this->loadInfo->getNumberOfBackGroundImages())
				y = y - (this->gameWidth * this->loadInfo->getNumberOfBackGroundImages());
			((*it).first)->setPosition((*it).second.x, y);
		}
		window->draw(*((*it).first));
	}

	for (std::map<sf::Sprite *, Timer *>::iterator it = this->loadInfo->getMapBackGroundTimer().begin();
	it != this->loadInfo->getMapBackGroundTimer().end(); ++it)
	{
		if ((*it).second->checkTime())
		{
			int x = (*it).first->getPosition().x - this->speedWindow;
			(*it).first->setPosition(x, (*it).first->getPosition().y);
			if (x > -((int)((*it).first)->getTexture()->getSize().x))
				window->draw(*((*it).first));
		}
	}
}

void WindowsWindow::MoveObjects()
{
	for (std::list<Animation*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->goToPosition();
	}
}

void WindowsWindow::drawScore()
{
	for (std::list<Score*>::iterator it = scores.begin(); it != scores.end(); ++it)
	{
		window->draw((*it)->drawScore());
	}
}

void WindowsWindow::drawGameObjects()
{
	for (std::list<Animation*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if ((*it)->getStatusDeleteAnimation() == true)
		{
			it = gameObjects.erase(it);
		}
		if (it != gameObjects.end())
		{
			sf::Sprite *tmp = NULL;
			int res = (*it)->getRowSprite();
			if (res >= 0)
				tmp = ((*(*it))[res]);
			if (tmp != NULL)
				window->draw(*tmp);
		}
	}
}


void WindowsWindow::drawPlayerLives()
{
	if (mainPlayer != NULL)
	{
		std::stringstream ss("");
		ss << mainPlayer->getHp();
		this->liveText.setString(ss.str());
		window->draw(liveText);
		window->draw(*heart);
	}
}


void WindowsWindow::display()
{
	if (isPaused == true)
		window->draw(loadInfo->getPauseText());
	else
	{
		drawBackGround();
		MoveObjects();
		drawGameObjects();
		drawScore();
		drawPlayerLives();
	}
	window->display();
}