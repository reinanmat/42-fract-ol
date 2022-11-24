# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:10:26 by revieira          #+#    #+#              #
#    Updated: 2022/11/24 18:55:29 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

PATH_LIBFT 	= ./libft/
INCLUDES 	= includes/ -I $(PATH_LIBFT)includes/
FILES 		= init.c fractal.c julia.c mandelbrot.c \
			  draw.c hooks.c img.c check.c color.c \
			  burningship.c
SRCS 		= $(addprefix srcs/, $(FILES))
OBJS 		= $(FILES:.c=.o)

CFLAGS 		= -Wall -Wextra -Werror
LIBFTFLAGS 	= -L $(PATH_LIBFT) -lft
LIBXFLAGS 	= -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBXFLAGS) $(LIBFTFLAGS)

$(OBJS): $(SRCS)
	make -C $(PATH_LIBFT)
	cc $(CFLAGS) -I $(INCLUDES) -c $(SRCS)  

valgrind:
	valgrind --leak-check=full ./fractol

clean:
	make clean -C $(PATH_LIBFT)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(PATH_LIBFT)
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
