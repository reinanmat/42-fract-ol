/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_tricorn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:41:37 by revieira          #+#    #+#             */
/*   Updated: 2022/11/30 18:27:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_tricorn(t_fractol *f)
{
	f->min_re = -2.1;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = (f->max_re - f->min_re) * HEIGHT / WIDTH + f->min_im;
	f->max_iter = 100;
	f->color = 0;
}

int	tricorn(double n_re, double n_im, t_fractol *f)
{
	double	xx;
	double	yy;
	double	temp;
	int		iter;

	xx = n_re;
	yy = n_im;
	iter = 0;
	while (iter < f->max_iter)
	{
		temp = xx * xx - yy * yy + n_re;
		yy = -2 * xx * yy + n_im;
		xx = temp;
		if (xx * xx + yy * yy > 4)
			return (iter);
		iter++;
	}
	return (iter);
}
