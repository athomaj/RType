//
// Animation.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Thu Dec  3 13:48:29 2015 Timothy Burdairon
// Last update Tue Dec 15 12:29:02 2015 Timothy Burdairon
//


#ifndef ANIMATION_HH_
#define ANIMATION_HH_

#include "GameObject.hh"
#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Timer.hh"
#include "Audio.hh"

class Animation : public GameObject
{
public:
	enum 				typeAnimation {NORMAL, ATTACK, MOVEMENT, DEATH};
	Animation(const std::string &, bool);
	~Animation();
	void 				loadSprites(sf::Vector2<int>, sf::Vector2<int>, sf::Vector2<int>, typeAnimation);
	sf::Sprite 			*operator[](int);
	int					getHp() const;
	int 				getNumberOfSprites();
	int 				getRowSprite();
	void 				setPositionAnim(int, int);
	void 				goToPosition();
	void 				setNextPosition(int ,int);
	void 				setFrequencyAnimation(float, typeAnimation);
	void 				setFrequencyMove(float);
	void 				setDistanceMove(float );
	void 				setScale(float, typeAnimation);
	int 				getDistanceMove() const;
	void 				setTypeAnimation(typeAnimation);
	void 				launchMissile(int, bool);
	void 				setWeapon(Animation *);
	void 				setRotation(float);
	bool 				getStatusDeleteAnimation();
	void 				setPositionShoot(float, float);
	//sf::Vector2<int>	getPositionShoot();
	void 				setSound(Audio *audio);
	Audio 				*getSound();
	void				killAnimation();
	void				restartAnimation();
	std::string 		&getName();
	void 				selfImpact();
	void				setID(int a);
	int					getID() const;
	void				fire(Animation *weapon);
	void				setHp(int);
	void 				setForce(Animation *anim);
	void 				setTransparent(int value);
	void				setOffset(int, int);
	int 				getOffsetX();
	int 				getOffsetY();
	float				getScale();
	int													ID;



private:
	//int													ID;
	int													Hp;
	std::map<typeAnimation, std::list<sf::Sprite *> *>	animationSprites;
	sf::Vector2<int>									nextPosition;
	typeAnimation										currentTypeAnimation;
	bool												finishedAnimation;
	sf::Texture 										*texture;
	int													numberOfSprites[4];
	int					 								currentSprite[4];
	sf::Sprite											*lastSprite;
	Timer												animationTimer[4];
	Timer												speedTimer;
	float 												distanceMove;
	//Animation 								 			*weapon;
	bool												isHit;
	Timer												hitTime;
	Timer												durationBlink;
	bool												showShip;
	bool												isWeapon;
	bool												deleteAnimation;
	bool												willDelete;
	sf::Vector2<int> 									positionShoot;
	Audio 												*audio;
	std::string											fileName;
	float												scale;
	//sf::Vector2<int>									offset;
	int													offSetX;
	int													offSetY;

	Animation											*force;
	sf::Vector2<int>									forceOffset;
	Timer												forceTimer;
};

#endif /* !ANIMATION_HH_ */
