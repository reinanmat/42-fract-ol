/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:24:16 by revieira          #+#    #+#             */
/*   Updated: 2023/09/01 22:01:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int key, int x, int y, t_fractol *f)
{
	x = 1;
	y = 1;
	if (key == 4 && x)
	{
		f->min_re -= f->min_re * 0.1;
		f->max_re -= f->max_re * 0.1;
		f->min_im -= f->min_im * 0.1;
		f->max_im -= f->max_im * 0.1;
	}
	if (key == 5 && y)
	{
		f->min_re += f->min_re * 0.1;
		f->max_re += f->max_re * 0.1;
		f->min_im += f->min_im * 0.1;
		f->max_im += f->max_im * 0.1;
	}
	return (1);
}
