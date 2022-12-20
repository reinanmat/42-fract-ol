/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:56:16 by coder             #+#    #+#             */
/*   Updated: 2022/11/16 12:04:39 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	if (!set)
		return (0);
	while (s1[i] && ft_strchr(set, s1[i++]))
		start++;
	if (start == ft_strlen(s1))
		return (ft_substr(s1, start, ft_strlen(s1)));
	end = ft_strlen(s1);
	i = end - 1;
	while (ft_strrchr(set, s1[i--]))
		end--;
	return (ft_substr(s1, start, end - start));
}
