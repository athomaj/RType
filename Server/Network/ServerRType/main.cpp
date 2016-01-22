/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 26 novembre 2015, 11:47
 */

#include "ServerTCP.hpp"
#include "ServerUDP.hpp"
#include "Thread.hpp"
#include "GameManager.hpp"
#include "Parser.hh"
#include "CrossLoader.hh"

void* launchServer(void *param)
{
    IServer* serv;
    
    serv = reinterpret_cast<IServer *>(param);
    serv->initMutex();
    try
    {
        serv->run(4242);
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return NULL;
}


void* launchManager(void *param)
{
    IServer* serv;
    serv = reinterpret_cast<IServer *>(param);
    IGameManager* gameManager = new GameManager(serv);
    serv->setGameManager(gameManager);
    gameManager->run();
    return NULL;
}

/*
 * 1 scénario / niveau (map)
 * 
 * Scénario:
 * Type obj, cycle, coord
 * 
 * Script obj:
 * debut cycle, fin cycle, coord vecteur directeur, 
 * 
 * type tir, frequence
 * 
 * scenario contient par cycle le niveau
 * 
 */
int main(int argc, char** argv)
{
#ifdef WIN32
	std::cout << "Win32" << std::endl;
#elif _WIN32
	std::cout << "_Win32" << std::endl;
#elif __WIN32
	std::cout << "__Win32" << std::endl;
#elif __CYGWIN__
	std::cout << "cygwin" << std::endl;
#else
	std::cout << "Autre" << std::endl;
#endif
	GameObject* gg = new GameObject;
#ifdef _WIN32
	IThread *thread = new ThreadWin();
	IThread *manag = new ThreadWin();
#else
	IThread *thread = new Thread();
	IThread *manag = new Thread();
#endif
    IServer *server = new ServerTCP();
	
	thread->create(reinterpret_cast<void*>(&launchServer), server);
    manag->create(reinterpret_cast<void*>(&launchManager), server);
    manag->join();
	
//	CrossLoader *loader = new CrossLoader();
//		
//	try
//	{
//		loader->checkLibraries();
//	}
//	catch (std::exception &e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//	loader->LoadLibrary("tim.dll");
//	loader->LoadSymbole();
//	loader->CloseLibrary();
//	Parser *parser = new Parser();
//	try
//	{
//		parser->load("Starwars");
//	}
//	catch (std::exception &e)
//	{
//		std::cout << e.what() << std::endl;
//	}
	return 0;
}

