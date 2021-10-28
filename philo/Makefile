# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 16:57:22 by jseo              #+#    #+#              #
#    Updated: 2021/10/28 10:40:57 by minhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# Color Variables
# =============================================================================

BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"

# =============================================================================
# Command Variables
# =============================================================================

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
CDEBUG		=	-fsanitize=address -g
RM			=	rm -f

# =============================================================================
# File Variables
# =============================================================================

NAME		=	philo
HEADER		=	./includes/
FOLDER		=	./srcs/
D_CTX		=	context/
D_FUNC		=	function/
D_UTIL		=	utility/
SRC_LIST	=	philo.c					\
				$(D_CTX)term.c			\
				$(D_CTX)thread.c		\
				$(D_FUNC)atoi.c		\
				$(D_FUNC)calloc.c		\
				$(D_FUNC)free.c		\
				$(D_FUNC)isdigit.c	\
				$(D_FUNC)isspace.c	\
				$(D_FUNC)memset.c		\
				$(D_FUNC)putchar.c	\
				$(D_FUNC)putendl.c	\
				$(D_FUNC)putnbr.c		\
				$(D_FUNC)putstr.c		\
				$(D_FUNC)strlen.c		\
				$(D_UTIL)chrono.c		\
				$(D_UTIL)console.c		\
				$(D_UTIL)resource.c		\
				$(D_UTIL)state.c
SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJ			=	$(SRC:.c=.o)

# =============================================================================
# Target Generating
# =============================================================================

%.o			:	%.c
				@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(OBJ)
				@echo $(GREEN) "Source files are compiled!\n" $(EOC)
				@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
				@$(CC) $(CFALGS) -I $(HEADER) -o $(NAME) $(OBJ)
				@echo $(GREEN) "$(NAME) is created!\n" $(EOC)

# =============================================================================
# Rules
# =============================================================================

.PHONY		:	all
all			:	$(NAME)

.PHONY		:	clean
clean		:
				@echo $(YELLOW) "Cleaning object files..." $(EOC)
				@$(RM) $(OBJ)
				@echo $(RED) "Object files are cleaned!\n" $(EOC)

.PHONY		:	fclean
fclean		:	clean
				@echo $(YELLOW) "Removing $(NAME)..." $(EOC)
				@$(RM) $(NAME)
				@echo $(RED) "$(NAME) is removed!\n" $(EOC)

.PHONY		:	re
re			:	fclean all

.PHONY		:	norm
norm		:
				@norminette
