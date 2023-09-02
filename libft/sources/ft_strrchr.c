/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:40:33 by coder             #+#    #+#             */
/*   Updated: 2023/01/02 10:49:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (!s)
		return (0);
	if (c == '\0')
		return (&(((char *)s)[i]));
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return (&(((char *)s)[i]));
		i--;
	}
	return (0);
}
