//
// GameEngine.cpp for  in /home/burdai_t/rendu/rtype/ClientGraphic
// 
// Made by Timothy Burdairon
// Login   <burdai_t@epitech.net>
// 
// Started on  Mon Nov 30 12:30:58 2015 Timothy Burdairon
// Last update Sun Jan  3 23:22:43 2016 Timothy Burdairon
//

#include "ClientUDP.hpp"
#include "GameEngine.hh"

GameEngine::GameEngine(IWindow *_window, std::string const& ip, int const port, int const playerId)
{
	window = _window;
//	player = window->getPlayer();
    if (playerId != -1)
    {
        player = window->getObject("player", playerId - 48);
        std::cout << "initId: " << playerId - 48 << std::endl;
        window->setHp("player", playerId - 48, 5);
        window->setMainPlayer(player);
    }
	sound = new Audio("music.wav");
    _ip = ip;
    _port = port;
    _udpClient = NULL;
	window->setKeyRepeatEnabled(true);
	y = 0;
	x = 0;
	left = true;
	right = true;
	down = true;
	up = true;
    _id = playerId - 48;
    shootTime.setTimer(0.25f);
}

GameEngine::~GameEngine()
{

}

IClient* GameEngine::getUdpClient()
{
    return _udpClient;
}

void	GameEngine::setDefaultSettings()
{
	window->setVerticalSyncEnabled(true);
}

void	GameEngine::playerMove()
{
	 if ((window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::Up)) && up == true)
		  {
		 	 x += 0;
		 	 y += (-player->getDistanceMove());
		 	 up = false;
		  }
	 else if (window->eventTrigger(sf::Event::KeyReleased) && window->keyTrigger(sf::Keyboard::Up))
	 {
		 y -= (-player->getDistanceMove());
		 up = true;
	 }

	 if ((window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::Down)) && down == true)
		  {
//              std::cout << std::to_string(player->getPosition().x) << " " << player->getPosition().x << std::endl;
		 	 x += 0;
		 	 y += (player->getDistanceMove());
		 	 down = false;
		  }
	 else if (window->eventTrigger(sf::Event::KeyReleased) && window->keyTrigger(sf::Keyboard::Down))
	 {
		 y -= (player->getDistanceMove());
//         std::cout << y << std::endl;
		 down = true;
	 }

	 if ((window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::Left)) && left == true)
		  {
		 	 x += - player->getDistanceMove();
		 	 y += 0;
		 	 left = false;
		  }
	 else if (window->eventTrigger(sf::Event::KeyReleased) && window->keyTrigger(sf::Keyboard::Left))
	 {
		 x -= -player->getDistanceMove();
		 left = true;
	 }

	 if ((window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::Right)) && right == true)
		  {
		 	 x +=  player->getDistanceMove();
		 	 y += 0;
		 	 right = false;
		  }
	 else if (window->eventTrigger(sf::Event::KeyReleased) && window->keyTrigger(sf::Keyboard::Right))
	 {
		 x -= player->getDistanceMove();
		 right = true;
	 }

	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && shootTime.isTime())
		{
//            std::cout << "sending shoot packet" << std::endl;
		 	 static int  nb = 0;

            //		 	 window->fireWeapon(_id - 48, "missilePlayer", nb + 10);
//		 	 window->getObject("missilePlayer", nb + 10)->setPositionAnim(player->getPosition().x, player->getPosition().y);
//			 window->addScoreToPlayer(_id - 48, 10);
            
            Packet packet = Packet::build(1, std::to_string(_id) + " "
                                          + std::to_string(player->getPosition().x)
                                          + " " + std::to_string(player->getPosition().y)
                                          + " " + std::to_string(nb) + " ");
            nb = (nb + 1) % 50;
            _udpClient->getMutex()->lock();
            reinterpret_cast<ASocket *>(_udpClient->getSocket())->addData<Packet>(packet, &serPacket);
            _udpClient->getMutex()->unlock();
		}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
		 	 player->killAnimation();
		}
	 /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
		  window->fireWeapon("greenShip", 0, "missileGreenShip", true);
		}*/
}


bool	GameEngine::checkEvent()
{
	while (window->windowEventTrigger() == true)
	{
		if (window->eventTrigger(sf::Event::Closed) ||
				(window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::Escape)))
		{
			sound->stop();
			return (false);
		}
	/*  if (window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::Space))
	  {
		  window->SwitchGameOrientation();
	  }*/
	  if (window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::N))
	  {
		  window->getObject("missileRed", 89);
		  window->setHp("missileRed", 89, 50);
		  window->setPosition(89, 1060,400);
	  }
	  if (window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::X))
	  {
		  window->setPosition(89, 50, 100);
	  }
	  if (window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::Z))
	  {
		  static int a = 50;
		   a = a - 10;
		   window->setHp("greenShip", 89, a);
		   if (a < 10)
			   a = 40;
	  }
	  if (window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::W))
	  {
		  window->setPosition(89, 1600, 1000);
	  }
	  if (window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::B))
	  {
	  		  player->selfImpact();
	  }
	  if (window->eventTrigger(sf::Event::KeyPressed) && window->keyTrigger(sf::Keyboard::F))
	  {
		  	  //window->getObject("greenShip", 114);
		  	  window->setForce(1, "force", 114);
	  		  //player->selfImpact();
	  }

	  playerMove();
	}
	if (player->getHp() == 0)
	{
		sound->stop();
		std::cout << "eNd GAmE" << std::endl;
		return (false);
	}
	if (player->getStatusDeleteAnimation() == true)
	{
		player->restartAnimation();
		player->setHp(player->getHp() - 1);
	}
	return (true);
}

std::string& GameEngine::getIp()
{
    return _ip;
}

int GameEngine::getPort() const
{
    return _port;
}


void* launchUdpClient(void* param)
{
    GameEngine* gameEngine = reinterpret_cast<GameEngine*>(param);
    
    gameEngine->getUdpClient()->run(gameEngine->getIp(), gameEngine->getPort());
    return (NULL);
}

bool GameEngine::networkAction()
{
    try
    {
        Animation* tmpPlayer;
        Packet *packet;
        while (1)
        {
            _udpClient->getMutex()->lock();
            packet = reinterpret_cast<ASocket *>(_udpClient->getSocket())->getData<Packet *>(&unserPacket);
            _udpClient->getMutex()->unlock();
            auto data = packet->getData();
            std::string dataStr(reinterpret_cast<char *>(Packet::toBuf(data)));
            std::stringstream tmp(dataStr);
            int id;
            float tmpx;
            float tmpy;
            tmp >> id;
            tmp >> tmpx;
            tmp >> tmpy;
            if (packet->getType() == 0)
            {
                if (id != _id)
                {
//                    std::cout << "id " << id << " "<< _id <<  std::endl;
                    tmpPlayer = window->getObject("player", id);
                    tmpPlayer->setNextPosition(tmpx, tmpy);
                }
            }
            else if (packet->getType() == 1)
            {
                window->getObject("missilePlayer", id)->setPositionAnim(tmpx, tmpy);
            }
            else if (packet->getType() == 2)
            {
                window->getObject("missilePlayer", id)->killAnimation();
            }
            else if (packet->getType() == 3)
            {
                Animation* mob = window->getObject("greenShip", id);
                mob->setPositionAnim(tmpx, tmpy);
            }
            else if (packet->getType() == 4)
            {
                Animation* toDel = window->getAnimation(id);
                if (toDel)
                    toDel->killAnimation();
            }
            else if (packet->getType() == 5)
            {
                window->getObject("missileGreenShip", id)->setPositionAnim(tmpx, tmpy);
            }
            else if (packet->getType() == 6)
            {
//                std::cout << "got Hit" << std::endl;
                window->getObject("missileGreenShip", id)->killAnimation();
            }
            else if (packet->getType() == 7)
            {
                std::cout << "id: " << id << std::endl;
                if (id >= 0 && id <= 3)
                    window->getObject("player", id)->setHp(window->getObject("player", id)->getHp() - 1);
                else
                    window->getAnimation(id)->setHp(window->getAnimation(id)->getHp() - 1);
            }
            else if (packet->getType() == 8)
            {
                
//                return false;
            }
            else if (packet->getType() == 9)
            {
                Animation* mob = window->getObject("orangeShip", id);
                mob->setPositionAnim(tmpx, tmpy);
            }
            else if (packet->getType() == 10)
            {
                Animation* mob = window->getObject("greenMonster", id);
                mob->setPositionAnim(tmpx, tmpy);
            }
            else if (packet->getType() == 11)
            {
	      std::cout << "hello" << std::endl;
                Animation* mob = window->getObject("greenLarve", id);
                mob->setPositionAnim(tmpx, tmpy);
            }
            else if (packet->getType() == 12)
            {
                Animation* mob = window->getObject("boss", id);
                mob->setPositionAnim(tmpx, tmpy);
            }



            else if (packet->getType() == 14)
                {
            	std::cout << "azeza" << std::endl;
                    window->getObject("missileBoss", id)->setPositionAnim(tmpx, tmpy);
                }
                else if (packet->getType() == 13)
                {
                	std::cout << "azeza!!" << std::endl;

    //                std::cout << "got Hit" << std::endl;
                    window->getObject("missileBoss", id)->killAnimation();
                }
                else if (packet->getType() == 16)
                    {
                        window->getObject("missileRed", id)->setPositionAnim(tmpx, tmpy);
                    }
                    else if (packet->getType() == 15)
                    {
        //                std::cout << "got Hit" << std::endl;
                        window->getObject("missileRed", id)->killAnimation();
                    }
                    else if (packet->getType() == 18)
                    {
                            window->getObject("missileGreenShip1", id)->setPositionAnim(tmpx, tmpy);
                        }
                        else if (packet->getType() == 17)
                        {
            //                std::cout << "got Hit" << std::endl;
                            window->getObject("missileGreenShip1", id)->killAnimation();
                        }
            else if (packet->getType() == 20)
            {
                return false;
            }
        }
    }
    catch (std::runtime_error const& err)
    {
        _udpClient->getMutex()->unlock();
    }
    return true;
}


void GameEngine::playGame()
{
    _networkThread = new Thread();
    _udpClient = new ClientUDP(_ip, _port);
    _networkThread->create(reinterpret_cast<void*>(&launchUdpClient), this);
    float previousX = 0;
    float previousY = 0;
    
    Packet packet = Packet::build(11, std::to_string(_id) + " 0 0");
    _udpClient->getMutex()->lock();
    reinterpret_cast<ASocket *>(_udpClient->getSocket())->addData<Packet>(packet, &serPacket);
    _udpClient->getMutex()->unlock();
    std::cout << _ip << " " <<_port << std::endl;
	sound->play();
	while (window->isOpen())
	{
        if (checkEvent() == false)
            return ;
        if (x != 0 || y != 0 || player->getPosition().x + x != previousX ||
            player->getPosition().y + y != previousY)
        {
//            if (player->getPosition().x + x < 0)
//                x = 0;
//            if (player->getPosition().x + x > 1700)
//                x = 0;
//            if (player->getPosition().y + y < 0)
//                y = 0;
//            if (player->getPosition().y + y > 1056)
//                y = 0;
            Packet packet = Packet::build(0, std::to_string(_id) + " "
                                            + std::to_string(player->getPosition().x + x)
                                              + " " + std::to_string(player->getPosition().y + y) + " ");
            _udpClient->getMutex()->lock();
            reinterpret_cast<ASocket *>(_udpClient->getSocket())->addData<Packet>(packet, &serPacket);
            _udpClient->getMutex()->unlock();
            previousX = player->getPosition().x + x;
            previousY = player->getPosition().y + y;
            player->setNextPosition(player->getPosition().x + x, player->getPosition().y + y);
        }
        if (networkAction() == false)
            return ;
		window->clear();
		window->display();
//        usleep(1000);
	}
    _networkThread->exit();
}
