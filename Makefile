# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:10:26 by revieira          #+#    #+#              #
#    Updated: 2022/12/19 19:31:31 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
BONUS = fractol_bonus

PATH_SRCS		= ./Mandatory/sources/
PATH_OBJS		= ./Mandatory/objects/
PATH_INCS		= ./Mandatory/includes/
PATH_BONUS_SRCS	= ./Bonus/sources/
PATH_BONUS_OBJS = ./Bonus/objects/
PATH_BONUS_INCS = ./Bonus/includes/

FILES 			= init set_fractal fractal_julia fractal_mandelbrot draw \
				  keyhooks check_args main close_program mousehooks utils

BONUS_FILES 	= init_bonus set_fractal_bonus fractal_julia_bonus \
				  fractal_mandelbrot_bonus draw_bonus keyhooks_bonus \
				  check_args_bonus colors_bonus close_program_bonus \
				  fractal_extra_bonus mousehooks_bonus utils_bonus \
				  main_bonus

OBJS 			= $(addprefix $(PATH_OBJS), $(addsuffix .o, $(FILES) ) )
SRCS 			= $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES) ) )
BONUS_SRCS		= $(addprefix $(PATH_BONUS_SRCS), $(addsuffix .c, $(BONUS_FILES) ) ) 
BONUS_OBJS		= $(addprefix $(PATH_BONUS_OBJS), $(addsuffix .o, $(BONUS_FILES) ) ) 

PATH_LIBFT 		= ./libraries/libft/
PATH_LIBX		= ./libraries/minilibx-linux/
INCLUDES 		= -I $(PATH_INCS) -I $(PATH_LIBFT)
BONUS_INCLUDES	= -I $(PATH_BONUS_INCS) -I $(PATH_LIBFT)

CFLAGS 			= -Wall -Wextra -Werror
LIBFTFLAGS 		= -L $(PATH_LIBFT) -lft
LIBXFLAGS 		= -L $(PATH_LIBX) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(PATH_OBJS) $(OBJS)
	make -C $(PATH_LIBFT) --no-print-directory
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBXFLAGS) $(LIBFTFLAGS)

$(PATH_OBJS):
	mkdir -p $(PATH_OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(PATH_BONUS_OBJS) $(BONUS_OBJS)
	make -C $(PATH_LIBFT) --no-print-directory
	cc $(CFLAGS) -o $(BONUS) $(BONUS_OBJS) $(LIBXFLAGS) $(LIBFTFLAGS)

$(PATH_BONUS_OBJS):
	mkdir -p $(PATH_BONUS_OBJS)

$(PATH_BONUS_OBJS)%.o: $(PATH_BONUS_SRCS)%.c
	cc $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

clean:	
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -rf $(PATH_OBJS) $(PATH_BONUS_OBJS)
	make clean -C $(PATH_LIBFT) --no-print-directory

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C $(PATH_LIBFT) --no-print-directory

re: fclean all

.PHONY: all bonus clean fclean re
