/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:09 by revieira          #+#    #+#             */
/*   Updated: 2022/11/28 15:55:42 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	map_re(int x, t_fractol *f)
{
	double	range;

	range = f->max_re - f->min_re;
	return (f->min_re + (x * range) / WIDTH);
}

double	map_im(int y, t_fractol *f)
{
	double	range;

	range = f->max_im - f->min_im;
	return (f->min_im + (y * range) / HEIGHT);
}

void	set_color(int x, int y, int i, t_fractol *f)
{
	int	color;

	color = 0;
	if (i == f->max_iter)
		color = 0x000000;
	else
	{
		if (f->color == 0)
			color = i * 265;
		else if (f->color == 1)
			color = colors_set_1(i);
		else if (f->color == 2)
			color = colors_set_2(i);
		else if (f->color == 3)
			color = colors_set_3(i);
		else if (f->color == 4)
			color = colors_set_4(i);
		else if (f->color == 5)
			color = colors_set_5(i);
	}
	img_pix_put(&f->img, x, y, color);
}

void	set_fractal(t_fractol *f)
{
	double	x;
	double	y;
	int		iter;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (f->fractal == 1)
				iter = mandelbrot(map_re(x, f), map_im(y, f), f);
			else if (f->fractal == 2)
				iter = julia(map_re(x, f), map_im(y, f), f);
			else if (f->fractal == 3)
				iter = burning_ship(map_re(x, f), map_im(y, f), f);
			set_color(x, y, iter, f);
		}
	}
}
