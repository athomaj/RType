SRC=	main.cpp	\
		ServerRType/ActionManager.cpp	\
		ServerRType/AServer.cpp			\
		ServerRType/ASocket.cpp		\
		ServerRType/circular_buffer.cpp		\
		ServerRType/GameManager.cpp			\
		ServerRType/Mutex.cpp				\
		ServerRType/Packet.cpp				\
		ServerRType/Room.cpp				\
		ServerRType/ServerTCP.cpp			\
		ServerRType/ServerUDP.cpp			\
		ServerRType/TCPSocket.cpp			\
		ServerRType/Thread.cpp				\
		ServerRType/ThreadCond.cpp			\
		ServerRType/ThreadPool.cpp			\
		ServerRType/UDPSocket.cpp			\
		../../GameLoading/GameObject.cpp 	\
		../../GameLoading/Parser.cpp		\
		../../Parser/Entity/Entity.cpp		\
		../../Parser/Entity/Level.cpp		\
		../../Parser/Entity/Vessel.cpp		\
		../../Gameobject/CrossLoader.cpp	\
		../../GameEngine/GameEngine.cpp	\


OBJ= $(SRC:.cpp=.o)

NAME=	server

CXXFLAGS=	-I./ -I./ServerRType -I../../GameLoading/ -I../../Parser/Entity/ -I../../Gameobject/ -I../../GameEngine/ -std=c++11


all:		$(NAME)

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(OBJ) -pthread -ldl

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
