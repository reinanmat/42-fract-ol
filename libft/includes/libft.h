/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:11:21 by revieira          #+#    #+#             */
/*   Updated: 2023/09/01 21:38:31 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 42
# define SPECS "cspdiuxX%"
# define BASE_DEC "0123456789"
# define BASE_HEX_LOW "0123456789abcdef"
# define BASE_HEX_UPP "0123456789ABCDEF"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//LIBFT
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);

void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//GET_NEXT_LINE
char	*get_next_line(int fd);
char	*fd_read(int fd, char *rest);
char	*extract_new_rest(char *rest);
char	*extract_new_line(char *rest);
int		check_line_break(char *s);

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(const char *s);
size_t	ft_strlen_gnl(const char *s);

//FT_PRINTF
int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_point(unsigned long long n);
int		ft_putnbr_base(long long n, char *base);
int		ft_putnbr_pos(unsigned long long n, char *base);

//ADD_FUNCTIONS
void	ft_exit_program(char *msg, int exit_code);
int		ft_str_is(char *str, int (*f)(int));
int		ft_matrix_is(char **matrix, int (*f)(int));
void	ft_free_matrix(void **matrix, int size);
int		ft_isnum(char *str);
int		ft_abs(int num);

#endif
