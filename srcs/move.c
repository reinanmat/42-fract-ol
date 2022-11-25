/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:24:16 by revieira          #+#    #+#             */
/*   Updated: 2022/11/25 16:33:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	arrows(int key, t_fractol *f)
{
	t_aux	aux;

	aux.range_re = f->max_re - f->min_re;
	aux.range_im = f->max_im - f->min_im;
	if (key == 65362)
	{
		f->min_im -= aux.range_im * 0.1;
		f->max_im -= aux.range_im * 0.1;
	}
	if (key == 65364)
	{
		f->min_im += aux.range_im * 0.1;
		f->max_im += aux.range_im * 0.1;
	}
	if (key == 65361)
	{
		f->min_re -= aux.range_re * 0.1;
		f->max_re -= aux.range_re * 0.1;
	}
	if (key == 65363)
	{
		f->min_re += aux.range_re * 0.1;
		f->max_re += aux.range_re * 0.1;
	}
}
