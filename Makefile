# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:10:26 by revieira          #+#    #+#              #
#    Updated: 2022/12/07 12:41:32 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

PATH_OBJS	= ./objects/
PATH_SRCS	= ./sources/
PATH_LIBFT 	= ./libraries/libft/
PATH_LIBX	= ./libraries/minilibx-linux/
INCLUDES 	= -I includes/ -I $(PATH_LIBFT)

FILES 		= init set_fractal fractal_julia fractal_mandelbrot \
			  draw keyhooks check_args colors close_program main\
			  fractal_burningship fractal_tricorn mousehooks zoom utils
OBJS 		= $(addprefix $(PATH_OBJS), $(addsuffix .o, $(FILES) ) )
SRCS 		= $(addsuffix .c, $(FILES) )

CFLAGS 		= -Wall -Wextra -Werror
LIBFTFLAGS 	= -L $(PATH_LIBFT) -lft
LIBXFLAGS 	= -L $(PATH_LIBX) -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(PATH_OBJS) $(OBJS)
	make -C $(PATH_LIBFT) --no-print-directory
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBXFLAGS) $(LIBFTFLAGS)

$(PATH_OBJS):
	mkdir -p $(PATH_OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:	
	rm -f $(OBJS)
	rm -rf $(PATH_OBJS)
	make clean -C $(PATH_LIBFT) --no-print-directory

fclean: clean
	rm -f $(NAME)	
	make fclean -C $(PATH_LIBFT) --no-print-directory

re: fclean all

.PHONY: all clean fclean re
