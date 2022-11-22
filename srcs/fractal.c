/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:09 by revieira          #+#    #+#             */
/*   Updated: 2022/11/22 16:52:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_mandelbrot(int x, int y, t_data *data)
{
    double      xtemp;
    double      xx;
    double      yy;
    int         iter;

	iter = -1;
	data->fractol.x0 = (x - WIDTH / 2 - 170) / (0.35 * WIDTH);
	data->fractol.y0 = (y - HEIGHT / 2) / (0.35 * HEIGHT);
	xx = 0;
	yy = 0;
	while (xx * xx + yy * yy < 4 && ++iter < data->fractol.max_iter)
	{
		xtemp = xx * xx - yy * yy + data->fractol.x0;
		yy = 2 * xx * yy + data->fractol.y0;
		xx = xtemp;
	}
	if (iter == data->fractol.max_iter)
		img_pix_put(&data->img, x, y, 0x000000);
	else
		img_pix_put(&data->img, x, y, iter * data->color);
}

void	ft_fractal(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
            set_mandelbrot(x, y, data);
		}
	}
}
