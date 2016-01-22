//
// Audio.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Tue Dec  8 11:10:00 2015 Timothy Burdairon
// Last update Tue Dec  8 11:10:00 2015 Timothy Burdairon
//


#include "Audio.hh"


Audio::Audio(const std::string &_name)
{
	fileName = _name;
	std::string res("resources/");
	res.append(fileName);
	soundBuffer.loadFromFile(res);
	sound.setBuffer(soundBuffer);
	sound.setPitch(1.5f);
	vol = 10.f;
	sound.setVolume(vol);
	sound.setLoop(false);
}

Audio::~Audio()
{
}

float	Audio::coefVolume(int value)
{
  static int coef = 1;
  if (value == -1)
    return (coef);
  else
    coef = (float)value / 10;
  return (coef);
  
}

std::string Audio::getFileName() const
{
	return (fileName);
}

std::string Audio::getName()
{
	size_t z = 0;
	size_t n = 0;
	n = fileName.find_first_of('.', z);
	if (n > fileName.size())
		n = fileName.size();
	std::string sub(fileName.substr(z, n).c_str());
	return (sub);
}



bool		Audio::loadFile(const std::string &name)
{
	std::string res("resources/");
	res.append(name);
	if (!soundBuffer.loadFromFile(res))
			return (false);
	sound.setBuffer(soundBuffer);
	return (true);
}

void		Audio::play()
{
  sound.setVolume(vol * coefVolume(-1));
	//std::cout << "playing" << std::endl;
  sound.play();
}

void 		Audio::pause()
{
	sound.pause();
}

void 		Audio::stop()
{
	sound.stop();
}

void Audio::setPitch(float pitch)
{
	sound.setPitch(pitch);
}

void Audio::setLoop(bool status)
{
	sound.setLoop(status);
}


void Audio::setVolume(float _vol)
{
  vol = _vol;
	sound.setVolume(vol);
}

void Audio::playSound()
{

}


