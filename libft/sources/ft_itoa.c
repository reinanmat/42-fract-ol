/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:41:59 by coder             #+#    #+#             */
/*   Updated: 2023/02/24 17:50:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		bytes;

	bytes = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * bytes + 1);
	if (str == 0x0)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[bytes--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		str[bytes--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
