/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:51:08 by revieira          #+#    #+#             */
/*   Updated: 2023/01/02 10:47:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (ft_strlen(dest) < ft_strlen(src))
		while (n-- > 0)
			(((char *)dest)[n]) = (((char *)src)[n]);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
