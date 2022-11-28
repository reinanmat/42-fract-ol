/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:41:09 by revieira          #+#    #+#             */
/*   Updated: 2022/11/28 16:29:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
