/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:37:37 by revieira          #+#    #+#             */
/*   Updated: 2022/10/18 15:32:53 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define SPECS          "cspdiuxX%"
# define BASE_DEC	    "0123456789"
# define BASE_HEX_LOW   "0123456789abcdef"
# define BASE_HEX_UPP	"0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_point(unsigned long long n);
int		ft_putnbr_base(long long n, char *base);
int		ft_putnbr_pos(unsigned long long n, char *base);
size_t	ft_strlen(char *str);

#endif
