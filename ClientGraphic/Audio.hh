//
// Audio.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Tue Dec  8 11:10:05 2015 Timothy Burdairon
// Last update Tue Dec  8 11:10:05 2015 Timothy Burdairon
//


#ifndef AUDIO_HH_
#define AUDIO_HH_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include "Timer.hh"

class Audio
{
public:
	Audio(const std::string &);
	~Audio();
	bool		loadFile(const std::string &);
	void		playSound();
	void 		setVolume(float vol);
	void 		setPitch(float pitch);
	void		setLoop(bool);
	void		play();
	void		pause();
	void		stop();
	std::string getFileName() const;
	std::string getName();
  static float coefVolume(int);

private:
  std::string fileName;
  sf::SoundBuffer	soundBuffer;
  sf::Sound		sound;
  Timer			time;
  float			vol;
};



#endif  /* AUDIO_HH_ */
