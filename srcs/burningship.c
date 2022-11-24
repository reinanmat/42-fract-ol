/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:46:57 by revieira          #+#    #+#             */
/*   Updated: 2022/11/24 19:04:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double  ft_fabs(double x)
{
    if (x < 0)
        return (-x);
    return (x);
}

int	burning_ship(double n_re, double n_im, t_fractol *fractol)
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
        yy = ft_fabs(2 * xx * yy) + n_im;
        xx = temp;
        if (xx * xx + yy * yy > 4)
            return (iter);
        iter++;
    }
    return (iter);
}
/*{
	double	xx;
	double	yy;
	double	temp;
	int		iter;

	xx = n_re;
	yy = n_im;
	iter = 0;
	while (iter < fractol->max_iter)
	{
		temp = xx * xx - yy * yy + n_re;
		yy = ft_fabs(2 * xx * yy) + n_im;
		xx = temp;
		if (xx * xx + yy * yy > 4)
			return (iter);
		iter++;
	}
	return (iter);
}
*/
