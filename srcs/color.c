/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:52:57 by revieira          #+#    #+#             */
/*   Updated: 2022/11/24 14:12:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    colors(t_fractol *f, int i)
{
    static int  color = 265;

    if (i == f->max_iter)
        color = 0;
    else
    {
        f->color = color;
        color += 265;
    }
}
