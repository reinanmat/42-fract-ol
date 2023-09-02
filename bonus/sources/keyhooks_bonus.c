/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:03:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/01 22:35:35 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	arrows(int key, t_fractol *f)
{
	double	range_re;
	double	range_im;

	range_re = f->max_re - f->min_re;
	range_im = f->max_im - f->min_im;
	if (key == XK_Left)
	{
		f->min_re -= range_re * 0.1;
		f->max_re -= range_re * 0.1;
	}
	else if (key == XK_Right)
	{
		f->min_re += range_re * 0.1;
		f->max_re += range_re * 0.1;
	}
	else if (key == XK_Up)
	{
		f->min_im -= range_im * 0.1;
		f->max_im -= range_im * 0.1;
	}
	else if (key == XK_Down)
	{
		f->min_im += range_im * 0.1;
		f->max_im += range_im * 0.1;
	}
}

void	new_max_iter(int key, t_fractol *f)
{
	if (key == 'a')
		f->max_iter += 10;
	if (key == 'd')
		f->max_iter -= 10;
}

void	key_zoom(int key, t_fractol *f)
{
	double	range_re;
	double	range_im;

	range_re = f->max_re - f->min_re;
	range_im = f->max_im - f->min_im;
	if (key == 'z')
	{
		f->min_re += range_re * 0.1;
		f->max_re -= range_re * 0.1;
		f->min_im += range_im * 0.1;
		f->max_im -= range_im * 0.1;
	}
	else if (key == 'x')
	{
		f->min_re -= range_re * 0.1;
		f->max_re += range_re * 0.1;
		f->min_im -= range_im * 0.1;
		f->max_im += range_im * 0.1;
	}
}

int	handle_input(int key, t_fractol *f)
{
	if (key == XK_Escape)
		close_program(f);
	else if (key == 114)
		init_fractal(f);
	else if (key == 32)
	{
		if (f->color == 4)
			f->color = 0;
		else
			f->color++;
	}
	if (key == 'a' || key == 'd')
		new_max_iter(key, f);
	else if (key == 's' && f->fractal == 2)
		f->args = !f->args;
	else if (key == 'z' || key == 'x')
		key_zoom(key, f);
	arrows(key, f);
	return (0);
}
