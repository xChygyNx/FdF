# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2019/10/07 19:31:46 by pcredibl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

OBJ_PATH		= ./src
INC_PATH		= ./include
LIB_PATH		= ./lib
SRC_PATH		= ./src

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LFLAGS			= -I $(INC_PATH) -I /usr/local/include/
LIB				= -L $(LIB_PATH) -lftprintf

UNAME 			= $(shell uname -s)

ifeq ($(UNAME), Linux)
	MLX			+= -lmlx -lXext -lX11
	MLX_PATH 	+=./minilibx_linux
else
	MLX			+= -L ./minilibx -lmlx -framework OpenGL -framework AppKit
	MLX_PATH 	+=./minilibx_macos
endif

SRC 			= fdf.c ft_exit.c fdf_create.c vector_create.c
SRC				+= coordinates_and_color.c initialize.c bresenham.c
SRC				+= draw.c rotation.c hooks.c matrix_create.c
SRC				+= matrix_actions.c zoom.c relief.c gradient.c

OBJ				= $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_PATH)
	@$(MAKE) -C $(MLX_PATH)
	$(CC) -g $(LFLAGS) $(OBJ) $(LIB) $(MLX) -lm -o $(NAME)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@$(CC) -g $(LFLAGS) -o $@ -c $<

norm:
	norminette $(LIB_PATH) | grep "E"
	norminette $(SRC_PATH) | grep "E"
	norminette $(INC_PATH) | grep "E"

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all
