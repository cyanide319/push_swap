# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 16:06:16 by tbeaudoi          #+#    #+#              #
#    Updated: 2022/09/28 16:29:41 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

NAME = push_swap

SRC = src/*.c

OBJ = $(SRC:.c=.o)

PRINTF = include/printf/libftprintf.a
PRINTF_PATH = include/printf/

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

				
all: push_swap

push_swap: $(SRC) $(OBJ)
		$(MAKE) -C $(PRINTF_PATH)
		$(MAKE) -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(PRINTF) $(LIBFT)

clean:
		$(RM) $(OBJ)
		make -C $(PRINTF_PATH) clean
		make -C $(LIBFT_PATH) clean

fclean: clean
		$(RM) $(NAME) $(PRINTF) $(LIBFT)

re: fclean all