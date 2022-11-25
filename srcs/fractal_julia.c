/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:42:29 by revieira          #+#    #+#             */
/*   Updated: 2022/11/25 16:30:20 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(double n_re, double n_im, t_fractol *fractol)
{
	double	xx;
	double	yy;
	double	temp;
	int		iter;

	iter = 0;
	xx = n_re;
	yy = n_im;
	while (iter < fractol->max_iter)
	{
		temp = xx * xx - yy * yy + fractol->arg_re;
		yy = 2 * xx * yy - fractol->arg_im;
		xx = temp;
		if (xx * xx + yy * yy > 4)
			break ;
		iter++;
	}
	return (iter);
}
