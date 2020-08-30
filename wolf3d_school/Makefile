# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talexia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 04:40:16 by talexia           #+#    #+#              #
#    Updated: 2020/08/28 04:40:16 by talexia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRC_INC_DIR = ./includes
SDL2_INC_DIR = SDL2.framework/Headers
SDL2_FRAME_DIR = ~/Library/Frameworks/
FRAME = SDL2.framework
INC_C = ./includes/wolf3d.h

SRC_FILES = main.c draw_fov.c draw_map.c draw_rect.c draw_walls.c input_pixel.c draw_skybox.c draw_texture.c init.c error.c read_map.c hooks.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
SDL2_FRAME = $(FRAME) $(SDL2_FRAME_DIR)
ADD_FRAME = -F ./ -framework SDL2

INCL = -I$(SRC_INC_DIR) -I$(SDL2_INC_DIR)

FLAGS = -Werror -Wextra -Wall $(INCL)

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) 
	gcc -o $(NAME) -O2 $(FLAGS) $(ADD_FRAME) $(OBJS)
	cp -r $(SDL2_FRAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_C)
	gcc $(FLAGS) -c -O3 $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(SDL2_FRAME_DIR)$(FRAME)

re: fclean all