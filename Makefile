# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 20:12:39 by pdonnie           #+#    #+#              #
#    Updated: 2019/07/31 14:42:23 by jbowen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCLUDES = "fillit.h"

SOURCE = fillit.c tetrimino.c check.c error.c grid.c

OBJECTS = fillit.o tetrimino.o check.o error.o grid.o

all : $(NAME)

$(NAME) : $(OBJECTS)
		gcc -Wall -Wextra -Werror $(OBJECTS) -o $(NAME)

%.o: %.c fillit.h
	gcc -Wall -Wextra -Werror -c $< -o $@

clean :
		/bin/rm -f $(OBJECTS)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all
