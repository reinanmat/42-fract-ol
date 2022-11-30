/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:24:16 by revieira          #+#    #+#             */
/*   Updated: 2022/11/30 13:55:18 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	arrows(int key, t_fractol *f)
{
	t_aux	aux;

	aux.range_re = f->max_re - f->min_re;
	aux.range_im = f->max_im - f->min_im;
	if (key == XK_Left)
	{
		f->min_re -= aux.range_re * 0.1;
		f->max_re -= aux.range_re * 0.1;
	}
	else if (key == XK_Right)
	{
		f->min_re += aux.range_re * 0.1;
		f->max_re += aux.range_re * 0.1;
	}
	else if (key == XK_Up)
	{
		f->min_im -= aux.range_im * 0.1;
		f->max_im -= aux.range_im * 0.1;
	}
	else if (key == XK_Down)
	{
		f->min_im += aux.range_im * 0.1;
		f->max_im += aux.range_im * 0.1;
	}
}
