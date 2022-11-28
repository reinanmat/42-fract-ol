/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:45:28 by revieira          #+#    #+#             */
/*   Updated: 2022/11/28 19:45:56 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	key_zoom(int key, t_fractol *f)
{
	t_aux	aux;

	aux.range_re = f->max_re - f->min_re;
	aux.range_im = f->max_im - f->min_im;
	if (key == 61)
	{
		f->min_re += aux.range_re * 0.1;
		f->max_re -= aux.range_re * 0.1;
		f->min_im += aux.range_im * 0.1;
		f->max_im -= aux.range_im * 0.1;
	}
	if (key == 45)
	{
		f->min_re -= aux.range_re * 0.1;
		f->max_re += aux.range_re * 0.1;
		f->min_im -= aux.range_im * 0.1;
		f->max_im += aux.range_im * 0.1;
	}
}
