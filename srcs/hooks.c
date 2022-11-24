/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:03:46 by revieira          #+#    #+#             */
/*   Updated: 2022/11/24 15:23:10 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse(int x, int y, t_fractol *f)
{
	printf("(%d, %d)\n", x, y);
	f->mouse_x = x;
	f->mouse_y = y;
	return (0);
}

int	handle_input(int key, t_fractol *f)
{
	if (key == 114)
    {
        if (f->fractal == 1)
            init_mandelbrot(f);
        else if (f->fractal == 2)
            init_julia(f);
    }
	else if (key == 65363)
		f->pos_x += 100;
	else if (key == 65361)
		f->pos_x -= 100;
	else if (key == 65364)
		f->pos_y += 100;
	else if (key == 65362)
		f->pos_y -= 100;
	else if (key == 45)
		f->zoom += 0.5;
	else if (key == 61)
		f->zoom -= 0.5;
	else if (key == 65307)
		close_program(f);
	else if (key == 99)
		new_color(f);
	else if (key == 65307)
		close_program(f);
	else if (key == 'a')
		f->max_iter += 10;
	else if (key == 'd')
		f->max_iter -= 10;
	ft_printf("%d\n", key);
	return (0);
}
