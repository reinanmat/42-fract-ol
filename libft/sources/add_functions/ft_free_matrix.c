/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:50:26 by revieira          #+#    #+#             */
/*   Updated: 2023/01/14 20:51:10 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(void **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
