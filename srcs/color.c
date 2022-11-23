/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:52:57 by revieira          #+#    #+#             */
/*   Updated: 2022/11/23 17:56:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    colors(t_data *data, int i)
{
    static int  color = 265;

    if (i == data->fractol.max_iter)
        data->color = 0;
    else
    {
        data->color = color;
        color += 265;
    }
}
