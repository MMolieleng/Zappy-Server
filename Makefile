# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoliele <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 13:12:05 by mmoliele          #+#    #+#              #
#*   Updated: 2017/07/16 01:24:59 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

FLAGS = -Wall -Werror
SERVERSRC = src/main.c\
			src/error.c

LIB	= -L libft/ -lft

INC	= -I libft/
INC	+= -I inc/


SERVER_OBJ = main.o\
			 error.o\

all:server
	make re -C libft

server:
	$(CC) $(FLAGS) -c $(SERVERSRC) $(INC)
	$(CC) $(FLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIB)

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER)

re:fclean all
