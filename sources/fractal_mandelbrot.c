/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:41:09 by revieira          #+#    #+#             */
/*   Updated: 2022/12/08 16:20:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mandelbrot(t_fractol *f)
{
	f->min_re = -2.1;
	f->max_re = 0.6;
	f->min_im = -1.2;
	f->max_im = (f->max_re - f->min_re) * HEIGHT / WIDTH + f->min_im;
	f->max_iter = 100;
	f->color = 0;
	f->args = 0;
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
