# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 21:03:19 by seoyoo            #+#    #+#              #
#    Updated: 2023/02/07 12:29:09 by jchoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Red = \033[0;31m		# Red
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m		# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m		# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

# target
NAME = minimath.a

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
DBFLAG = -g3

# archive
AR = ar
ARFLAGS = -rcs

# include
INC_DIR = ./inc
INC = -I $(INC_DIR)

# basic directories
SRC_DIR = ./src/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# **************************************************************************** #

SRC_FILE = \
		matrix.c \
		matrix_binary_operation.c \
		matrix_unary_operation.c \
		vector.c \
		vector_binary_operation.c \
		vector_projection.c \
		vector_unary_operation.c\
		utils.c\
		line.c\
		dist.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))

# object
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILE)) 

# **************************************************************************** #

# rules
all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	@printf "$(Green)\n[ minimath compile finished!!] \n$(Color_Off)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf ./obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PONEY: all clean fclean re
