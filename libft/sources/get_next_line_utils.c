/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:54:47 by revieira          #+#    #+#             */
/*   Updated: 2023/01/02 10:59:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*cpy;
	int		i;

	if (!s)
		return (0);
	cpy = (char *)malloc(sizeof(char) * ft_strlen_gnl(s) + 1);
	if (!cpy)
		return (0);
	i = -1;
	while (s[++i])
		cpy[i] = s[i];
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	if (s1 == NULL)
		s1 = ft_strdup("");
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
