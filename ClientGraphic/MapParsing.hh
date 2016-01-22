//
// MapParsing.hh for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Sat Dec 12 16:38:06 2015 Timothy Burdairon
// Last update Sat Dec 12 16:38:06 2015 Timothy Burdairon
//
#ifndef MAPPARSING_HH_
#define MAPPARSING_HH_

#include "Loader.hh"

class Loader;

class MapParsing
{
public:
	typedef void (MapParsing::*type)(std::string &);
	MapParsing(Loader *, const std::string &);
	void  parseFile();
	void whatIsTheLine(std::string &name, std::string &args);
	void loadBackGroundMap(std::string &);
	void loadGameObjectsMap(std::string &args);
	void loadImageBackGroundMap(std::string &args);
	~MapParsing();

private:
	Loader 			*loadInfo;
	std::string		fileName;
	std::map<std::string, type> pointer;

};

#endif /* MAPPARSING_HH_ */
