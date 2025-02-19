# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 15:39:28 by kkurowsk          #+#    #+#              #
#    Updated: 2025/02/19 10:19:41 by kkurowsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = push_swap.h

NAME = pushswap.a

SRC = push_swap.c utilis_p.c utilis_r.c utilis_rr.c utilis_s.c

OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -I$(LIB_PATH)

LIB_PATH = libft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIB_PATH) all

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I./ &< -o $@

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)

clean:
	rm -f $(OBJS)
	make -C$(LIB_PATH) clean

re: fclean all

.PHONY: all clean fclean re
