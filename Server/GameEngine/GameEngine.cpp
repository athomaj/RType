/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameEngine.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 * 
 * Created on 11 décembre 2015, 13:35
 */

#include "GameEngine.hh"
//#include "GameEngine.hpp"

void* launchUDPClient(void *param)
{
    GameEngine* engine = reinterpret_cast<GameEngine *>(param);
    
    engine->getServer()->run(engine->getRoom()->getPort());
    return (NULL);
}

GameEngine::GameEngine() :
    _thread(NULL), _servUdp(NULL)
{
#ifdef _WIN32
	_cond = new ThreadCondWin();
#else
	_cond = new ThreadCond();
#endif
    _cond->init();
    _curCycle = 0;
    shotId = 100;
}

GameEngine::GameEngine(const GameEngine& orig)
{
}

GameEngine::~GameEngine()
{
}

IServer* GameEngine::getServer()
{
    return (_servUdp);
}

Room* GameEngine::getRoom()
{
    return (_room);
}

IThreadCond* GameEngine::getThreadCond()
{
    return (_cond);
}

void GameEngine::setRoom(Room *room)
{
    _room = room;
}

void GameEngine::launch()
{
    _servUdp = new ServerUDP();
    _servUdp->initMutex();
    _servUdp->setGameEngine(this);
#ifdef _WIN32
	_thread = new ThreadWin();
#else
	_thread = new Thread();
#endif
    _thread->create(reinterpret_cast<void*>(&launchUDPClient), this);
    
    createPlayers(static_cast<int>(_room->getNbPlayer()));
    addMobs();
    while (1)
    {
        if (!_servUdp)
            return ;
        checkActions();
        checkMobs();
        moveObjects();
        sendNewData();
#ifdef _WIN32
		Sleep(10);
#else
		usleep(10000);
#endif
        ++_curCycle;
	//std::cout << _curCycle << std::endl;
    }
}

void GameEngine::checkMobs()
{
    for (unsigned int i=0; i<_objects.size(); ++i)
    {
        if ((_objects[i].getType() == "greenShip" || _objects[i].getType() == "orangeShip" ||
             _objects[i].getType() == "greenMonster" || _objects[i].getType() == "greenLarve" ||
             _objects[i].getType() == "boss") && _objects[i].getState() == WAITING && _objects[i].getSpawn() == _curCycle)
        {
            _objects[i].setState(SPAWNED);
        }
        if ((_objects[i].getType() == "greenShip" || _objects[i].getType() == "orangeShip")
            && _objects[i].getState() == SPAWNED && (_curCycle % _objects[i].getShotFrequency() == 0))
        {
            GameObject shot;
            shot.setPositionY(_objects[i].getPositionY());
	    //   std::cout << "pos:" <<  _objects[i].getPositionY() << std::endl;
            shot.setPositionX(_objects[i].getPositionX() - 30);
            shot.setId(shotId++);
            shot.setOwner(_objects[i].getId());
            shot.setType("missileGreenShip");
            shot.setSpeed(3);
            shot.setState(SPAWNED);
            shot.setPath(-70, _objects[i].getPositionY());
	    shot.setMissileSize(_objects[i].getMissileSizeX(), _objects[i].getMissileSizeY());
            _objects.push_back(shot);
        }

	if ((_objects[i].getType() == "greenMonster" || _objects[i].getType() == "greenLarve")
	    && _objects[i].getState() == SPAWNED && (_curCycle % _objects[i].getShotFrequency() == 0))
        {
            GameObject shot;
            shot.setPositionY(_objects[i].getPositionY());
	    //   std::cout << "pos:" <<  _objects[i].getPositionY() << std::endl;
            shot.setPositionX(_objects[i].getPositionX() - 30);
            shot.setId(shotId++);
            shot.setOwner(_objects[i].getId());
            shot.setType("missileGreenShip1");
            shot.setSpeed(3);
            shot.setState(SPAWNED);
            shot.setPath(-70, _objects[i].getPositionY());
	    shot.setMissileSize(_objects[i].getMissileSizeX(), _objects[i].getMissileSizeY());
            _objects.push_back(shot);
        }

     if (_objects[i].getType() == "boss"
            && _objects[i].getState() == SPAWNED && (_curCycle % _objects[i].getShotFrequency() == 0))
        {
          
            GameObject shot;
            shot.setPositionY(_objects[i].getPositionY());
	    //   std::cout << "pos:" <<  _objects[i].getPositionY() << std::endl;
            shot.setPositionX(_objects[i].getPositionX() - 30);
            shot.setId(shotId++);
            shot.setOwner(_objects[i].getId());
            shot.setType("missileBoss");
            shot.setSpeed(3);
            shot.setState(SPAWNED);
            shot.setPath(-70, _objects[i].getPositionY());
	    shot.setMissileSize(_objects[i].getMissileSizeX(), _objects[i].getMissileSizeY());
            _objects.push_back(shot);
	    GameObject shot2;
            shot2.setPositionY(_objects[i].getPositionY());
	    //   std::cout << "pos:" <<  _objects[i].getPositionY() << std::endl;
            shot2.setPositionX(_objects[i].getPositionX() - 30);
            shot2.setId(shotId++);
            shot2.setOwner(_objects[i].getId());
            shot2.setType("missileBoss");
            shot2.setSpeed(3);
            shot2.setState(SPAWNED);
            shot2.setPath(-70, 0);
	    shot2.setMissileSize(_objects[i].getMissileSizeX(), _objects[i].getMissileSizeY());
            _objects.push_back(shot2);
	    
        }
    }
}

int		GameEngine::getXValue(GameObject *obj)
{
	int cnt = 0;
	for (std::list<t_coord*>::iterator it = obj->getPath().begin(); it != obj->getPath().end(); ++it)
	{
		if (cnt == obj->getCurrentIterator())
		{
			return ((*it)->x);
		}
		++cnt;
	}
    return (1);
}

int		GameEngine::getYValue(GameObject *obj)
{
	int cnt = 0;
	for (std::list<t_coord*>::iterator it = obj->getPath().begin(); it != obj->getPath().end(); ++it)
	{
		if (cnt == obj->getCurrentIterator())
		{
			return ((*it)->y);
		}
		++cnt;
	}
    return (1);
}


void GameEngine::moveObjectsToPosition(GameObject *it)
{
	float a;
	if (getXValue(it) - it->getPositionX() == 0 && getYValue(it)  - it->getPositionY() == 0)
	{
		std::cout << "GOOD" << std::endl;
		it->setCurrentIterator((it->getCurrentIterator() + 1) %  it->getPath().size());
		std::cout << getXValue(it) << std::endl;
		std::cout << getYValue(it) << std::endl;
	}
	float x = getXValue(it) - it->getPositionX();
	float y = getYValue(it)  - it->getPositionY();
	if (x != 0 && y != 0)
		a = y / x;
	else
	a = 1;
  x = a * x;
  y = a * y;
  int distanceMovetmp = it->getSpeed();

	  if (x > 0 && y > 0)
	  {
			 //this->setPositionAnim(this->getPosition().x + distanceMovetmp, this->getPosition().y + distanceMovetmp);
			 it->setPositionX(it->getPositionX() +  distanceMovetmp);
			 it->setPositionY(it->getPositionY() +  distanceMovetmp);
	  }
	else if (x > 0 && y == 0)
	 {
		 it->setPositionX(it->getPositionX() +  distanceMovetmp);

	//			 this->setPositionAnim(this->getPosition().x + distanceMovetmp, this->getPosition().y);
	  }
		  else if (x > 0 && y < 0)
		  {
				 it->setPositionX(it->getPositionX() -  distanceMovetmp);
				 it->setPositionY(it->getPositionY() +  distanceMovetmp);

				 //this->setPositionAnim(this->getPosition().x - distanceMovetmp, this->getPosition().y + distanceMovetmp);
		  }
		  else if (x == 0 && y < 0)
		  {
				 it->setPositionY(it->getPositionY() -  distanceMovetmp);

				 //this->setPositionAnim(this->getPosition().x, this->getPosition().y - distanceMovetmp);
		  }
		  else if (x < 0 && y < 0)
		  {
				 it->setPositionX(it->getPositionX() -  distanceMovetmp);
				 it->setPositionY(it->getPositionY() -  distanceMovetmp);

				 //this->setPositionAnim(this->getPosition().x - distanceMovetmp, this->getPosition().y - distanceMovetmp);
		  }
		  else if (x < 0 && y == 0)
		  {
				 it->setPositionX(it->getPositionX() -  distanceMovetmp);
				 //it.setPositionY(it->getPositionY() +  distanceMovetmp);

//				 this->setPositionAnim(this->getPosition().x - distanceMovetmp, this->getPosition().y);
		  }
		  else if (x < 0 && y > 0)
		  {
				 it->setPositionX(it->getPositionX() +  distanceMovetmp);
				 it->setPositionY(it->getPositionY() -  distanceMovetmp);
				 //this->setPositionAnim(this->getPosition().x + distanceMovetmp, this->getPosition().y - distanceMovetmp);
		  }
		  else if (x == 0 && y > 0)
		  {
//				 it->setPositionX(it->getPositionX() +  distanceMovetmp);
				 it->setPositionY(it->getPositionY() +  distanceMovetmp);

			//	 this->setPositionAnim(this->getPosition().x, this->getPosition().y + distanceMovetmp);
		  }

}

void GameEngine::moveObjects()
{
    for (unsigned int i=0; i<_objects.size(); ++i)
    {
    	if (_objects[i].getType() == "player")
    	    {
    	          if (_objects[i].getHP() <= 0)
    	              _objects[i].setState(DEAD);
    	    }
        else if (_objects[i].getType() == "missileGreenShip" || _objects[i].getType() == "missilePlayer"
		 ||_objects[i].getType() == "missileGreenShip1" || _objects[i].getType() == "missileBoss"
		 ||_objects[i].getType() == "missileRed")
        {
	  moveObjectsToPosition(&_objects[i]);
	}
        else if ((_objects[i].getType() == "greenShip" || _objects[i].getType() == "orangeShip" ||
             _objects[i].getType() == "greenMonster" || _objects[i].getType() == "greenLarve" ||
             _objects[i].getType() == "boss")
                 && _objects[i].getState() == SPAWNED)
        {
            if (_objects[i].getHP() <= 0)
	      {
                _objects[i].setState(DEAD);
	      }
            else
            	moveObjectsToPosition(&_objects[i]);
                //_objects[i].setPositionX(_objects[i].getPositionX() - 1);
        }
    }
}

bool GameEngine::checkShootCollisions(GameObject& object, int const offsetl, int const offseth)
{
    for (unsigned int i=0; i<_objects.size(); ++i)
    {
        if (_objects[i].getState() != DEAD && _objects[i].getId() != object.getOwner() &&
            (_objects[i].getType() == "player" ||
             ((_objects[i].getType() == "greenShip" || _objects[i].getType() == "orangeShip" ||
               _objects[i].getType() == "greenMonster" || _objects[i].getType() == "greenLarve" ||
               _objects[i].getType() == "boss")
              && _objects[i].getState() == SPAWNED)))
        {
	  if ((object.getPositionX() - object.getMissileSizeX() <= _objects[i].getPositionX() + _objects[i].getSizeX() &&
	       object.getPositionX() + object.getMissileSizeX() >= _objects[i].getPositionX() - _objects[i].getSizeX()) &&
	      (object.getPositionY() - object.getMissileSizeY() <= _objects[i].getPositionY() + _objects[i].getSizeY() &&
	       object.getPositionY() + object.getMissileSizeY() >= _objects[i].getPositionY() - _objects[i].getSizeY()))
	    {
                _objects[i].setHP(_objects[i].getHP() - 5);
                Packet packet = Packet::build(7, std::to_string(_objects[i].getId()) + " " // 7 == BLINK
                                              + std::to_string(_objects[i].getPositionX())
                                              + " " + std::to_string(_objects[i].getPositionY()) + " ");
                if (_servUdp)
                    _servUdp->broadcast(packet);
                int id = object.getOwner();
                if (id >= 0 && id <= 3)
                {
                    auto& players = _room->getSavedPlayers();
                    players[id]->incScore();
                }
                return true;
            }
        }
    }
    return false;
}

//void GameEngine::sendPacket(PacketType type)
//{
//}

void GameEngine::sendNewData()
{
    auto it=_objects.begin();
    while(it != _objects.end())
    {
        if ((*it).getState() == DEAD)
        {
            Packet packet = Packet::build(4, std::to_string((*it).getId()) + " " // 4 == DEAD
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
            if ((*it).getType() == "boss")
            {
                Packet packet = Packet::build(20, std::to_string((*it).getId()) + " " // 4 == DEAD
                                              + std::to_string((*it).getPositionX())
                                              + " " + std::to_string((*it).getPositionY()) + " ");
                if (_servUdp)
                    _servUdp->broadcast(packet);
            }
            it = _objects.erase(it);
            if (_servUdp)
                _servUdp->broadcast(packet);
        }
        else if ((*it).getType() == "player")
        {
            Packet packet = Packet::build(0, std::to_string((*it).getId()) + " " // 0 == POS
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
            if (_servUdp)
                _servUdp->broadcast(packet);
            ++it;
        }
        else if ((*it).getType() == "missilePlayer")
        {
            if ((*it).getPositionX() >= 1750 || checkShootCollisions(*it, 0/*(*it).getSizeX()*/, /*(*it).getSizeY())*/0))
            {
                Packet packet = Packet::build(2, std::to_string((*it).getId()) + " " // 2 == KILLMISSILEPLAYER
                                              + std::to_string((*it).getPositionX())
                                              + " " + std::to_string((*it).getPositionY()) + " ");
                it = _objects.erase(it);
                if (_servUdp)
                    _servUdp->broadcast(packet);
            }
            else
            {
                Packet packet = Packet::build(1, std::to_string((*it).getId()) + " " // 1 == POSMIISILEPLAYER
                                              + std::to_string((*it).getPositionX())
                                              + " " + std::to_string((*it).getPositionY()) + " ");
                if (_servUdp)
                    _servUdp->broadcast(packet);
                ++it;
            }
        }
        else if ((*it).getType() == "missileGreenShip")
        {
            if ((*it).getPositionX() <= -60 || checkShootCollisions(*it, -20, 80))
            {
                Packet packet = Packet::build(6, std::to_string((*it).getId()) + " " // 6 == POSMMISILEGREENKILL
                                              + std::to_string((*it).getPositionX())
                                              + " " + std::to_string((*it).getPositionY()) + " ");
                it = _objects.erase(it);
                if (_servUdp)
                    _servUdp->broadcast(packet);
            }
            else
            {
                Packet packet = Packet::build(5, std::to_string((*it).getId()) + " " // 5 == POSMMISILEGREEN
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
                if (_servUdp)
                    _servUdp->broadcast(packet);
                ++it;
            }
        }
	  else if ((*it).getType() == "missileBoss")
        {
            if ((*it).getPositionX() <= -60 || checkShootCollisions(*it, -20, 80))
            {
                Packet packet = Packet::build(13, std::to_string((*it).getId()) + " " // 6 == POSMMISILEGREENKILL
                                              + std::to_string((*it).getPositionX())
                                              + " " + std::to_string((*it).getPositionY()) + " ");
                it = _objects.erase(it);
                if (_servUdp)
                    _servUdp->broadcast(packet);
            }
            else
            {
                Packet packet = Packet::build(14, std::to_string((*it).getId()) + " " // 5 == POSMMISILEGREEN
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
                if (_servUdp)
                    _servUdp->broadcast(packet);
                ++it;
            }
        }
	else if ((*it).getType() == "missileRed")
        {
            if ((*it).getPositionX() <= -60 || checkShootCollisions(*it, -20, 80))
            {
                Packet packet = Packet::build(15, std::to_string((*it).getId()) + " " // 6 == POSMMISILEGREENKILL
                                              + std::to_string((*it).getPositionX())
                                              + " " + std::to_string((*it).getPositionY()) + " ");
                it = _objects.erase(it);
                if (_servUdp)
                    _servUdp->broadcast(packet);
            }
            else
            {
                Packet packet = Packet::build(16, std::to_string((*it).getId()) + " " // 5 == POSMMISILEGREEN
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
                if (_servUdp)
                    _servUdp->broadcast(packet);
                ++it;
            }
        }
	else if ((*it).getType() == "missileGreenShip1")
        {
            if ((*it).getPositionX() <= -60 || checkShootCollisions(*it, -20, 80))
            {
                Packet packet = Packet::build(17, std::to_string((*it).getId()) + " " // 6 == POSMMISILEGREENKILL
                                              + std::to_string((*it).getPositionX())
                                              + " " + std::to_string((*it).getPositionY()) + " ");
                it = _objects.erase(it);
                if (_servUdp)
                    _servUdp->broadcast(packet);
            }
            else
            {
                Packet packet = Packet::build(18, std::to_string((*it).getId()) + " " // 5 == POSMMISILEGREEN
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
                if (_servUdp)
                    _servUdp->broadcast(packet);
                ++it;
            }
        }

        else if ((*it).getType() == "greenShip" && (*it).getState() == SPAWNED)
        {
            Packet packet = Packet::build(3, std::to_string((*it).getId()) + " " // 3 == POSGREENSHIP
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
            if (_servUdp)
                _servUdp->broadcast(packet);
            ++it;
        }
        else if ((*it).getType() == "orangeShip" && (*it).getState() == SPAWNED)
        {
            Packet packet = Packet::build(9, std::to_string((*it).getId()) + " "
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
            if (_servUdp)
                _servUdp->broadcast(packet);
            ++it;
        }
	else if ((*it).getType() == "greenMonster" && (*it).getState() == SPAWNED)
	  {
            Packet packet = Packet::build(10, std::to_string((*it).getId()) + " "
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
            if (_servUdp)
	      _servUdp->broadcast(packet);
            ++it;
	  }

	else if ((*it).getType() == "greenLarve" && (*it).getState() == SPAWNED)
	  {
            Packet packet = Packet::build(11, std::to_string((*it).getId()) + " "
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
            if (_servUdp)
	      _servUdp->broadcast(packet);
            ++it;
	  }
	else if ((*it).getType() == "boss" && (*it).getState() == SPAWNED)
	  {
            Packet packet = Packet::build(12, std::to_string((*it).getId()) + " "
                                          + std::to_string((*it).getPositionX())
                                          + " " + std::to_string((*it).getPositionY()) + " ");
            if (_servUdp)
	      _servUdp->broadcast(packet);
            ++it;
	  }

        else
            ++it;
    }
}


void GameEngine::addMobs()
{
    Parser tmp(_room->getMap());
    std::cout << "MAP NAME:"  << _room->getMap()<< std::endl;
    //tmp.append(_room->getLevelName());
    std::list<GameObject*> &t = tmp.getObjectList();

    for (auto it=t.begin(); it != t.end(); ++it)
    {
        (*it)->setPositionX(1700);
        (*it)->setPositionY(500);
	(*it)->setState(WAITING);
        std::cout <<"type2: " << (*it)->getType() << std::endl;
        std::cout << "spawn: " << (*it)->getSpawn() << std::endl;
        _objects.push_back(*(*it));
    }
}

void GameEngine::createPlayers(int const nb)
{
    GameObject player;
    
    for (int i=0; i<nb; ++i)
    {
        player.setPositionX(i * 200);
        player.setPositionY(i * 200);
        player.setType("player");
        player.setId(i);
        player.setHP(25);
	player.setSize(80, 20);
	//player.setMissileSize(50, -20);
        _objects.push_back(player);
    }
}

void GameEngine::checkActions()
{
    auto mutex = _servUdp->getMutex();
    mutex->lock();
    Packet *action;
    while (_servUdp && (action = _servUdp->getUdpAction()))
    {
        if (action->getType() == 0)
        {
            movePlayer(action);
        }
        else if (action->getType() == 1)
        {
            playerShoot(action);
        }
        else if (action->getType() == 2)
        {
            playerLeave(action);
        }
        else if (action->getType() == 3)
        {
            activateStrenght(action);
        }
    }
    mutex->unlock();
}

GameObject& GameEngine::getObjectById(int const id)
{
    for (unsigned int i=0; i<_objects.size(); ++i)
    {
        if (id == _objects[i].getId())
            return (_objects[i]);
    }
    throw std::runtime_error("no object with this id");
}

void GameEngine::movePlayer(Packet *action)
{
    auto data = action->getData();
    std::string dataStr(reinterpret_cast<char *>(Packet::toBuf(data)));
    std::stringstream tmp(dataStr);
    int id;
    float tmpx;
    float tmpy;
    tmp >> id;
    tmp >> tmpx;
    tmp >> tmpy;
    try {
        GameObject& player = getObjectById(id);
        player.setPositionX(tmpx);
        player.setPositionY(tmpy);
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void GameEngine::playerShoot(Packet *action)
{
    auto data = action->getData();
    std::string dataStr(reinterpret_cast<char *>(Packet::toBuf(data)));
    std::stringstream tmp(dataStr);
    int id;
    float tmpx;
    float tmpy;
    tmp >> id;
    tmp >> tmpx;
    tmp >> tmpy;
    try {
        GameObject shot;
        shot.setPositionY(tmpy);
        shot.setPositionX(tmpx + 30);
        shot.setId(shotId++);
        shot.setOwner(id);
        shot.setSpeed(10);
        shot.setType("missilePlayer");
        shot.setState(SPAWNED);
        shot.setPath(1800, tmpy);
	//shot.setMissileSize(_objects[i].getMissileSizeX(), _objects[i].getMissileSizeY());
        _objects.push_back(shot);
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void GameEngine::playerLeave(Packet *action)
{
}

void GameEngine::activateStrenght(Packet *action)
{
}

void GameEngine::setServerUdp(IServer* serv)
{
    _servUdp = serv;
}

/*
 * Master en requete sur un niveau
 * lecture du niveau scripté demandé
 * chargement des objects
 * lancement de la boucle de jeu
 * {
 * action
 * check collision 
 * retour des informations user + actualité des objets
 * }
 * retour des informations score
 *
 *  
 * instanciation des objects
 * class de score <-- cintia
 * system de collision complet (vie, collision partielle, fratricide...) <--- sophie
 * lecture des actions
 */
