# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 12:53:47 by mmatime           #+#    #+#              #
#    Updated: 2018/02/02 12:19:17 by mmatime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
INCLUDE = -Ilibft -Iinclude
CFLAGS = -Wall -Werror -Wextra $(INCLUDE)
SRC_PS = src/main_push_swap.c src/manip.c src/sort_piles.c src/valid_parsing.c src/pile_fill_a.c src/utils_1.c src/utils_2.c src/utils_3.c
LIB_PATH = ./libft/
LIB_BIN = $(LIB_PATH)libft.a
SRC_PATH = ./src/

OBJ_SRC_PS = $(SRC_PS:.c=.o)

$(NAME): $(OBJ_SRC_PS)
	make -C $(LIB_PATH)
	$(CC) -o $(NAME) $(SRC_PS) $(INCLUDE) $(CFLAGS) $(LIB_BIN)

all: $(NAME)

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -f $(OBJ_SRC_PS)

fclean: clean
	make -C $(LIB_PATH) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
