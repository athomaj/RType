#include "RoomPage.hh"

RoomPage::RoomPage(int _width, int _height, NetworkEvent &_netEvent) : netEvent(_netEvent)
{

  width = _width;
  height = _height;
  sf::Texture *textureRoom = new sf::Texture;
  if (!textureRoom->loadFromFile("resources/rooms.png"))
    std::cerr << "rooms.png is not found" << std::endl;
  roomBack.setTexture(*textureRoom);
  roomBack.setColor(sf::Color(255, 255, 255, 200));
  defaultPos.x = 0.17 * width;
  defaultPos.y = 0.15 * height;
  roomBack.setPosition(defaultPos);
  
  sf::Texture *textureButtonCreate = new sf::Texture();
  if (!textureButtonCreate->loadFromFile("resources/create_button.png"))
    std::cerr << "create_button.png is not found" << std::endl;
  createButton.setTexture(*textureButtonCreate);
  createButton.setScale(1.5f, 1.5f);
  createButton.setPosition(sf::Vector2f((float)width * 0.65f, (float)height/1.8f));

  sf::Vector2f buttonPos(createButton.getPosition().x , createButton.getPosition().y);
   sf::Vector2f  buttonSize(textureButtonCreate->getSize().x * 1.5f, textureButtonCreate->getSize().y * 1.5f);
   mouseBox["create"] = new MouseOnBox(NULL, buttonPos, buttonSize, "create");



  sf::Texture *textureButtonBack = new sf::Texture();
  if (!textureButtonBack->loadFromFile("resources/back_button.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  backButton.setTexture(*textureButtonBack);
  backButton.setPosition(sf::Vector2f((float)width * 0.2f, (float)height * 0.75));
  backButton.setScale(1.5f, 1.5f);
  
  sf::Vector2f backPos(backButton.getPosition().x , backButton.getPosition().y);
  sf::Vector2f backSize(textureButtonBack->getSize().x * 1.5f, textureButtonBack->getSize().y * 1.5f);
  mouseBox["back"] = new MouseOnBox(NULL, backPos, backSize, "back");


  sf::Texture *textureButtonJoin = new sf::Texture();
  if (!textureButtonJoin->loadFromFile("resources/join_button.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  joinButton.setTexture(*textureButtonJoin);
  joinButton.setScale(1.5f, 1.5f);
  joinButton.setPosition(sf::Vector2f((float)width *0.65f, (float)height/1.6f));

  sf::Vector2f joinPos(joinButton.getPosition().x , joinButton.getPosition().y);
  sf::Vector2f joinSize(textureButtonJoin->getSize().x * 1.5f,  textureButtonJoin->getSize().y * 1.5f);
  mouseBox["join"] = new MouseOnBox(NULL, joinPos, joinSize, "join");

  /*  sf::Texture *textureButtonOk = new sf::Texture();
  if (!textureButtonOk->loadFromFile("ok_button.png"))
    std::cerr << "back_button.png is not found" << std::endl;
  okButton.setTexture(*textureButtonOk);
  okButton.setScale(1.5f, 1.5f);*/
  back = false;
  roomFull = false;
  currentFocus = "name" ;
  if (!fontRoom.loadFromFile("imagine_font.ttf"))
    {
      std::cerr << "Typo not found" << std::endl;
    }
  textRoom[0].setFont(fontRoom);
  textRoom[0].setColor(sf::Color::White);
  textRoom[0].setString("List of rooms");
  textRoom[0].setPosition(sf::Vector2f((float)width * 0.23f, (float)height/3.5));


  textRoom[1].setPosition(sf::Vector2f((float)width *0.65f , (float)height /3.5));
  textRoom[1].setFont(fontRoom);
  textRoom[1].setColor(sf::Color::White);
  textRoom[1].setString("Name");
  if (!fontBasic.loadFromFile("resources/sansation.ttf"))
     {
       std::cerr << "Typo not found" << std::endl;
     }

  textRoom[2].setPosition(sf::Vector2f((float)width *0.65f , (float)height /2.5));
  textRoom[2].setFont(fontBasic);
  textRoom[2].setColor(sf::Color::White);
  textRoom[2].setString("+");
  textRoom[2].setCharacterSize(60);
  //textRoom[2].setScale(1.f, 1.f);
  sf::Vector2f t2(textRoom[2].getPosition().x , textRoom[2].getPosition().y + 0.03f * (float)height);
  sf::Vector2f  sizet((float)width *0.026f, (float)height *0.026f);
  mouseBox["+"] = new MouseOnBox(NULL, t2, sizet, "+");

  prevFocusRoom = "";
  textRoom[3].setPosition(sf::Vector2f((float)width *0.75f , (float)height /2.5));
  textRoom[3].setFont(fontBasic);
  textRoom[3].setColor(sf::Color::White);
  textRoom[3].setString("-");
  textRoom[3].setCharacterSize(60);

  t2.x = textRoom[3].getPosition().x;
  t2.y =  textRoom[3].getPosition().y  + 0.03f * (float)height;
 // sizet.x = (float)width *0.05f;
  //sizet.y = (float)height *0.05f;
  mouseBox["-"] = new MouseOnBox(NULL, t2, sizet, "-");


  textRoom[4].setPosition(sf::Vector2f((float)width *0.7f , (float)height /2.5));
  textRoom[4].setFont(fontBasic);
  textRoom[4].setColor(sf::Color::White);
  textRoom[4].setString("1");
  textRoom[4].setCharacterSize(60);

  //textRoom[4].setScale(0.8f, 0.8f);
//    addPlayerName("juju");

  rectName.setFillColor(sf::Color(255,255,255,122));
  writeNamePos.x = 0.18 * width;
  writeNamePos.y = 0.05 * height;
  this->rectName.setSize(writeNamePos);
  this->rectName.setPosition(textRoom[1].getPosition().x, textRoom[1].getPosition().y + 0.05 * (float)height);
  sf::Vector2f rectPos = rectName.getPosition();
  mouseBox["name"] = new MouseOnBox(NULL, rectPos, writeNamePos, "name");
  writeBox["name"] = new WriteInBox(rectPos, 40, 11);
  nbPlayerInRoom = 1;
  addListRoom("toto", 4, 0);
//  addListRoom("titi", 2);
  currentRoom.setFillColor(sf::Color(255,255,255,122));
  sf::Vector2f currentRoomSize(0.376f * width, 0.03f * height);
  currentRoom.setSize(currentRoomSize);
}

RoomPage::~RoomPage()
{
  
}

void RoomPage::removePlayerFromRoom()
{
	if (currentFocus != "")
	{
		WriteInBox *tmpW = writeBox[prevFocusRoom];
		std::string tmpStr = tmpW->getText();
		std::stringstream str(tmpStr.c_str());
		int i;
		int nb;
		str >> i;
		str.ignore(1);
		str >> nb;
		if (i > 0)
		{
			netEvent.leaveRoom(prevFocusRoom,netEvent.getHostName());
			std::stringstream sstr("");
			sstr << i - 1;
			sstr << "/";
			sstr << nb;
			tmpW->clear();
			tmpW->addString(sstr.str());
		}
	}
}

void RoomPage::removePlayerFromRoom(const std::string &roomName)
{
	if (roomName != "")
	{
		WriteInBox *tmpW = writeBox[roomName];
		std::string tmpStr = tmpW->getText();
		std::stringstream str(tmpStr.c_str());
		int i;
		int nb;
		str >> i;
		str.ignore(1);
		str >> nb;
		if (i > 0)
		{
			//netEvent.leaveRoom(roomName,netEvent.getHostName());
			std::stringstream sstr("");
			sstr << i - 1;
			sstr << "/";
			sstr << nb;
			tmpW->clear();
			tmpW->addString(sstr.str());
		}
	}
}


void RoomPage::addPlayerToRoom()
{
	if (currentFocus != "")
	{
		WriteInBox *tmpW = writeBox[currentFocusRoom];
		std::string tmpStr = tmpW->getText();
		std::stringstream str(tmpStr.c_str());
		prevFocusRoom = currentFocusRoom;
		int i;
		int nb;
		str >> i;
		str.ignore(1);
		str >> nb;
		if (i < nb)
		{
			netEvent.joinRoom(currentFocusRoom, netEvent.getHostName());
//			std::stringstream sstr("");
//			sstr << i + 1;
//			sstr << "/";
//			sstr << nb;
//			tmpW->clear();
//			tmpW->addString(sstr.str());
//			if (i + 1 == nb)
//			{
//				/* While server not working */
//				netEvent.menuLevel();
//
//				roomFull = true;
//			}
		}
	}
}

void RoomPage::addPlayerToRoom(const std::string &roomName)
{
	if (roomName != "")
	{
		prevFocusRoom = roomName;
		WriteInBox *tmpW = writeBox[roomName];
		std::string tmpStr = tmpW->getText();
		std::stringstream str(tmpStr.c_str());
		int i;
		int nb;
		str >> i;
		str.ignore(1);
		str >> nb;
		if (i < nb)
		{
			std::stringstream sstr("");
			sstr << i + 1;
			sstr << "/";
			sstr << nb;
			tmpW->clear();
			tmpW->addString(sstr.str());
//			if (i + 1 == nb)
//			{
//				/* While server not working */
//				netEvent.menuLevel();
//
//				roomFull = true;
//			}
		}
	}
}


void RoomPage::addListRoom(const std::string &roomName, int const maxPlayer, int const nbPlayer)
{
    std::stringstream str("");
    
    for (auto it=roomList.begin(); it != roomList.end(); ++it)
    {
        if (it->first->getName() == roomName)
        {
            if (nbPlayer == 0)
            {
                writeBox.erase(roomName);
                roomList.erase(it);
                return ;
            }
            str << nbPlayer;
            str << "/";
            str << maxPlayer;
            writeBox[roomName]->clear();
            writeBox[roomName]->addString(str.str());
            return ;
        }
    }
	sf::Vector2f sizeLine(0.376f * width, 0.03f * height);
	sf::Vector2f pos(textRoom[0].getPosition().x , (float)roomList.size() * 0.03f * (float)height + (textRoom[0].getPosition().y  * 1.15));

	MouseOnBox *tmp =  new MouseOnBox(NULL, pos ,sizeLine, roomName);
	WriteInBox *tmpW = new  WriteInBox (pos, 20, 20);

	tmpW->addString(roomName);
	roomList[tmp] = tmpW;
	currentFocusRoom = roomName;
	currentRoom.setPosition(pos);
	pos.x += 0.35 * (float)width;
	writeBox[roomName] = new WriteInBox(pos, 20, 11);
	str << nbPlayer;
	str << "/";
	str << maxPlayer;
//	if (nb == 1)
//	{
//		/* While server not working */
//			netEvent.menuLevel();
//		std::cout << "hello 1" << std::endl;
//		roomFull = true;
//	}
	writeBox[roomName]->addString(str.str());
}


void RoomPage::mousePositionBox(sf::RenderWindow &window, bool mouseClicked)
{
	for (std::map<std::string, MouseOnBox*>::iterator it = mouseBox.begin(); it != mouseBox.end(); ++it)
	{
		sf::Vector2<int> tmpV;

		tmpV.x = mouse.getPosition(window).x;
		tmpV.y = mouse.getPosition(window).y;
		if ((*it).second->isOnObject(tmpV) == true)
		{
		    	//  menu->setSpriteSpaceShip(*((*it)->getNextSprite()));
			if (mouseClicked == true)
			{
				std::string  tmp = (*it).first;
				currentFocus = tmp;
			if (currentFocus.find("name") != std::string::npos && mouseClicked)
					rectName.setFillColor(sf::Color::White);
				else if (mouseClicked)
					rectName.setFillColor(sf::Color(255,255,255,122));
				if (currentFocus.find("+") != std::string::npos && mouseClicked)
				{
					if (nbPlayerInRoom < 4)
						++nbPlayerInRoom;
				}
				if (currentFocus.find("-") != std::string::npos && mouseClicked)
				{
					if (nbPlayerInRoom > 1)
							--nbPlayerInRoom;
				}
				if (currentFocus.find("create") != std::string::npos && mouseClicked)
					{
						if (writeBox["name"]->getText() != "" && writeBox.find(writeBox["name"]->getText()) == writeBox.end())
						{
//							addListRoom(writeBox["name"]->getText(), nbPlayerInRoom);
                            netEvent.newRoom(writeBox["name"]->getText(), nbPlayerInRoom, netEvent.getHostName());
							nbPlayerInRoom = 1;
//							removePlayerFromRoom(prevFocusRoom);
							prevFocusRoom = writeBox["name"]->getText();
							writeBox["name"]->clear();
							currentFocus = "";
						}
					}
				if (currentFocus.find("join") != std::string::npos && mouseClicked)
				{
//					removePlayerFromRoom(prevFocusRoom);
					addPlayerToRoom();
					currentFocus = "";
				}
				if (currentFocus.find("back") != std::string::npos && mouseClicked)
				{
					std::cout << "back !!" << std::endl;
					//back = true;
					netEvent.menuConnection();
				}

				std::stringstream sstr;
				sstr << nbPlayerInRoom;
				textRoom[4].setString(sstr.str());
			}
		}
	}

	for (std::map<MouseOnBox*, WriteInBox*>::iterator it = roomList.begin(); it != roomList.end(); ++it)
		{
			sf::Vector2<int> tmpV;

			tmpV.x = mouse.getPosition(window).x;
			tmpV.y = mouse.getPosition(window).y;
			if ((*it).first->isOnObject(tmpV) == true)
			{
			    	//  menu->setSpriteSpaceShip(*((*it)->getNextSprite()));
				if (mouseClicked == true)
				{
					std::string  tmp = (*it).first->getName();
					//currentFocus = tmp;
					currentFocusRoom = tmp;
					sf::Vector2f sizetmp;
					sizetmp.x =  (*it).first->getPosition().x;
					sizetmp.y =  (*it).first->getPosition().y;
					currentRoom.setPosition(sizetmp);
					std::cout << tmp << std::endl;
				}
			}
		}
}

void RoomPage::restart()
{
	back = false;
	currentFocus = "name";
	roomFull = false;
	for (std::map<std::string,  WriteInBox*>::iterator it = writeBox.begin(); it \
	       != writeBox.end(); ++it)
	  {
	    (*it).second->clear();
	  }
//    roomList.clear();
}

bool	RoomPage::checkBack()
{
	return (back);
}

bool	RoomPage::checkRoomFull()
{
	return (roomFull);
}

void	RoomPage::writeCharacter(char c)
{
	std::cout << currentFocus << std::endl;
	if (currentFocus.size() > 1)
		writeBox[currentFocus]->addCharacter(c);
}

void RoomPage::addPlayerName(const std::string &playerName)
{
  sf::Vector2f pos(textRoom[0].getPosition().x - 0.048f * (float)width, textRoom[0].getPosition().y - 0.1f * (float)height);
  writeBox[playerName] = new WriteInBox(pos, 50, 11);
  writeBox[playerName]->addString(playerName);
  }

void RoomPage::drawBackGround(sf::RenderWindow &window, bool mouseClicked)
{
  window.draw(roomBack);
  window.draw(createButton);
  window.draw(backButton);
  // window.draw(okButton);
  window.draw(joinButton);
  window.draw(rectName);
  window.draw(currentRoom);
  mousePositionBox(window, mouseClicked);
  for(int i =0; i < MAX_TXT_ROOM; i++)
    {
      window.draw(textRoom[i]);
    }
  for (std::map<std::string, WriteInBox *>::iterator it = writeBox.begin() ; it != writeBox.end(); ++it)
  	{
  	  window.draw((*it).second->drawString());
  	}
  for (std::map<MouseOnBox *, WriteInBox *>::iterator it = roomList.begin() ; it != roomList.end(); ++it)
    {
    	  window.draw((*it).second->drawString());
    }
}
