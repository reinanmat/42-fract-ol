/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadra_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:52:04 by revieira          #+#    #+#             */
/*   Updated: 2023/01/14 20:53:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_quadra_free(void *one, void *two, void *three, void *four)
{
	if (one)
		free(one);
	if (two)
		free(two);
	if (three)
		free(three);
	if (four)
		free(four);
}
