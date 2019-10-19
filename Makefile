# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2019/10/19 10:55:19 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

OBJ_DIR			= ./obj
INC_DIR			= ./inc
LIB_DIR			= ./libftprintf
SRC_DIR			= ./src

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LFLAGS			= -I $(INC_DIR) -I /usr/local/include/
LFLAGS			+= -I $(LIB_DIR)/inc -I $(LIB_DIR)/libft
LIBS			= -L $(LIB_DIR) -lftprintf

HEADERS			= fdf.h buttons.h color.h

UNAME 			= $(shell uname -s)

ifeq ($(UNAME), Linux)
	LIBS		+= -lmlx -lXext -lX11 -lm
	MLX_PATH 	+=./minilibx_linux
else
	LIBS		+= -L ./minilibx -lmlx -framework OpenGL -framework AppKit -lm
	MLX_PATH 	+=./minilibx
endif

SRC 			= fdf.c ft_exit.c fdf_create.c vector_create.c
SRC				+= coordinates_and_color.c initialize.c bresenham.c
SRC				+= draw.c hooks.c matrix_create.c matrix_actions.c
SRC				+= legend.c gradient_color.c mix_color.c zbuffer.c

OBJ				= $(SRC:.c=.o)

vpath %.h $(INC_DIR)
vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)

all: $(NAME)

$(NAME): libs $(OBJ)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(LFLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ)) $(LIBS) -o $@

$(OBJ):%.o:%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(LFLAGS) -o $(OBJ_DIR)/$@ -c $<

libs:
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_PATH)

$(OBJ_DIR):
	mkdir -p $@

norm:
	$(MAKE) $@ -C $(LIB_DIR)
	norminette $(SRC_DIR)
	norminette $(INC_DIR)

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_PATH)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re libs

.SILENT: all $(NAME) $(OBJ) $(OBJ_DIR) clean fclean re libs
