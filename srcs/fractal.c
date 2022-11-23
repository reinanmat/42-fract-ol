/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:09 by revieira          #+#    #+#             */
/*   Updated: 2022/11/23 19:44:07 by revieira         ###   ########.fr       */
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

int julia(double n_re, double n_im, t_fractol *fractol)
{
    double	xx;
    double	yy;
    double  temp;
    int		iter;

    iter = 0;
    xx = n_re;
    yy = n_im;
    while (iter < fractol->max_iter)
    {
        temp = xx * xx - yy * yy + fractol->arg_re;
        yy = 2 * xx * yy + fractol->arg_im;
        xx = temp;
        if (xx * xx + yy * yy > 4)
            break ;
        iter++;
    }
    return (iter);
}

int	mandelbrot(double n_re, double n_im, t_fractol *fractol)
{
	double	xx;
	double	yy;
	double	temp;
	int		iter;

	xx = 0;
	yy = 0;
	iter = 0;
	while (iter < fractol->max_iter)
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
            if (data->fractol.fractal == 1)
                iter = mandelbrot(map_re(x, &data->fractol), map_im(y, &data->fractol), &data->fractol);
            else
                iter = julia(map_re(x, &data->fractol), map_im(y, &data->fractol), &data->fractol);
			if (iter == data->fractol.max_iter)
				img_pix_put(&data->img, x, y, 0x000000);
			else
				img_pix_put(&data->img, x, y, iter * data->color);
		}
	}
}
