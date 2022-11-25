# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:10:26 by revieira          #+#    #+#              #
#    Updated: 2022/11/25 16:14:48 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

PATH_LIBFT 	= ./libft/
INCLUDES 	= includes/ -I $(PATH_LIBFT)includes/
FILES 		= init.c set_fractal.c fractal_julia.c fractal_mandelbrot.c \
			  draw.c hooks.c check_args.c color.c close.c main.c\
			  fractal_burningship.c move.c zoom.c utils.c
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
