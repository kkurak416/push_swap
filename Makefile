# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:30:38 by kkurowsk          #+#    #+#              #
#    Updated: 2025/05/06 17:56:47 by kkurowsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = ../libft/libft.a

SRCS = args.c main.c operations.c sort.c sort_utils.c support.c utils.c utils2.c utils3.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ../libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ../libft
	rm -f $(OBJS)

fclean: clean
	@make fclean -C ../libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
