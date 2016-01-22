/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CrossLoader.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 * 
 * Created on 3 décembre 2015, 18:29
 */

#include <stdexcept>
#include <vector>
#include <typeinfo>

#include "CrossLoader.hh"

CrossLoader::CrossLoader()
{
}

CrossLoader::CrossLoader(const CrossLoader& orig)
{
	(void)orig;
}

CrossLoader::~CrossLoader()
{
}

//template<typename Base, typename T>
//inline bool instanceof(const T*) {
//    return std::is_<Base, T>::value;
//}

void CrossLoader::findNewLibraries()
{
	std::cout << "findNewLibraries" << std::endl;
	struct dirent* ent = NULL;
	std::string	filename;
	std::vector<std::string>::iterator	it;
	
	rewinddir(rep);
	while ((ent = readdir(rep)) != NULL)
	{
		filename = ent->d_name;
		std::cout << filename << " check" << std::endl;
		if (this->isDllFile(filename) == true)
		{
			std::cout << filename << " is ok" << std::endl;
//			it = std::find(liblist.begin(), liblist.end(), filename);
			if (liblist.find(filename) == liblist.end())
			{
//				//Chargement de la librairie de mon amoureux <3
				this->LoadLibrary(std::string(DIRLIB) + "/" + filename);
				liblist.insert(std::pair<std::string, dllfct>(filename, this->LoadSymbole()));
//				this->CloseLibrary();
				try
				{
//					GameObject* fn_handle2 = dynamic_cast<GameObject *>(liblist[filename]());
//					CrossLoader* fn_handle2 = static_cast<CrossLoader *>(liblist[filename]());
					GameObject* fn_handle2 = static_cast<GameObject *>(liblist[filename]());
					std::cout << "11111" << std::endl;
//					GameObject* fn_handle2 = dynamic_cast<GameObject *>(fn_handle);
					if (fn_handle2 == NULL)
						std::cout << "NULL" << std::endl;
					std::cout << "22222" << std::endl;
					fn_handle2->affiche();
				}
				catch(const std::bad_cast& e)
				{
					std::cout << "FUCK" << std::endl;
					throw std::runtime_error("Fuck");
				}
//				liblist.push_back(filename);
			}
		}
	}
}

bool CrossLoader::isDllFile(const std::string& filename) const
{
	if (filename.compare(".") != 0 && filename.compare("..") != 0)
		{
			#if defined(WIN32) || defined(__CYGWIN__)
				if (filename.compare(filename.length() - 4, 4, ".dll") == 0)
					return (true);
			#else
				if (filename.compare(filename.length() - 3, 3, ".so") == 0)
					return (true);
			#endif
		}
	return (false);
}


int CrossLoader::countLibraries()
{
	int nbr = 0;
    struct dirent* ent = NULL;
	std::string filename;
	
    while ((ent = readdir(rep)) != NULL)
    {
		filename = ent->d_name;
		if (this->isDllFile(filename) == true)
			++nbr;
    }
	std::cout << "nbdll " << nbr << std::endl;
    return nbr;
}

void CrossLoader::LoadLibraries()
{
	this->checkLibraries();
}


void CrossLoader::checkLibraries()
{
	if ((rep = opendir(DIRLIB)) == NULL)
	{
		std::string	error(DIRLIB);
		error += " directory required";
		throw std::runtime_error(error);
	}
	if (this->countLibraries() != (int)(liblist.size()))
	{
		this->findNewLibraries();
	}
	closedir(rep);
}

void CrossLoader::LoadLibrary(const std::string libpath)
{
	#ifdef WIN32
//		string nameOfLibToLoad("C:\opt\lib\libctest.dll");
		lib_handle = LoadLibrary(TEXT(libpath.c_str()));
		if (!lib_handle)
		{
			std::cerr << "Cannot load library: " << libpath << std::endl;
		}
		else
		{
			std::cout << "Dynamic Load Window" << std::endl;
		}
	#else
		lib_handle = dlopen(libpath.c_str(), RTLD_LAZY);
		if (!lib_handle) 
		{
			std::cerr << "Cannot load library ["<< libpath <<"]: " << dlerror() << std::endl;
		}
		else
		{
			std::cout << "Dynamic Load linux" << std::endl;
		}
	#endif
}

dllfct CrossLoader::LoadSymbole()
{
	#ifdef WIN32
//		func_t* fn_handle = (func_t*) GetProcAddress(lib_handle, "affiche");
		GameObject* fn_handle = (GameObject*) GetProcAddress(lib_handle, "affiche");
		if (!fn_handle) 
		{
			std::cerr << "Cannot load symbol superfunctionx: " << GetLastError() << std::endl;
		}
		else
		{
			std::cout << "Load symboly" << std::endl;
		}
	#else
		// reset errors
		dlerror();

		// load the symbols (handle to function "superfunctionx")
//		func_t* fn_handle= (func_t*) dlsym(lib_handle, "affiche");
//		void* (*fptr)();
		dllfct fptr;
		fptr = (dllfct)dlsym(lib_handle, "create");
//		fptr = static_cast< dllfct>(dlsym(lib_handle, "create"));
		const char* dlsym_error = dlerror();
		if (dlsym_error) 
		{
			std::cerr << "Cannot load symbol superfunctionx: " << dlsym_error << std::endl;
		}
		else
		{
			std::cout << "Load symboly Linux" << std::endl;
		}
	#endif
//		GameObject* fn_handle = reinterpret_cast<GameObject *>(fptr());
//		fn_handle->affiche();
		return (fptr);
}

void CrossLoader::CloseLibrary()
{
	#ifdef WIN32
		FreeLibrary(lib_handle);
	#else
		dlclose(lib_handle);
	#endif
}

const Libmap& CrossLoader::getLibList() const
{
	return (this->liblist);
}
