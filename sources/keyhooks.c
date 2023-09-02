/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:03:46 by revieira          #+#    #+#             */
/*   Updated: 2022/12/20 12:27:34 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	new_max_iter(int key, t_fractol *f)
{
	if (key == 'a')
		f->max_iter += 10;
	if (key == 'd')
		f->max_iter -= 10;
}

void	key_zoom(int key, t_fractol *f)
{
	if (key == 'z')
	{
		f->min_re -= f->min_re * 0.1;
		f->max_re -= f->max_re * 0.1;
		f->min_im -= f->min_im * 0.1;
		f->max_im -= f->max_im * 0.1;
	}
	else if (key == 'x')
	{
		f->min_re += f->min_re * 0.1;
		f->max_re += f->max_re * 0.1;
		f->min_im += f->min_im * 0.1;
		f->max_im += f->max_im * 0.1;
	}
}

int	handle_input(int key, t_fractol *f)
{
	if (key == XK_Escape)
		close_program(f);
	else if (key == 114)
		init_fractal(f);
	else if (key == 'a' || key == 'd')
		new_max_iter(key, f);
	else if (key == 'z' || key == 'x')
		key_zoom(key, f);
	return (0);
}
