# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 01:12:20 by sleonia           #+#    #+#              #
#    Updated: 2020/01/19 05:03:44 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = sleonia.filler

SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./libft/
VIZ_PATH = ./visualization/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
HEADERS = $(addprefix, $(INC_PATH), $(HEADERS_NAME))

FLAGS = 	-Ofast -g
# FLAGS = 	-Wall -Werror -Wextra -Ofast -g

HEADERS_NAME =	define_value.h		\
				function.h			\
				rt.h				\
				struct.h			\

SRC_NAME =	init.c					\
			main.c					\
			math_best_pos.c			\
			math_heatmap.c			\
			utilits.c				\
			parse_piece.c			\
			parse_plateau.c			\
			parse_player.c			\

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make lib_refresh
	@make visualization_refresh
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -lft -L $(LIB_PATH) $(FRAME)
	 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	@mkdir -p $(OBJ_PATH)
	@echo "\033[31m"
	@gcc $(FLAGS) $(INC) $(INC_SDL) -o $@ -c $<
	@echo "\033[0m"

lib_refresh:
	@make -C $(LIB_PATH)

visualization_refresh:
	@make -C $(VIZ_PATH)

clean:
	@find . -name ".DS_Store" -delete
	@clear
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@make clean -C $(VIZ_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@make fclean -C $(VIZ_PATH)

re: fclean all