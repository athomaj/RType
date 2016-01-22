#ifndef _ROOM_PAGE
# define _ROOM_PAGE

#include <iostream>
#include <string>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "MouseOnBox.hh"
#include "WriteInBox.hh"
#include "NetworkEvent.hh"

#include "IMenu.h"
# define MAX_TXT_ROOM 5

class RoomPage
{
public:
  RoomPage(int, int, NetworkEvent &);
  ~RoomPage();
  void 	drawBackGround(sf::RenderWindow &window, bool);
  void 	mousePositionBox(sf::RenderWindow &, bool);
   void	writeCharacter(char c);
   bool checkBack();
   void	restart();
   void	addListRoom(const std::string &roomName, int const nb, int const);
   void addPlayerToRoom();
   void addPlayerToRoom(const std::string &roomName);
   void removePlayerFromRoom();
   void removePlayerFromRoom(const std::string &roomName);
   bool checkRoomFull();
  void addPlayerName(const std::string &);
  
private:
  int		width;
  int		height;
  sf::Mouse mouse;


  sf::RectangleShape rectName;
  sf::RectangleShape currentRoom;
  sf::Vector2f writeNamePos;
  std::string	currentFocus;
  std::string	currentFocusRoom;
  std::string	prevFocusRoom;
  sf::Vector2f defaultPos;
  sf::Font fontRoom;
  sf::Font fontBasic;
  sf::Text textRoom[MAX_TXT_ROOM];
  sf::Sprite roomBack;
  sf::Sprite createButton;
  sf::Sprite joinButton;
  sf::Sprite backButton;
  bool		back;
  int		nbPlayerInRoom;

  std::map<std::string, MouseOnBox *> mouseBox;
    std::map<std::string, WriteInBox *> writeBox;
  //  sf::Sprite okButton;
    std::map<MouseOnBox *, WriteInBox *>	roomList;
    bool	roomFull;
    NetworkEvent& netEvent;
};

#endif
