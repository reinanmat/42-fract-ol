# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:10:26 by revieira          #+#    #+#              #
#    Updated: 2022/11/22 17:13:19 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES = init.c fractal.c draw.c hooks.c img.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(FILES:.c=.o)
INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror
LIBXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBXFLAGS)

$(OBJS): $(SRCS)
	cc $(CFLAGS) -I $(INCLUDES) -c $(SRCS) 

valgrind:
	valgrind --leak-check=full ./fractol

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
