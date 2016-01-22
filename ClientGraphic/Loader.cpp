//
// Loader.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Mon Nov 30 14:58:54 2015 Timothy Burdairon
// Last update Wed Dec  9 13:43:13 2015 Timothy Burdairon
//

#include "Loader.hh"

Loader::Loader(int &_gameWidth, int &_gameHeight, bool option, const std::string &mapName): gameHeight(_gameHeight)
{
	sequenceScene = 7;
	gameWidth = _gameWidth;
	std::cout << "gW:" << gameWidth << std::endl;
	numberOfBackGroundImages = 0;
	sizex = (float)_gameWidth / (float)sequenceScene;
	horizontal = option;
	MapParsing mapParsing(this, mapName);
	/*loadBackGround("background.png");
	loadBackGround("background.png");

	loadImageBackGround("marsPlanet.png", sf::Vector2f(100,400), 1,1);
	loadImageBackGround("redPlanete.png", sf::Vector2f(100,500), 14,1);
	loadImageBackGround("backPlanete.png", sf::Vector2f(100,200), 25, 0.5f);
	loadImageBackGround("jupiter.png", sf::Vector2f(100,800), 42, 1.2f);

	loadGameObjects("greenShip.png", 3, false);
	loadGameObjects("orangeShip.png", 3, false);
	loadGameObjects("player.png", 4, false);
	loadGameObjects("missilePlayer.png", 50, true);
	loadGameObjects("missileOrangeShip.png", 50, true);
	loadGameObjects("missileGreenShip.png", 50, true);*/
    std::cout << "before fail" << std::endl;
	Parsing pars(&typeGameObjects);
	typeGameObjects = pars.parseFiles();
	player = (*(typeGameObjects["player"]->begin()));
}

Loader::Loader(int &_gameWidth, int &_gameHeight): gameHeight(_gameHeight)
{
	sequenceScene = 7;
	gameWidth = _gameWidth;
	numberOfBackGroundImages = 0;
	sizex = _gameWidth / sequenceScene;
	loadBackGround("background.png");
	loadBackGround("background.png");
}

Loader::~Loader()
{

}


Animation *Loader::getPlayer()
{
	return (player);
}

Animation *Loader::getAnimationList(const std::string &name, int nb)
{
	int cnt = 0;

	for (std::list<Animation *>::iterator it = typeGameObjects[name]->begin(); it != typeGameObjects[name]->end(); ++it)
	{
		if (cnt == nb)
		{
			return ((*it));
		}
		++cnt;
	}
	return ((*(typeGameObjects[name]->begin())));
}

Animation *Loader::getAnimationList(const std::string &name)
{
	int cnt = 0;

	//std::cout << "name:" << name << std::endl;
	for (std::list<Animation *>::iterator it = typeGameObjects[name]->begin(); it != typeGameObjects[name]->end(); ++it)
	{
		if (cnt == typeCurrent[name])
		{

		//	std::cout << "|||" << std::endl;
			typeCurrent[name] = (typeCurrent[name] + 1) % typeGameObjects[name]->size();
			(*it)->restartAnimation();
			return ((*it));
		}
		++cnt;
	}
	std::cout << "Not Good" << std::endl;
	return ((*(typeGameObjects[name]->begin())));
}


void Loader::loadGameObjects(const std::string &_name, int number, bool isWeapon)
{
	int inc = -1;

	std::list<Animation*> *gameObjects = new std::list<Animation*>;
	std::string res("resources/");
	res.append(_name);
	while (++inc < number)
	{
		Animation *tmp = new Animation(_name, isWeapon);
		gameObjects->push_back(tmp);
	}

	size_t beg = res.find_last_of('/');
	size_t end = res.find_last_of('.');
	std::string newName = res.substr(beg + 1, (end) - (beg + 1));
	typeGameObjects[newName] = gameObjects;
	typeCurrent[newName] = 0;
}

int	Loader::getSequenceBackGroundSize()
{
	return (sizex);
}
int Loader::getNumberOfBackGroundImages() const
{
	return (numberOfBackGroundImages);
}

Timer		*Loader::getSpawnTime(sf::Sprite *tmp)
{
	if (mapSpriteBackGroundTimer.find(tmp) != mapSpriteBackGroundTimer.end())
		return (mapSpriteBackGroundTimer[tmp]);
	return (NULL);
}

bool Loader::loadImageBackGround(const std::string &name, sf::Vector2f pos, float time, float scale)
{
	std::string res("resources/");
	res.append(name);
	backGroundTexture = new sf::Texture();
	if (!backGroundTexture->loadFromFile(res.c_str()))
		return (false);
	sf::Sprite* currentSprite = new sf::Sprite;
	currentSprite->setTexture(*backGroundTexture);
	currentSprite->setTextureRect(sf::IntRect(0,0,backGroundTexture->getSize().x,backGroundTexture->getSize().y));
	currentSprite->setPosition(pos.x + this->gameWidth, pos.y);
	currentSprite->setScale(scale, scale);
	mapSpriteBackGroundTimer[currentSprite] = new Timer(time);
	return (true);
}

bool Loader::loadBackGround(const std::string &name)
{
	++(this->numberOfBackGroundImages);
	std::string res("resources/");
	res.append(name);
	backGroundTexture = new sf::Texture();
	if (!backGroundTexture->loadFromFile(res.c_str()))
	    return (false);
	backGroundTexture->setSmooth(true);
	int inc = mapSpriteBackGround.size() - 1;
	int t = inc;
	float sizeTextureSequence = ((float)(backGroundTexture->getSize().x) /(float) sequenceScene);
	while (++inc <=  t + sequenceScene)
	{
		sf::Sprite* currentSprite = new sf::Sprite;
		currentSprite->setTexture(*backGroundTexture);
		currentSprite->setTextureRect(sf::IntRect(((inc % sequenceScene) * sizeTextureSequence), 0, sizeTextureSequence, (float)(backGroundTexture->getSize().y)));
		currentSprite->setScale(((float)gameWidth / (float)(backGroundTexture->getSize().x)) + 0.01f, (float)gameHeight /  (float)(backGroundTexture->getSize().y));
		//if (horizontal == true)
		//{
			mapSpriteBackGround[currentSprite] = sf::Vector2<unsigned int>(inc  * sizex, 0);
		//}
		//else
		//{
		//	currentSprite->rotate(270);
			//mapSpriteBackGround[currentSprite] = sf::Vector2<unsigned int>(0, inc * sizex);
		//}
	}
	std::cout << "BackGround Loaded" << std::endl;
	return (true);
}

std::map<sf::Sprite *, sf::Vector2<unsigned int> > &Loader::getMapBackGround()
{
	return (mapSpriteBackGround);
}

std::map<sf::Sprite *, Timer* > &Loader::getMapBackGroundTimer()
{
	return (mapSpriteBackGroundTimer);
}





bool Loader::loadPause(const std::string &font)
{
	std::string res("resources/");
	res.append(font);
	 if (!pauseFont.loadFromFile(res.c_str()))
	        return false;
	    pauseText.setFont(pauseFont);
	    pauseText.setCharacterSize(40);
	    pauseText.setPosition(170.f, 150.f);
	    pauseText.setColor(sf::Color::White);
	    pauseText.setString("Game is paused");
	return (true);
}

sf::Text &Loader::getPauseText()
{
	return (pauseText);
}
