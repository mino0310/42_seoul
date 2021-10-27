# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 03:30:54 by minhkim           #+#    #+#              #
#    Updated: 2021/10/28 03:30:55 by minhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = philo.c	\
	validation.c	\
	init.c	\
	utils.c	\
	routine.c	\
	print.c	\
	finish.c

OBJ :=  $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) -c $(CFLAGS) $(SRC)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	
		make fclean
		make all
