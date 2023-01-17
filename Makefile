# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:02:01 by seoyoo            #+#    #+#              #
#    Updated: 2023/01/17 14:24:25 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Green = \033[0;31m		# Green
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m		# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m		# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

# target
NAME = miniRT

# compiler
CC = cc
DBFLAGS = -g
CFLAGS = -Wall -Wextra -Werror

# basic directories
SRC_DIR = ./src/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# include
INC_DIR = ./inc/
INC_FLAGS = -I $(INC_DIR)

# my_lib
MY_LIB_DIR = ./my_lib/
MY_LIB_ARC = my_lib.a
MY_LIB = $(MY_LIB_DIR)$(MY_LIB_ARC)

# mlx related
MLX_DIR = ./mlx/
MLX_ARC = libmlx.a
MLX = $(MLX_DIR)$(MLX_ARC)
API_FLAGS = -framework OpenGL -framework AppKit

# complication
COMPILE_FLAGS = $(CC) $(DBFLAGS) $(CFLAGS) $(INC_FLAGS) -I $(MLX_DIR)
LINKING_FLAGS = $(CC) $(MLX) $(MY_LIB) $(API_FLAGS)

# main
MAIN_SRC_DIR = $(SRC_DIR)
MAIN_OBJ_DIR = $(OBJ_DIR)
MAIN_FILE = main

MAIN_SRC = $(SRC_DIR)$(MAIN_FILE).c
MAIN_OBJ = $(OBJ_DIR)$(MAIN_FILE).o
OBJS += $(MAIN_OBJ)

# utils

UTILS_DIR = utils/
UTILS_SRC_DIR = $(SRC_DIR)$(UTILS_DIR)
UTILS_OBJ_DIR = $(OBJ_DIR)$(UTILS_DIR)

UTILS_FILE = \
		hello_world

UTILS_SRCS = $(addprefix $(addprefix $(UTILS_SRC_DIR), $(UTILS_FILE)), .c)
UTILS_OBJS = $(addprefix $(addprefix $(UTILS_OBJ_DIR), $(UTILS_FILE)), .o)
OBJS += $(UTILS_OBJS)

# **************************************************************************** #

# main rules

all : $(NAME)

#	linking
$(NAME) : $(OBJS)
	@make mylib
	@make minilibx
	@printf "$(Green)\n[ mylib & minilibx compile finished!!] \n$(Color_Off)"
	$(LINKING_FLAGS) -o $@ $^
	@printf "$(Blue)\n[ ENJOY FDF!! ]\n$(Color_Off)"

#	compiling
$(MAIN_OBJ_DIR)%.o : $(MAIN_SRC_DIR)%.c
	@mkdir -p $(MAIN_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

$(UTILS_OBJ_DIR)%.o : $(UTILS_SRC_DIR)%.c
	@mkdir -p $(UTILS_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

# **************************************************************************** #

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean -C $(MY_LIB_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(NAME)

re : fclean all

ree : clean all

mylib :
	@make -C $(MY_LIB_DIR)

minilibx : 
	@make -C $(MLX_DIR)

norm :
	@norminette src inc my_lib | grep Error

.PONEY : all clean fclean re ree mylib minilibx norm
