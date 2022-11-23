# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:10:26 by revieira          #+#    #+#              #
#    Updated: 2022/11/23 18:29:25 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

PATH_LIBFT = ./libft/
FILES = init.c fractal.c draw.c hooks.c img.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(FILES:.c=.o)
INCLUDES = includes/ -I $(PATH_LIBFT)includes/

CFLAGS = -Wall -Wextra -Werror
LIBFTFLAGS = -L $(PATH_LIBFT) -lft
LIBXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBXFLAGS) $(LIBFTFLAGS)

$(OBJS): $(SRCS)
	make -C $(PATH_LIBFT)
	cc $(CFLAGS) -I $(INCLUDES) -c $(SRCS))  

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
