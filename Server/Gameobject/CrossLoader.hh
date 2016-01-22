/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CrossLoader.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 3 décembre 2015, 18:29
 */

#ifndef CROSSLOADER_HH
#define CROSSLOADER_HH

#ifndef WIN32

#ifdef WIN32
	#include <direct.h>
	#include <windows.h>
#else
	#include <sys/types.h>
	#include <dlfcn.h>
#endif
#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <map>
#include "GameObject.hh"

#define DIRLIB "lib"

typedef void* func_t; 
typedef void* (*dllfct)();
typedef std::map<std::string, dllfct> Libmap;

/**
 * Chargeur de librairi dynamique cross platforme
 */
class CrossLoader
{
private:
	#ifdef WIN32
		HINSTANCE				lib_handle;
	#else
		void					*lib_handle;
	#endif
	DIR							*rep;
	std::map<std::string, dllfct> liblist;
	
	bool	isDllFile(const std::string& filename) const;
	void	findNewLibraries();
	int		countLibraries();
public:
	CrossLoader();
	CrossLoader(const CrossLoader& orig);
	virtual ~CrossLoader();

	/**
	 * Vérifie si toutes les librairies dynamiques ont été chargées
	 */
	void	checkLibraries();
	
	/**
	 * Charge toutes les librairie de facon sure
	 * 
	 * @param libpath chemin vers la librairie
	 */
	void	LoadLibraries();

	/**
	 * Charge une librairie spécifique
	 * 
	 * @param libpath chemin vers la librairie
	 */
	void	LoadLibrary(const std::string libpath);
	
	/**
	 * Chargement de la classe dynamique
	 */
	dllfct	LoadSymbole();
	
	/**
	 *	Ferme une librairie spécifique 
	 */
	void	CloseLibrary();
	
	const Libmap&	getLibList() const;
};

#endif
#endif /* CROSSLOADER_HH */

