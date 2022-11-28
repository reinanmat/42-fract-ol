/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:03:46 by revieira          #+#    #+#             */
/*   Updated: 2022/11/28 19:08:51 by revieira         ###   ########.fr       */
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
	if (key == 65307)
		close_program(f);
	else if (key == 114)
		init_fractal(f);
	else if (key >= 65361 && key <= 65364)
		arrows(key, f);
	else if (key == 45 || key == 61)
		key_zoom(key, f);
	else if (key == 32)
	{
		if (f->color == 5)
			f->color = 0;
		else
			f->color++;
	}
	else if (key == 'a' || key == 'd')
		new_max_iter(key, f);
	ft_printf("%d\n", key);
	return (0);
}
