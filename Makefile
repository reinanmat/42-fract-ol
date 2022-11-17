# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:10:26 by revieira          #+#    #+#              #
#    Updated: 2022/11/17 16:59:27 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfractal

SRCS = $(addprefix srcs/, main.c plotline.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LIBXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) 
	
$(OBJS): $(SRCS)
	cc $(CFLAGS) -I includes/fractal.h $(SRCS) $(LIBXFLAGS) -o fractal

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
