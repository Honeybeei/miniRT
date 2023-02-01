# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:02:01 by seoyoo            #+#    #+#              #
#    Updated: 2023/02/01 10:34:33 by seoyoo           ###   ########.fr        #
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

# archive files

# my_lib
MY_LIB_DIR = ./my_lib/
MY_LIB_ARC = my_lib.a
MY_LIB = $(MY_LIB_DIR)$(MY_LIB_ARC)

# mlx related
MLX_DIR = ./mlx/
MLX_ARC = libmlx.a
MLX = $(MLX_DIR)$(MLX_ARC)
API_FLAGS = -framework OpenGL -framework AppKit

# MINI_MATH
MINI_MATH_DIR = ./minimath/
MINI_MATH_ARC = minimath.a
MINI_MATH = $(MINI_MATH_DIR)$(MINI_MATH_ARC)

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

# flags and options
COMPILE_FLAGS = $(CC) $(DBFLAGS) $(CFLAGS) $(INC_FLAGS) -I $(MLX_DIR)
LINKING_FLAGS = $(CC) $(MLX) $(MY_LIB) $(MINI_MATH) $(API_FLAGS)

# **************************************************************************** #

# main
MAIN_SRC_DIR = $(SRC_DIR)
MAIN_OBJ_DIR = $(OBJ_DIR)
MAIN_FILE = main

MAIN_SRC = $(SRC_DIR)$(MAIN_FILE).c
MAIN_OBJ = $(OBJ_DIR)$(MAIN_FILE).o
OBJS += $(MAIN_OBJ)
OBJ_DIRS += $(MAIN_OBJ_DIR)

# **************************************************************************** #

# drawing_tools
DRAWING_TOOLS_DIR = drawing_tools/
DRAWING_TOOLS_SRC_DIR = $(SRC_DIR)$(DRAWING_TOOLS_DIR)
DRAWING_TOOLS_OBJ_DIR = $(OBJ_DIR)$(DRAWING_TOOLS_DIR)

DRAWING_TOOLS_FILE = \
        color_related \
		put

DRAWING_TOOLS_SRCS = $(addsuffix .c, $(addprefix $(DRAWING_TOOLS_SRC_DIR), $(DRAWING_TOOLS_FILE)))
DRAWING_TOOLS_OBJS = $(addsuffix .o, $(addprefix $(DRAWING_TOOLS_OBJ_DIR), $(DRAWING_TOOLS_FILE)))
OBJS += $(DRAWING_TOOLS_OBJS)
OBJ_DIRS += $(DRAWING_TOOLS_OBJ_DIR)

# **************************************************************************** #

# input_parsing
INPUT_PARSING_DIR = input_parsing/
INPUT_PARSING_SRC_DIR = $(SRC_DIR)$(INPUT_PARSING_DIR)
INPUT_PARSING_OBJ_DIR = $(OBJ_DIR)$(INPUT_PARSING_DIR)

INPUT_PARSING_FILE = \
		parse_input \
		parsing_utils1 \
		parsing_utils2 \
		print_inputs \
		scan_essentials \
		scan_optionals

INPUT_PARSING_SRCS = $(addsuffix .c, $(addprefix $(INPUT_PARSING_SRC_DIR), $(INPUT_PARSING_FILE)))
INPUT_PARSING_OBJS = $(addsuffix .o, $(addprefix $(INPUT_PARSING_OBJ_DIR), $(INPUT_PARSING_FILE)))
OBJS += $(INPUT_PARSING_OBJS)
OBJ_DIRS += $(INPUT_PARSING_OBJ_DIR)

# **************************************************************************** #

# rendering
RENDERING_DIR = rendering/
RENDERING_SRC_DIR = $(SRC_DIR)$(RENDERING_DIR)
RENDERING_OBJ_DIR = $(OBJ_DIR)$(RENDERING_DIR)

RENDERING_FILE = \
		draw_all \
		traverse

RENDERING_SRCS = $(addsuffix .c, $(addprefix $(RENDERING_SRC_DIR), $(RENDERING_FILE)))
RENDERING_OBJS = $(addsuffix .o, $(addprefix $(RENDERING_OBJ_DIR), $(RENDERING_FILE)))
OBJS += $(RENDERING_OBJS)
OBJ_DIRS += $(RENDERING_OBJ_DIR)

# **************************************************************************** #

# utils
UTILS_DIR = utils/
UTILS_SRC_DIR = $(SRC_DIR)$(UTILS_DIR)
UTILS_OBJ_DIR = $(OBJ_DIR)$(UTILS_DIR)

UTILS_FILE = \
		error_management \
		initialization

UTILS_SRCS = $(addsuffix .c, $(addprefix $(UTILS_SRC_DIR), $(UTILS_FILE)))
UTILS_OBJS = $(addsuffix .o, $(addprefix $(UTILS_OBJ_DIR), $(UTILS_FILE)))
OBJS += $(UTILS_OBJS)
OBJ_DIRS += $(UTILS_OBJ_DIR)

# **************************************************************************** #

# main rules
all : minilibx mylib mini_math mkobjdir $(NAME)

#	linking
$(NAME) : $(OBJS)
	$(LINKING_FLAGS) -o $@ $^
	@printf "$(Blue)\n[ Shut up and Ray Trace!! ]\n\n$(Color_Off)"

#	compiling
$(MAIN_OBJ_DIR)%.o : $(MAIN_SRC_DIR)%.c
	$(COMPILE_FLAGS) -c $< -o $@

# **************************************************************************** #

mkobjdir :
	@mkdir -p $(OBJ_DIRS)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean -C $(MY_LIB_DIR)
	@make fclean -C $(MINI_MATH_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(NAME)

re : fclean all

ree : clean all

run : ree
	@./$(NAME)

mylib :
	@make -C $(MY_LIB_DIR)

minilibx : 
	@make -C $(MLX_DIR)

mini_math :
	@make -C $(MINI_MATH_DIR)

norm :
	@norminette src inc minimath my_lib | grep Error

.PONEY : all mkobjdir clean fclean re ree run mylib minilibx MINI_MATH norm
