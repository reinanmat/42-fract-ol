/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:55:26 by revieira          #+#    #+#             */
/*   Updated: 2023/01/02 10:59:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_line_break(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

char	*extract_new_line(char *rest)
{
	char	*new_line;
	int		i;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (0);
	i = -1;
	while (rest[++i] && rest[i] != '\n')
		new_line[i] = rest[i];
	if (rest[i] == '\n')
	{
		new_line[i] = rest[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*extract_new_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if ((rest[i] == '\n' && rest[i + 1] == '\0') || !rest[i])
	{
		free(rest);
		return (NULL);
	}
	new_rest = (char *)malloc(sizeof(char) * (ft_strlen_gnl(rest) - i + 1));
	if (!new_rest)
		return (0);
	j = 0;
	while (rest[++i] != '\0')
		new_rest[j++] = rest[i];
	new_rest[j] = '\0';
	free(rest);
	return (new_rest);
}

char	*fd_read(int fd, char *rest)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	bytes_read = 1;
	while (!(check_line_break(rest)))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		rest = ft_strjoin_gnl(rest, buf);
		if (!rest)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	if (bytes_read == -1)
		return (NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	rest = fd_read(fd, rest);
	if (!(ft_strlen(rest)))
	{
		free(rest);
		return (NULL);
	}
	line = extract_new_line(rest);
	rest = extract_new_rest(rest);
	return (line);
}
