//
// Loader.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Mon Nov 30 14:58:57 2015 Timothy Burdairon
// Last update Wed Dec  9 13:42:50 2015 Timothy Burdairon
//


#ifndef LOADER_HH_
#define LOADER_HH_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include <iostream>
#include "Animation.hh"
#include "Parsing.hh"
#include "Timer.hh"
#include "MapParsing.hh"

class MapParsing;

class Loader
{
public:
  Loader(int&, int&, bool, const std::string &);
  Loader(int&, int&);
  ~Loader();
  bool 													loadPause(const std::string &);
  bool 													loadBackGround(const std::string &);
  sf::Text 												&getPauseText();
  std::map<sf::Sprite *, sf::Vector2<unsigned int> > 	&getMapBackGround();
  int													getSequenceBackGroundSize();
  int 													getNumberOfBackGroundImages() const;
  void 													loadGameObjects(const std::string &, int, bool);
  Animation 											*getAnimationList(const std::string &name, int nb);
  Animation 											*getAnimationList(const std::string &name);
  Animation 											*getPlayer();
  bool 													loadImageBackGround(const std::string &, sf::Vector2f, float, float);
  Timer													*getSpawnTime(sf::Sprite *tmp);
  std::map<sf::Sprite *, Timer* > 						&getMapBackGroundTimer();


private:
  int													sequenceScene;
  bool 													horizontal;
  sf::Text 												pauseText;
  sf::Font 												pauseFont;
  int													gameWidth;
  sf::Texture 											*backGroundTexture;
  int 													gameHeight;
  float													sizex;
  int 													numberOfBackGroundImages;
  std::map<sf::Sprite *, sf::Vector2<unsigned int> > 	mapSpriteBackGround;
  std::map<sf::Sprite *, Timer*> 						mapSpriteBackGroundTimer;
  std::map<std::string, std::list<Animation*> *> 		typeGameObjects;
  std::map<std::string,  int> 							typeCurrent;
  Animation												*player;
};

#endif /* LOADER_HH_ */
