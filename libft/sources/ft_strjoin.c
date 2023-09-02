/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:20:48 by coder             #+#    #+#             */
/*   Updated: 2023/01/02 10:48:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	str[j] = '\0';
	ft_strlcat(str, s2, len);
	return (str);
}
