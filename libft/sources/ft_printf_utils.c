/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:23:03 by revieira          #+#    #+#             */
/*   Updated: 2023/01/02 10:48:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(long long n, char *base)
{
	int	bytes_writes;
	int	len_base;

	len_base = ft_strlen(base);
	bytes_writes = 0;
	if (n < 0)
	{
		bytes_writes += ft_print_char('-');
		n *= -1;
	}
	if (n < len_base)
		bytes_writes += ft_print_char(base[n]);
	else
	{
		bytes_writes += ft_putnbr_base(n / len_base, base);
		bytes_writes += ft_putnbr_base(n % len_base, base);
	}
	return (bytes_writes);
}

int	ft_putnbr_pos(unsigned long long n, char *base)
{
	int					bytes_writes;
	unsigned long long	len_base;

	len_base = ft_strlen(base);
	bytes_writes = 0;
	if (n < len_base)
		bytes_writes += ft_print_char(base[n]);
	else
	{
		bytes_writes += ft_putnbr_base(n / len_base, base);
		bytes_writes += ft_putnbr_base(n % len_base, base);
	}
	return (bytes_writes);
}

int	ft_print_point(unsigned long long n)
{
	int	bytes_writes;

	if (!n)
		return (ft_print_str("(nil)"));
	bytes_writes = ft_print_str("0x");
	bytes_writes += ft_putnbr_pos(n, BASE_HEX_LOW);
	return (bytes_writes);
}
