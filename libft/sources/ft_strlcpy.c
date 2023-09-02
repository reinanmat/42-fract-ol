/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:36:39 by coder             #+#    #+#             */
/*   Updated: 2023/01/02 10:49:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen(src);
	i = -1;
	if (size >= 1)
	{
		while ((size - 1) > ++i && *(src + i) != '\0')
			*(dest + i) = *(src + i);
		*(dest + i) = '\0';
	}
	return (len_src);
}
