# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:10:26 by revieira          #+#    #+#              #
#    Updated: 2022/11/16 15:46:42 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfractal

SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): 
	cc $(CFLAGS) -I includes/fractal.h $(SRCS) -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o fractal

run:
	./fractal

valgrind:
	valgrind --leak-check ./fractal

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
