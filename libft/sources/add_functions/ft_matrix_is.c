/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:36:24 by revieira          #+#    #+#             */
/*   Updated: 2023/01/20 18:32:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrix_is(char **matrix, int (*f)(int))
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (!ft_str_is(matrix[i], f))
			return (0);
		i++;
	}
	return (1);
}
