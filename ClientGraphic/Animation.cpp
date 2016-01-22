//
// Animation.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Thu Dec  3 13:48:25 2015 Timothy Burdairon
// Last update Mon Jan  4 03:21:42 2016 Timothy Burdairon
//

#include <stdlib.h>
#include "Animation.hh"



Animation::Animation(const std::string &_textureName, bool _isWeapon):
GameObject(0, 0)
{
	nextPosition.x = 0;
	nextPosition.y = 0;
	rotation = 0;
	ID = 0;
	Hp = 0;
	//weapon = NULL;
	distanceMove = 5;
	finishedAnimation = true;
	currentTypeAnimation = Animation::NORMAL;
	numberOfSprites[0] = 0;
	numberOfSprites[1] = 0;
	numberOfSprites[2] = 0;
	numberOfSprites[3] = 0;
	willDelete = false;
	animationTimer[0].setTimer(0.25f);
	animationTimer[1].setTimer(0.25f);
	animationTimer[2].setTimer(0.25f);
	animationTimer[3].setTimer(0.25f);
	animationSprites[Animation::NORMAL] = new std::list<sf::Sprite *>;
	animationSprites[Animation::ATTACK] = new std::list<sf::Sprite *>;
	animationSprites[Animation::MOVEMENT] = new std::list<sf::Sprite *>;
	animationSprites[Animation::DEATH] = new std::list<sf::Sprite *>;
	distanceMove = 5;
	showShip = true;
	hitTime.setTimer(1);
	durationBlink.setTimer(0.1f);
	speedTimer.setTimer(0.01f);
	isHit = false;
	std::string res("resources/");
	res.append(_textureName);
	texture = new sf::Texture();
	texture->loadFromFile(res);
	fileName =_textureName;
	lastSprite = NULL;
	currentSprite[0] = -1;
	currentSprite[1] = -1;
	currentSprite[2] = -1;
	currentSprite[3] = -1;
	isWeapon = _isWeapon;
	deleteAnimation = false;
	positionShoot.x = 0;
	positionShoot.y = 0;
	audio = NULL;
	force = NULL;
	offSetY = 0;
	offSetX = 0;
//	animationSprites = new std::list<sf::Sprite*>();
}

void Animation::restartAnimation()
{
	animationTimer[0].setTimer(0.25f);
	animationTimer[1].setTimer(0.25f);
	animationTimer[2].setTimer(0.25f);
	animationTimer[3].setTimer(0.25f);
	speedTimer.setTimer(0.01f);
	currentSprite[0] = -1;
	currentSprite[1] = -1;
	currentSprite[2] = -1;
	currentSprite[3] = -1;
	deleteAnimation = false;
	willDelete = false;
	this->setTypeAnimation(Animation::NORMAL);
}

void	Animation::fire(Animation *weapon)
{
	this->setTypeAnimation(Animation::ATTACK);
	if (weapon->getSound() != NULL)
		weapon->getSound()->play();

	/* To delete */
	weapon->setNextPosition(1700, this->getPosition().y);
}

void Animation::setHp(int value)
{
	if (Hp == 0)
	{
		Hp = value;
	}
	if (value == 0)
	{
		Hp = 0;
		killAnimation();
	}
	if (Hp != value)
	{
		Hp = value;
		selfImpact();
	}
}

int					Animation::getHp() const
{
	return (Hp);
}

int Animation::getNumberOfSprites()
{
	return (this->numberOfSprites[currentTypeAnimation]);
}

void 	Animation::selfImpact()
{
	hitTime.restart();
	isHit = true;
	//std::cout << "self Impact" << std::endl;
	durationBlink.restart();
	showShip = false;
}

void Animation::setForce(Animation *anim)
{
	if (anim != NULL)
	{
		force = anim;
		forceTimer.setTimer(5);
 		forceTimer.restart();
		force->setTypeAnimation(Animation::NORMAL);
		forceOffset.x =  -20;
		forceOffset.y = -60;
		force->setPositionAnim(this->position.x + forceOffset.x, this->position.y + forceOffset.y);
		force->setTransparent(120);
	}
}

void Animation::setTransparent(int value)
{
	int c = -1;
	while (++c < 4)
	{
		for (std::list<sf::Sprite *>::iterator it = animationSprites[(typeAnimation)c]->begin(); it != animationSprites[(typeAnimation)c]->end(); ++it)
		{
			(*it)->setColor(sf::Color(255,255,255, value));
		}
	}
}

void Animation::loadSprites(sf::Vector2<int> start, sf::Vector2<int> end, sf::Vector2<int> size, typeAnimation tA)
{
	sf::Vector2<int> inc = start;
	std::list<sf::Sprite *>	*tmplist = new std::list<sf::Sprite *>;
	sf::Texture			*tmpTexture = texture;
	if (tA == Animation::DEATH)
	{
		std::string res("resources/");
		res.append("death");
		res.append(fileName);
		tmpTexture = new sf::Texture();
		tmpTexture->loadFromFile(res);
	}
	if (start.y != end.y)
	  {
	    while (inc.x < end.x && inc.y <= end.y)
	      {
		sf::Sprite *tmp = new sf::Sprite;
		tmp->setTexture(*tmpTexture);
		tmp->setTextureRect(sf::IntRect(inc.x, inc.y, size.x, size.y));
		tmplist->push_back(tmp);
		inc.x += size.x;
		if (inc.x >= end.x)
		  {
		    inc.y += size.y;
		    inc.x = start.x;
		  }
		numberOfSprites[(int)tA] += 1;
	      }
	  }
	else
	  {
	    while (inc.x < end.x)
	      {
		sf::Sprite *tmp = new sf::Sprite;
		tmp->setTexture(*tmpTexture);
		tmp->setTextureRect(sf::IntRect(inc.x, inc.y, size.x, size.y));
		tmplist->push_back(tmp);
		inc.x += size.x;
		numberOfSprites[(int)tA] += 1;
	      }
	  }

	animationSprites[tA] = tmplist;
}

sf::Sprite *Animation::operator[](int place)
{
	int cnt = 0;

	for (std::list<sf::Sprite *>::iterator it = (animationSprites[currentTypeAnimation])->begin(); it != animationSprites[currentTypeAnimation]->end() ; ++it)
	{
		if (cnt == place)
		{
				lastSprite = *it;
				return (*it);
		}
		++cnt;
	}
	return (lastSprite);
}

void Animation::setNextPosition(int _x, int _y)
{
	nextPosition.x = _x;
	nextPosition.y = _y;
	speedTimer.restart();
}

int Animation::getDistanceMove() const
{
	return (distanceMove);
}

void Animation::setID(int value)
{
	ID = value;
}

int	Animation::getID() const
{
	return (ID);
}

void Animation::goToPosition()
{
//    speedTimer.isTime() &&
	if ((abs(nextPosition.x - this->getPosition().x) > 3
			|| abs(nextPosition.y - this->getPosition().y) > 3))
	{
		float a;
		float x = nextPosition.x - this->getPosition().x;
		float y = nextPosition.y  - this->getPosition().y;
		 if (x != 0 && y != 0)
			a = y / x;
		 else
			a = 1;
		  x = a * x;
		  y = a * y;
		  int distanceMovetmp = distanceMove / 3;
		  if (x > 0 && y > 0)
			 this->setPositionAnim(this->getPosition().x + distanceMovetmp, this->getPosition().y + distanceMovetmp);
		  else if (x > 0 && y == 0)
				 this->setPositionAnim(this->getPosition().x + distanceMovetmp, this->getPosition().y);
		  else if (x > 0 && y < 0)
				 this->setPositionAnim(this->getPosition().x - distanceMovetmp, this->getPosition().y + distanceMovetmp);
		  else if (x == 0 && y < 0)
				 this->setPositionAnim(this->getPosition().x, this->getPosition().y - distanceMovetmp);
		  else if (x < 0 && y < 0)
				 this->setPositionAnim(this->getPosition().x - distanceMovetmp, this->getPosition().y - distanceMovetmp);
		  else if (x < 0 && y == 0)
				 this->setPositionAnim(this->getPosition().x - distanceMovetmp, this->getPosition().y);
		  else if (x < 0 && y > 0)
				 this->setPositionAnim(this->getPosition().x + distanceMovetmp, this->getPosition().y - distanceMovetmp);
		  else if (x == 0 && y > 0)
				 this->setPositionAnim(this->getPosition().x, this->getPosition().y + distanceMovetmp);
		  speedTimer.restart();
	}
//	if (isWeapon == true && abs(nextPosition.x - this->getPosition().x) < distanceMove && abs(nextPosition.y - this->getPosition().y) < distanceMove)
//	{
//		killAnimation();
//	}
//	if (force != NULL && forceTimer.checkTime())
//	{
//		force->killAnimation();
//		force = NULL;
//	}
}

void	Animation::killAnimation()
{
	willDelete = true;
	if (isWeapon == false && audio != NULL)
		audio->play();
	this->setTypeAnimation(Animation::DEATH);
}

bool 	Animation::getStatusDeleteAnimation()
{
	return (deleteAnimation);
}

void	Animation::setPositionAnim(int x, int y)
{
	int c = -1;
	while (++c < 4)
	{
		for (std::list<sf::Sprite *>::iterator it = animationSprites[(typeAnimation)c]->begin(); it != animationSprites[(typeAnimation)c]->end(); ++it)
		{
			if (nextPosition.x == this->position.x && nextPosition.y == this->position.y)
			{
				setPosition(x, y);
				if (rotation == 180)
					(*it)->setPosition(x /*+ this->positionShoot.x*/ + offSetX, y  /*this->positionShoot.y*/ + offSetY);
				else if (rotation == 270)
				  (*it)->setPosition(x -  offSetX, y  /*this->positionShoot.y*/ + offSetY);
				else
					(*it)->setPosition(x /*+ this->positionShoot.x*/ - offSetX, y  /*this->positionShoot.y*/ - offSetY);
				setNextPosition(x, y);
			}
			else
			{
				setPosition(x, y);
				if (rotation == 180)
					(*it)->setPosition(x /*+ this->positionShoot.x*/ + offSetX, y  /*this->positionShoot.y*/ + offSetY);
				else if (rotation == 270)
				  (*it)->setPosition(x -  offSetX /*+ this->positionShoot.x*/, y  /*this->positionShoot.y*/ + offSetY);
				else
					(*it)->setPosition(x /*+ this->positionShoot.x*/ - offSetX, y  /*this->positionShoot.y*/ - offSetY);
			}
			if (force != NULL)
				force->setPositionAnim(x + forceOffset.x, y + forceOffset.y);
		}
	}
}

std::string &Animation::getName()
{
	return (fileName);

}

void	Animation::setRotation(float x)
{
	int c = -1;
	while (++c < 4)
	{
		for (std::list<sf::Sprite *>::iterator it = animationSprites[(typeAnimation)c]->begin(); it != animationSprites[(typeAnimation)c]->end(); ++it)
		{
			(*it)->setRotation(x);
			rotation = x;
		}
	}
}

void	Animation::setScale(float _scale, typeAnimation tA)
{
	if (tA == Animation::NORMAL)
		scale = _scale;
	for (std::list<sf::Sprite *>::iterator it = animationSprites[tA]->begin(); it != animationSprites[tA]->end(); ++it)
	{
		(*it)->scale(_scale, _scale);
	}
}

float		Animation::getScale()
{
	return (scale);
}

Audio *Animation::getSound()
{
	return (audio);
}

void Animation::setSound( Audio *_audio)
{
	this->audio= _audio;
}

int Animation::getRowSprite()
{
	if (animationTimer[currentTypeAnimation].isTime())
	{
		currentSprite[currentTypeAnimation] = (currentSprite[currentTypeAnimation] + 1) % (numberOfSprites[currentTypeAnimation] + 1);
		animationTimer[currentTypeAnimation].restart();
	}

	//std::cout << currentSprite[currentTypeAnimation] << std::endl;
	if (currentSprite[currentTypeAnimation] == numberOfSprites[currentTypeAnimation])
	{
		if (currentTypeAnimation == Animation::DEATH)
			{
				deleteAnimation = true;
			}
		else
		{
			finishedAnimation = true;
			this->setTypeAnimation(Animation::NORMAL);
		}
	}
	else
		finishedAnimation = false;
	if (isHit == true  && hitTime.checkTime())
	{
		std::cout << "END Hit" << std::endl;
		isHit = false;
		showShip = true;
	}
	if (isHit == true && durationBlink.isTime())
	{
		std::cout << "BLINK" << std::endl;
		showShip = !showShip;
	}
	if (showShip == true)
		return (currentSprite[(currentTypeAnimation)]);
	else
		return (-1);
}

/* May not be needed Anymore */

void 	Animation::setPositionShoot(float x, float y)
{
	this->positionShoot.x  = x;
	this->positionShoot.y  = y;
}
/*
sf::Vector2<int>		Animation::getPositionShoot()
{
	return (positionShoot);
}

void Animation::launchMissile(int windowWidth, bool isEnemy)
{
	if (isEnemy == false)
	{
		weapon->setPositionAnim(this->getPosition().x - weapon->getPositionShoot().x, this->getPosition().y - weapon->getPositionShoot().y);
		weapon->setNextPosition(windowWidth , this->getPosition().y - weapon->getPositionShoot().y);
	}
	else
	{
		weapon->setRotation(180);
		weapon->setPositionAnim(this->getPosition().x - weapon->getPositionShoot().x, this->getPosition().y - weapon->getPositionShoot().y);
		weapon->setNextPosition(10, this->getPosition().y - weapon->getPositionShoot().y);
	}
	this->setTypeAnimation(Animation::ATTACK);
	if (weapon->getSound() != NULL)
		weapon->getSound()->play();
}

void Animation::setWeapon(Animation *_missile)
{
	weapon = _missile;
}
*/

/* ----------------------- */


void		Animation::setOffset(int x, int y)
{
	offSetX = x;
	offSetY = y;
}

int 	Animation::getOffsetY()
{
	return (offSetY);
}

int 	Animation::getOffsetX()
{
	return (offSetX);
}


void Animation::setFrequencyAnimation(float tmp, typeAnimation tA)
{
	this->animationTimer[tA].setTimer(tmp);
	//this->speedOfAnimation = tmp;
}

void Animation::setTypeAnimation(typeAnimation tA)
{
	this->currentTypeAnimation = tA;
	//animationTimer[currentTypeAnimation].restart();
}

void Animation::setFrequencyMove(float tmp)
{
	this->speedTimer.setTimer(tmp);
}

void Animation::setDistanceMove(float tmp)
{
	this->distanceMove = tmp;
}


Animation::~Animation()
{

}




