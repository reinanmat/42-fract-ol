/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:28:35 by coder             #+#    #+#             */
/*   Updated: 2022/11/16 12:02:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_cwords(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	ft_insstr(char **str, char const *s, char c)
{
	size_t	position;
	size_t	start;
	size_t	len;
	size_t	i;

	position = 0;
	i = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		if (len != 0)
			str[position++] = ft_substr(s, start, len);
	}
	str[position] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arstr;

	if (!s)
		return (0x0);
	arstr = (char **)ft_calloc(ft_cwords(s, c) + 1, sizeof(char *));
	if (!arstr)
		return (0x0);
	ft_insstr(arstr, s, c);
	return (arstr);
}
