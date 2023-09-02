/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:39:28 by revieira          #+#    #+#             */
/*   Updated: 2023/01/02 10:48:10 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	bytes_writes;

	bytes_writes = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (*str)
	{
		bytes_writes += ft_print_char(*str);
		str++;
	}
	return (bytes_writes);
}

static int	check_valided_specifier(char c, const char *specifiers)
{
	while (*specifiers)
	{
		if (*specifiers == c)
			return (1);
		specifiers++;
	}
	return (0);
}

static int	check_after_percent(char specifier, va_list ap)
{
	int	bytes_writes;

	bytes_writes = 0;
	if (specifier == 'c')
		bytes_writes = ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		bytes_writes = ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		bytes_writes = ft_putnbr_base(va_arg(ap, int), BASE_DEC);
	else if (specifier == 'p')
		bytes_writes = ft_print_point(va_arg(ap, unsigned long long));
	else if (specifier == 'u')
		bytes_writes = ft_putnbr_pos(va_arg(ap, unsigned int), BASE_DEC);
	else if (specifier == 'x')
		bytes_writes = ft_putnbr_pos(va_arg(ap, unsigned int), BASE_HEX_LOW);
	else if (specifier == 'X')
		bytes_writes = ft_putnbr_pos(va_arg(ap, unsigned int), BASE_HEX_UPP);
	else if (specifier == '%')
		bytes_writes = ft_print_char('%');
	return (bytes_writes);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bytes_writes;

	if (!format)
		return (-1);
	va_start(ap, format);
	bytes_writes = 0;
	while (*format)
	{
		if (*format == '%' && check_valided_specifier(*(format + 1), SPECS))
		{
			format++;
			bytes_writes += check_after_percent(*format, ap);
		}
		else
			bytes_writes += ft_print_char(*format);
		format++;
	}
	va_end(ap);
	return (bytes_writes);
}
