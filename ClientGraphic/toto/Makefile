##
## Makefile for Nibbler in /home/ferrei_e/cpp_nibbler
## 
## Made by Ferreira Cintia
## Login   <ferrei_e@epitech.net>
## 
## Started on  Wed Mar 11 16:04:57 2015 Ferreira Cintia
## Last update Wed Dec  9 13:42:27 2015 Timothy Burdairon
##

SRC=		main.cpp	\
		menu.cpp	\
		../Loader.cpp	\
		menuWindow.cpp	\
		MouseOnBox.cpp

NAME=		sfmlt

CC=		g++

RM=		rm -f

OBJ=		$(SRC:.cpp=.o)

CXXFLAGS=	-W -Wall -Werror -Wextra -g3

LIB=		-lsfml-graphics -lsfml-window -lsfml-system

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
