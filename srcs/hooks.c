/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:03:46 by revieira          #+#    #+#             */
/*   Updated: 2022/11/30 14:23:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse(int x, int y, t_fractol *f)
{
	if (f->args == 0)
	{
		f->arg_re = map_re(x, f);
		f->arg_im = map_im(y, f);
	}
	return (0);
}

void	new_max_iter(int key, t_fractol *f)
{
	if (key == 'a')
		f->max_iter += 10;
	if (key == 'd')
		f->max_iter -= 10;
}

int	handle_input(int key, t_fractol *f)
{
	if (key == XK_Escape)
		close_program(f);
	else if (key == 114)
		init_fractal(f);
	else if (key == 32)
	{
		if (f->color == 5)
			f->color = 0;
		else
			f->color++;
	}
	if (key == 'a' || key == 'd')
		new_max_iter(key, f);
	else if (key == 's' && f->fractal == 2)
		f->args = ft_invert(f->args);
	else if (key == 'z')
		zoom(0.1, 'd', f);
	else if (key == 'x')
		zoom(0.1, 'u', f);
	arrows(key, f);
	return (0);
}
