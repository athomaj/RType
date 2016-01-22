##
## Makefile for Nibbler in /home/ferrei_e/cpp_nibbler
## 
## Made by Ferreira Cintia
## Login   <ferrei_e@epitech.net>
## 
## Started on  Wed Mar 11 16:04:57 2015 Ferreira Cintia
## Last update Tue Dec 22 15:37:20 2015 Timothy Burdairon
##

SRC=		main.cpp	\
		menu.cpp	\
		Loader.cpp	\
		menuWindow.cpp	\
		MouseOnBox.cpp	\
		LinuxWindow.cpp	\
		GameEngine.cpp	\
		Animation.cpp	\
		GameTime.cpp	\
		GameObject.cpp	\
		Parsing.cpp	\
		Timer.cpp	\
		Audio.cpp	\
		Score.cpp	\
		ConnectionPage.cpp \
		RoomPage.cpp	\
		LevelPage.cpp	\
		WriteInBox.cpp	\
		OptionPage.cpp	\
		ScorePage.cpp	\
		DeadPage.cpp	\
		MapParsing.cpp	\
		waitingPage.cpp	\
		EndPage.cpp	\
		WindowsWindow.cpp	\
		../Server/Network/ClientRType/ClientRType/AClient.cpp	\
		../Server/Network/ClientRType/ClientRType/ClientTCP.cpp	\
		../Server/Network/ClientRType/ClientRType/ClientUDP.cpp	\
		../Server/Network/ClientRType/ManageAction.cpp		\
		../Server/Network/ClientRType/Mutex.cpp		\
		../Server/Network/ClientRType/NetworkEvent.cpp		\
		../Server/Network/ClientRType/Packet.cpp		\
		../Server/Network/ClientRType/Thread.cpp		\
		../Server/Network/ServerRType/ServerRType/circular_buffer.cpp \
		../Server/Network/ServerRType/ServerRType/TCPSocket.cpp \
		../Server/Network/ServerRType/ServerRType/UDPSocket.cpp \
		../Server/Network/ServerRType/ServerRType/ASocket.cpp \


NAME=		sfmlt

CC=		g++

RM=		rm -f

OBJ=		$(SRC:.cpp=.o)

INCLUDE= -I../Server/Network/ServerRType/ServerRType -I../Server/Network/ServerRType -I../Server/GameEngine -I../Server/GameObject -I../Server/Parser -I../Server/Network/ClientRType/ClientRType -I./ -I../Server/Network/ClientRType

CXXFLAGS=	-Wall -Wextra $(INCLUDE) -std=c++11 -g3

LIB=		-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -pthread

LIBRARY=	library/library

all:	$(NAME) 

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

$(LIBRARY):
	make -C library

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
