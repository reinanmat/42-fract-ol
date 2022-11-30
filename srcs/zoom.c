/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:45:28 by revieira          #+#    #+#             */
/*   Updated: 2022/11/30 14:12:46 by revieira         ###   ########.fr       */
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
		f->max_im = (f->max_re - f->min_re) * HEIGHT / WIDTH + f->min_im ;
	}
}

void	resize(double value, char direction, t_fractol *f)
{
	t_aux	aux;

	aux.range_re = f->max_re - f->min_re;
	aux.range_im = f->max_im - f->min_im;
	if (direction == 'r')
	{
		f->min_re += aux.range_re * value;
		f->max_re += aux.range_re * value;
	}
	else if (direction == 'l')
	{
		f->min_re -= aux.range_re * value;
		f->max_re -= aux.range_re * value;
	}
	else if (direction == 'u')
	{
		f->min_im -= aux.range_im * value;
		f->max_im -= aux.range_im * value;
	}
	else if (direction == 'd')
	{
		f->min_im += aux.range_im * value;
		f->max_im += aux.range_im * value;
	}
}

int	mouse_zoom(int key, int x, int y, t_fractol *f)
{
	t_aux	aux;

	aux.range_re = f->max_re - f->min_re;
	aux.range_im = f->max_im - f->min_im;
	if (key == 4)
	{
		zoom(0.1, 'd', f);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			resize(ft_fabs(x) / (double)WIDTH, 'l', f);
		else if (x > 0)
			resize(x / (double)WIDTH, 'r', f);
		if (y < 0)
			resize(ft_fabs(y) / (double)HEIGHT, 'u', f);
		else if (y > 0)
			resize(y / (double)HEIGHT, 'd', f);
	}
	if (key == 5)
		zoom(0.1, 'u', f);
	return (1);
}
