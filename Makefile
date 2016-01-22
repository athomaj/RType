SRCSERV= 	src/Server/main.cpp				\
		src/Server/Network/ActionManager.cpp	\
		src/Server/Network/AServer.cpp			\
		src/Server/Network/GameManager.cpp		\
		src/Server/Network/Room.cpp				\
		src/Server/Network/ServerTCP.cpp		\
		src/Server/Network/ServerUDP.cpp		\
		src/Tools/ASocket.cpp			\
		src/Tools/circular_buffer.cpp	\
		src/Tools/Mutex.cpp			\
		src/Tools/Packet.cpp			\
		src/Tools/TCPSocket.cpp		\
		src/Tools/Thread.cpp			\
		src/Tools/ThreadCond.cpp		\
		src/Tools/ThreadPool.cpp		\
		src/Tools/UDPSocket.cpp		\
		src/Server/GameEngine/GameEngine.cpp				\
		src/Server/GameObject/GameObject.cpp				\
		src/Server/GameObject/CrossLoader.cpp				\
		src/Server/Parser/Parser.cpp						\
		src/Server/Parser/Scenario.cpp						\
		src/Server/Parser/Entity/Entity.cpp					\
		src/Server/Parser/Entity/Level.cpp					\
		src/Server/Parser/Entity/Vessel.cpp					\

SRCCLIENT= src/Client/main.cpp	\
		src/Client/Graphic/menu.cpp	\
		src/Client/Graphic/Loader.cpp	\
		src/Client/Graphic/menuWindow.cpp	\
		src/Client/Graphic/MouseOnBox.cpp	\
		src/Client/Graphic/LinuxWindow.cpp	\
		src/Client/Graphic/GameEngine.cpp	\
		src/Client/Graphic/Animation.cpp	\
		src/Client/Graphic/GameTime.cpp	\
		src/Client/Graphic/GameObject.cpp	\
		src/Client/Graphic/Parsing.cpp	\
		src/Client/Graphic/Timer.cpp	\
		src/Client/Graphic/Audio.cpp	\
		src/Client/Graphic/Score.cpp	\
		src/Client/Graphic/ConnectionPage.cpp \
		src/Client/Graphic/RoomPage.cpp	\
		src/Client/Graphic/LevelPage.cpp	\
		src/Client/Graphic/WriteInBox.cpp	\
		src/Client/Graphic/OptionPage.cpp	\
		src/Client/Graphic/ScorePage.cpp	\
		src/Client/Graphic/DeadPage.cpp	\
		src/Client/Graphic/MapParsing.cpp	\
		src/Client/Graphic/waitingPage.cpp	\
		src/Client/Graphic/EndPage.cpp	\
		src/Client/Graphic/WindowsWindow.cpp	\
		src/Client/Graphic/Network/AClient.cpp	\
		src/Client/Graphic/Network/ClientTCP.cpp	\
		src/Client/Graphic/Network/ClientUDP.cpp	\
		src/Client/Graphic/Network/ManageAction.cpp		\
		src/Client/Graphic/Network/NetworkEvent.cpp		\
		src/Tools/Mutex.cpp		\
		src/Tools/Packet.cpp		\
		src/Tools/Thread.cpp		\
		src/Tools/circular_buffer.cpp \
		src/Tools/TCPSocket.cpp \
		src/Tools/UDPSocket.cpp \
		src/Tools/ASocket.cpp \



OBJSERV= $(SRCSERV:.cpp=.o)

OBJCLIENT= $(SRCCLIENT:.cpp=.o)


NAMESERV= serverRtype

NAMECLIENT= clientRtype


CXXFLAGS= -I./src/Server/Network -I./src/Tools -I./src/Server/GameObject -I./src/Server/GameEngine -I./src/Server/Parser

INCLUDECLIENT= -I./src/Client/Graphic -I./src/Client/Network -I./src/Tools


CXXFLAGS= -Wall -Wextra $(INCLUDE) -std=c++11


all: $(NAMESERV)

$(NAMESERV): $(OBJSERV)
			g++ $(OBJSERV) -o $(NAMESERV)

$(NAMECLIENT): $(OBJCLIENT)
			g++ $(OBJCLIENT) -o $(NAMECLIENT)	

clean:
	rm -f $(OBJSERV)

fclean:	clean
	rm -rf $(NAMESERV)

re:		fclean all