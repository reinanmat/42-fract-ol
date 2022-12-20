# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 18:11:10 by revieira          #+#    #+#              #
#    Updated: 2022/12/07 11:08:38 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libft.a

INCLUDES 	=	includes/
PATH_SRCS 	=	sources/
PATH_OBJS 	=	objects/

FILES 		= 	ft_atoi ft_isalnum ft_isalpha ft_isascii \
				ft_isdigit ft_isprint ft_tolower ft_toupper \
				ft_strlen ft_strncmp ft_strdup ft_strlcat \
				ft_strlcpy ft_strchr ft_strrchr ft_strnstr \
				ft_bzero ft_calloc ft_memcmp ft_memchr \
				ft_memset ft_memmove ft_memcpy ft_substr \
				ft_strjoin ft_strtrim ft_striteri ft_putchar_fd \
				ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_itoa \
				ft_split ft_strmapi ft_lstnew ft_lstadd_front \
				ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
				ft_lstclear ft_lstiter ft_lstmap get_next_line \
				get_next_line_utils ft_printf ft_printf_utils \

OBJS 		=	$(addprefix $(PATH_OBJS), $(addsuffix .o, $(FILES) ) )
SRCS 		=	$(addsuffix .c, $(FILES) ) 
CFLAGS 		=	-Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(PATH_OBJS) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(PATH_OBJS):
	mkdir -p $(PATH_OBJS)

$(PATH_OBJS)%.o : $(PATH_SRCS)%.c 
	cc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean :
	rm -rf $(PATH_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
