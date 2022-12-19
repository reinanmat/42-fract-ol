/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:09 by revieira          #+#    #+#             */
/*   Updated: 2022/11/30 18:14:31 by revieira         ###   ########.fr       */
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
			else if (f->fractal == 4)
				iter = tricorn(map_re(x, f), map_im(y, f), f);
			set_color(x, y, iter, f);
		}
	}
}
