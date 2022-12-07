/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:45:28 by revieira          #+#    #+#             */
/*   Updated: 2022/12/07 12:01:02 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(double zoom, char up_down, t_fractol *f)
{
	if (up_down == 'd')
	{
		f->min_re += (f->max_im - f->min_im) * zoom;
		f->max_re -= (f->max_im - f->min_im) * zoom;
		f->min_im += (f->max_re - f->min_re) * zoom;
		f->max_im = (f->max_re - f->min_re) * HEIGHT / WIDTH + f->min_im;
	}
	else if (up_down == 'u')
	{
		f->min_re -= (f->max_im - f->min_im) * zoom;
		f->max_re += (f->max_im - f->min_im) * zoom;
		f->min_im -= (f->max_re - f->min_re) * zoom;
		f->max_im = (f->max_re - f->min_re) * HEIGHT / WIDTH + f->min_im;
	}
}

void	key_zoom(int key, t_fractol *f)
{
	t_aux	aux;

	aux.range_re = f->max_re - f->min_re;
	aux.range_im = f->max_im - f->min_im;
	if (key == 'z')
	{
		f->min_re += aux.range_re * 0.1;
		f->max_re -= aux.range_re * 0.1;
		f->min_im += aux.range_im * 0.1;
		f->max_im -= aux.range_im * 0.1;
	}
	else if (key == 'x')
	{
		f->min_re -= aux.range_re * 0.1;
		f->max_re += aux.range_re * 0.1;
		f->min_im -= aux.range_im * 0.1;
		f->max_im += aux.range_im * 0.1;
	}
}
