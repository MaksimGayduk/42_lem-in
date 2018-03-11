# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 08:37:35 by mgayduk           #+#    #+#              #
#    Updated: 2018/03/11 14:12:28 by mgayduk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

# Output settings
DEFAULT	:=\033[0m
BOLD	:=\033[1m
GREEN	:=\033[0;32m
RED		:=\033[0;31m

# Compiler
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g

# Directories
SRC_DIR := ./sources
OBJ_DIR := ./objects
INC_DIR := ./includes ./libft/includes
LFT_DIR := ./libft

# Source files for push_swap
SRC :=	push_swap.c 		\
		parser.c 			\
		reader.c			\
		input_error.c		\
		helpers.c			\
		ps_tools.c			\
		ps_tools_wrap1.c	\
		ps_tools_wrap2.c	\
		ps_tools_wrap3.c	\
		sorter.c 			\
		compute_a_stack.c	\
		compute_b_stack.c 	\
		mediana.c    		\
		sort_group_a.c 		\
		sort_group_a_last.c \
		sort_group_b.c 		\
		printer.c			
		
# Object files for push_swap
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Source files for checker
SRC2 := checker.c			\
		parser.c			\
		reader.c			\
		input_error.c		\
		helpers.c			\
		printer.c			\
		ps_tools.c			\
		ps_tools_wrap1.c	\
		ps_tools_wrap2.c	\
		ps_tools_wrap3.c	\
		statistics.c

# Object files for checker
OBJ2 := $(addprefix $(OBJ_DIR)/, $(SRC2:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
LFT := libft.a

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	make -C $(LFT_DIR) all
	$(CC) $(FLAGS) $(OBJ) $(LFT_DIR)/$(LFT) $(INC) -o $(NAME)
	$(CC) $(FLAGS) $(OBJ2) $(LFT_DIR)/$(LFT) $(INC) -o $(NAME2)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
	
clean:
	make -C $(LFT_DIR) clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LFT_DIR)/$(LFT)
	rm -rf $(NAME)
	rm -rf $(NAME2)

re: fclean all



