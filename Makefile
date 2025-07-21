# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 15:36:02 by digulraj          #+#    #+#              #
#    Updated: 2025/07/21 13:48:26 by digulraj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = fractol.c events.c init.c math_utils.c render.c string_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
W_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11

all:
	$(CC) $(SRC) -o $(NAME) $(W_FLAGS) $(MLX_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
