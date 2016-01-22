//
// LinuxWindow.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
//
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
//
// Started on  Fri Nov 27 19:04:43 2015 Timothy Burdairon
// Last update Tue Dec 22 15:42:22 2015 Timothy Burdairon
//

#include "LinuxWindow.hh"

LinuxWindow::LinuxWindow(int x, int y, const std::string &name, const std::string &mapName)
: gameWidth(x), gameHeight(y), isPaused(false), windowName(name)
{
	speedWindow = 2;
	windowOrientationChange = false;
	window = new sf::RenderWindow(sf::VideoMode(gameWidth , gameHeight, 32), name.c_str(),
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

void LinuxWindow::setMainPlayer(Animation* player)
{
    mainPlayer = player;
}

void LinuxWindow::addScoreToPlayer(int id, int score)
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

Animation *LinuxWindow::getPlayer()
{
	return (loadInfo->getPlayer());
}

sf::RenderWindow *LinuxWindow::getWindow()
{
	return (window);
}

void LinuxWindow::loadNewGame(const std::string &file)
{
	speedWindow = 2;
	windowOrientationChange = false;
	loadInfo = new Loader(gameWidth, gameHeight, true, file);
	currentPositionWindowSprite = 0;
	lastObjectCreated = NULL;
	sizeXspriteBackGround = this->loadInfo->getSequenceBackGroundSize();
	gameObjects.clear();
	scores.clear();
	liveText.setString("0");
}

LinuxWindow::~LinuxWindow()
{
}

int	LinuxWindow::getGameWidth()
{
	return (gameWidth);
}

int	LinuxWindow::getGameHeight()
{
	return (gameHeight);
}


void LinuxWindow::fireWeapon(int id, const std::string &weapon, int idWeapon)
{
	Animation *obj = getAnimation(id);
	Animation *wep = getObject(weapon, idWeapon);
	if (obj != NULL)
		obj->fire(wep);
}

void	LinuxWindow::setForce(int id, const std::string &forceName, int idForce)
{
	Animation *obj = getAnimation(id);
	Animation *force = getObject(forceName, idForce);
	if (obj != NULL)
		obj->setForce(force);
}

void	LinuxWindow::setHp(const std::string &name, int id, int Hp)
{
	Animation *anim = getObject(name, id);
	anim->setHp(Hp);
}

void	LinuxWindow::setPosition(int id, float x, float y)
{
	Animation *obj = getAnimation(id);
	if (obj->getPosition().x == 0 && obj->getPosition().y == 0)
		obj->setPositionAnim(x, y);
	obj->setNextPosition(x, y);
}


Animation *LinuxWindow::getAnimation(int id)
{
	for (std::list<Animation*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if ((*it)->getID() == id)
			return (*it);
	}
	return (NULL);
}

Animation *LinuxWindow::getObject(const std::string &_name, int ID)
{
	Animation *tmp = NULL;
	if ((tmp = getAnimation(ID)) == NULL)
	{
		tmp = loadInfo->getAnimationList(_name);
		tmp->setID(ID);
		lastObjectCreated = tmp;
		size_t i;
//		if ((i = _name.find("player")) != std::string::npos && i == 0)
//		{
//			mainPlayer = tmp;
//			Score *tmpScore = new Score(tmp, posScore.x, gameHeight - posScore.y - (30 * scores.size()));
//			this->scores.push_back(tmpScore);
//		}
		this->gameObjects.push_back(tmp);
	}
	return (tmp);
}

Animation *LinuxWindow::getLastObjectCreated()
{
	return (lastObjectCreated);
}


void LinuxWindow::SwitchGameOrientation()
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

void LinuxWindow::setKeyRepeatEnabled(bool state)
{
	window->setKeyRepeatEnabled(state);
}


sf::Event &LinuxWindow::getEvent()
{
	return (this->event);
}

void LinuxWindow::setSize(int x, int y)
{
	sf::Vector2<unsigned int>   vec(x, y);
	window->setSize(vec);
}

void LinuxWindow::setGameWidth(int x)
{
  this->gameWidth = x;
}

void LinuxWindow::setGameHeight(int y)
{
  this->gameHeight = y;
}

void LinuxWindow::setVerticalSyncEnabled(bool state)
{
	window->setVerticalSyncEnabled(state);
}

bool LinuxWindow::isOpen()

{
	if (window->isOpen())
		return (true);
	return (false);
}

bool LinuxWindow::windowEventTrigger()
{
	if (window->pollEvent(this->event))
		return (true);
	return (false);
}

bool LinuxWindow::eventTrigger(sf::Event::EventType eventType)
{
	if (this->event.type == eventType)
		return (true);
	return (false);
}

bool LinuxWindow::keyTrigger(sf::Keyboard::Key keyType)
{
	if (this->event.key.code == keyType)
		return (true);
	return (false);
}

void LinuxWindow::close()
{
	window->close();
}

void LinuxWindow::clear()
{
	window->clear(sf::Color(0, 0, 0));
}

void LinuxWindow::pause()
{
	isPaused = !isPaused;
}

void LinuxWindow::drawBackGround()
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
			(*it).first->setPosition(x,(*it).first->getPosition().y);
			if (x > -((int)((*it).first)->getTexture()->getSize().x))
				window->draw(*((*it).first));
		}
	}
}

void LinuxWindow::MoveObjects()
{
	for (std::list<Animation*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
		{
//            std::cout << (*it)->getName() << " " << (*it)->getID() << std::endl;
			(*it)->goToPosition();
		}
}

void LinuxWindow::drawScore()
{
	for (std::list<Score*>::iterator it = scores.begin(); it != scores.end(); ++it)
	{
		window->draw((*it)->drawScore());
	}
}

void LinuxWindow::drawPlayerLives()
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

void LinuxWindow::drawGameObjects()
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


void LinuxWindow::display()
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
