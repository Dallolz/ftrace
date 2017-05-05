##
## Makefile for makefile in /home/semon_l/rendu/PSU_2016_ftrace
## 
## Made by luc semon
## Login   <semon_l@epitech.net>
## 
## Started on  Mon May  1 10:27:31 2017 luc semon
## Last update Fri May  5 15:50:56 2017 luc semon
##

NAME	= ftrace

SRC	= main.c \
	  parser.c \
	  fork.c \
	  strace.c \
	  symbol.c \
	  ./sig/signaux.c \
	  symbol2.c

OBJ	= $(SRC:.c=.o)

CXX	= gcc -g

CFLAGS =  -lelf

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	 $(CXX) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
