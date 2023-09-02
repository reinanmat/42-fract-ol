/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:15:06 by coder             #+#    #+#             */
/*   Updated: 2023/01/02 10:48:56 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	start;
	size_t	len;
	size_t	i;

	i = ft_strlen(dest);
	if (size < i || (dest[0] == '\0' && size == 0))
		return (ft_strlen(src) + size);
	len = i + ft_strlen(src);
	start = 0;
	while (i < size - 1 && src[start] != '\0')
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (len);
}
