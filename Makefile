# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 16:54:08 by ehasalu           #+#    #+#              #
#    Updated: 2023/01/22 12:43:17 by ehasalu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long
SRCS =	so_long.c so_long_util.c sprite.c movement.c map.c so_long_util2.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: lib $(NAME)

lib:
	make -C libft
	make -C libft/ft_printf
	make -C mlx

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) mlx/libmlx.a libft/libft.a libft/ft_printf/libftprintf.a -lXext -lX11

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@	

clean:
	rm -rf $(OBJS)
	make fclean -C libft
	make fclean -C libft/ft_printf
	make clean -C mlx

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
