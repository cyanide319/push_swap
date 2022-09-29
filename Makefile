# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 16:06:16 by tbeaudoi          #+#    #+#              #
#    Updated: 2022/09/29 18:59:03 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

NAME = push_swap

SRC = src/push_swap.c \
	src/error.c \
	src/moves_a.c \
	src/moves_b.c \
	src/moves_multi.c \
	src/stacks_init.c \
	src/utils.c \

OBJ = $(SRC:.c=.o)

PRINTF = include/printf/libftprintf.a
PRINTF_PATH = include/printf/

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

				
all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C $(PRINTF_PATH)
		$(MAKE) -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PRINTF) $(LIBFT)

clean:
		$(RM) $(OBJ)
		make -C $(PRINTF_PATH) clean
		make -C $(LIBFT_PATH) clean

fclean: clean
		$(RM) $(NAME) $(PRINTF) $(LIBFT)

re: fclean all