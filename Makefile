# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 12:53:47 by mmatime           #+#    #+#              #
#    Updated: 2018/01/22 22:04:00 by mmatime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = binaire
CC = gcc
INCLUDE = -Ilibft -Iinclude
CFLAGS = -Wall -Werror -Wextra $(INCLUDE)
SRC = src/main.c
LIB_PATH = ./libft/
LIB_BIN = $(LIB_PATH)libft.a
SRC_PATH = ./src/

OBJ_SRC = $(SRC:.c=.o)

$(NAME): $(OBJ_SRC)
	make -C $(LIB_PATH)
	$(CC) -o $(NAME) $(SRC) $(INCLUDE) $(CFLAGS) $(LIB_BIN)

all: $(NAME)

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -f $(OBJ_SRC)

fclean: clean
	make -C $(LIB_PATH) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
