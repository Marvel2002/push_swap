# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 12:53:47 by mmatime           #+#    #+#              #
#    Updated: 2018/02/12 20:27:01 by mmatime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_2 = checker
CC = gcc
INCLUDE = -Ilibft -Iinclude
CFLAGS = -Wall -Werror -Wextra $(INCLUDE)
SRC_PS = src/main_push_swap.c src/manip_1.c src/manip_2.c src/manip_3.c src/sort_piles.c src/valid_parsing.c src/pile_fill_a.c src/utils.c src/pile_init.c
SRC_CK = src/main_checker.c src/manip_1.c src/manip_2.c src/manip_3.c src/sort_piles.c src/valid_parsing.c src/pile_fill_a.c src/utils.c src/pile_init.c
LIB_PATH = ./libft/
LIB_BIN = $(LIB_PATH)libft.a
SRC_PATH = ./src/

OBJ_SRC_PS = $(SRC_PS:.c=.o)
OBJ_SRC_CK = $(SRC_CK:.c=.o)

all: $(NAME) $(NAME_2)

$(NAME): $(OBJ_SRC_PS)
	make -C $(LIB_PATH)
	$(CC) -o $(NAME) $(SRC_PS) $(INCLUDE) $(CFLAGS) $(LIB_BIN)

$(NAME_2): $(OBJ_SRC_CK)
	make -C $(LIB_PATH)
	$(CC) -o $(NAME_2) $(SRC_CK) $(INCLUDE) $(CFLAGS) $(LIB_BIN)

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -f $(OBJ_SRC_PS) $(OBJ_SRC_CK)

fclean: clean
	make -C $(LIB_PATH) fclean
	/bin/rm -f $(NAME) $(NAME_2)

re: fclean all

.PHONY: all clean fclean re
