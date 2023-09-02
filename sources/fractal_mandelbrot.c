/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:41:09 by revieira          #+#    #+#             */
/*   Updated: 2023/09/01 22:00:30 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractol *f)
{
	f->min_re = -2.2;
	f->max_re = 1.0;
	f->min_im = -1.5;
	f->max_im = (f->max_re - f->min_re) * HEIGHT / WIDTH + f->min_im;
	f->max_iter = 100;
	f->color = 265;
}

int	mandelbrot(double n_re, double n_im, t_fractol *f)
{
	double	xx;
	double	yy;
	double	temp;
	int		iter;

	xx = 0;
	yy = 0;
	iter = 0;
	while (iter < f->max_iter)
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
