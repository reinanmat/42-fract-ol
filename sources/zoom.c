/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:45:28 by revieira          #+#    #+#             */
/*   Updated: 2022/11/30 18:37:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(double zoom, char up_down, t_fractol *f)
{
	if (up_down == 'd')
	{
		f->min_re += (f->max_im - f->min_im) * zoom;
		f->max_re -= (f->max_im - f->min_im) * zoom;
		f->min_im += (f->max_re - f->min_re) * zoom;
		f->max_im = (f->max_re - f->min_re) * HEIGHT / WIDTH + f->min_im;
	}
	else if (up_down == 'u')
	{
		f->min_re -= (f->max_im - f->min_im) * zoom;
		f->max_re += (f->max_im - f->min_im) * zoom;
		f->min_im -= (f->max_re - f->min_re) * zoom;
		f->max_im = (f->max_re - f->min_re) * HEIGHT / WIDTH + f->min_im;
	}
}
