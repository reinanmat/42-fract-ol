/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:09 by revieira          #+#    #+#             */
/*   Updated: 2022/11/23 17:59:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	map_re(int x, t_fractol *fractol)
{
	double	range;

	range = fractol->max_re - fractol->min_re;
	return (((x * range) + fractol->pos_x) / (WIDTH - 1) + fractol->min_re);
}

double	map_im(int y, t_fractol *fractol)
{
	double	range;

	range = fractol->max_im - fractol->min_im;
	return (((y * range) + fractol->pos_y) / (HEIGHT - 1) + fractol->min_im);
}

int	mandelbrot(double n_re, double n_im)
{
	double	temp;
	double	xx;
	double	yy;
	int		iter;

	xx = 0;
	yy = 0;
	iter = 0;
	while (iter < MAX_ITER)
	{
		temp = xx * xx - yy * yy + n_re;
		yy = 2 * xx * yy + n_im;
		xx = temp;
		if (xx * xx + yy * yy > 4)
			return (iter);
		iter++;
	}
	return (iter);
}

void	set_fractal(t_data *data)
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
			iter = mandelbrot(map_re(x, &data->fractol), map_im(y,
						&data->fractol));
			if (iter == MAX_ITER)
				img_pix_put(&data->img, x, y, 0x000000);
			else
				img_pix_put(&data->img, x, y, iter * data->color);
		}
	}
}
