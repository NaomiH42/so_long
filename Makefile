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

NAME =	so_long.out
SRCS =	so_long.c so_long_util.c sprite.c movement.c map.c gnl/get_next_line.c \
	gnl/get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	ar rc $(NAME).a $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@	

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME).a

re: fclean all

.PHONY: all clean fclean re
