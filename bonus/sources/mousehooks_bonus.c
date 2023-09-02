/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:24:16 by revieira          #+#    #+#             */
/*   Updated: 2023/09/01 21:52:36 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

int	mouse(int x, int y, t_fractol *f)
{
	if (f->fractal == 2 && f->args == 0)
	{
		f->arg_re = map_re(x, f);
		f->arg_im = map_im(y, f);
	}
	return (0);
}

void	move_for_mouse(double value, char direction, t_fractol *f)
{
	double	range_re;
	double	range_im;

	range_re = f->max_re - f->min_re;
	range_im = f->max_im - f->min_im;
	if (direction == 'r')
	{
		f->min_re += range_re * value;
		f->max_re += range_re * value;
	}
	else if (direction == 'l')
	{
		f->min_re -= range_re * value;
		f->max_re -= range_re * value;
	}
	else if (direction == 'u')
	{
		f->min_im -= range_im * value;
		f->max_im -= range_im * value;
	}
	else if (direction == 'd')
	{
		f->min_im += range_im * value;
		f->max_im += range_im * value;
	}
}

int	mouse_zoom(int key, int x, int y, t_fractol *f)
{
	if (key == 4)
	{
		zoom(0.1, 'd', f);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move_for_mouse(ft_fabs(x) / WIDTH, 'l', f);
		else if (x > 0)
			move_for_mouse(x / WIDTH, 'r', f);
		if (y < 0)
			move_for_mouse(ft_fabs(y) / HEIGHT, 'u', f);
		else if (y > 0)
			move_for_mouse(y / HEIGHT, 'd', f);
	}
	if (key == 5)
		zoom(0.1, 'u', f);
	return (1);
}
