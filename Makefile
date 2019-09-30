# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2019/09/27 20:01:23 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

OBJ_PATH		= ./src
INC_PATH		= ./include
LIB_PATH		= ./src/lib
SRC_PATH		= ./src/fdf
MLX_PATH		= ./src/minilibx

CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror
LFLAGS			= -I $(INC_PATH) -I /usr/local/include/
LIB				= -L $(LIB_PATH) -lftprintf
MLX				= -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

SRC 			= fdf.c ft_exit.c create_fdf.c create_vector.c validation.c

OBJ				= $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

######################FOR UBUNTU#######################
MLX_L			= -L /usr/local/lib -lmlx -lXext -lX11
MLX_L_PATH		= ./src/minilibx_l
linux: $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(MAKE) -C $(MLX_L_PATH)
	$(CC) $(LFLAGS) $(OBJ) $(LIB) $(MLX_L) -o $(NAME)
#######################################################


$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(LFLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	$(CC) $(LFLAGS) -o $@ -c $<

norm:
	norminette $(LIB_PATH) | grep "E"
	norminette $(SRC_PATH) | grep "E"
	norminette $(INC_PATH) | grep "E"

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	#@$(MAKE) clean -C $(MLX_L_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all
