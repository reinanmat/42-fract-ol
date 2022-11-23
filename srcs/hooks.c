/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:03:46 by revieira          #+#    #+#             */
/*   Updated: 2022/11/23 19:09:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse(int x, int y, t_data *data)
{
	printf("(%d, %d)\n", x, y);
	data->fractol.mouse_x = x;
	data->fractol.mouse_y = y;
	return (0);
}

int	handle_input(int key, t_data *data)
{
	if (key == 114)
		init_fractol(&data->fractol);
	else if (key == 65363)
		data->fractol.pos_x += 100;
	else if (key == 65361)
		data->fractol.pos_x -= 100;
	else if (key == 65364)
		data->fractol.pos_y += 100;
	else if (key == 65362)
		data->fractol.pos_y -= 100;
	else if (key == 45)
		data->fractol.zoom += 0.5;
	else if (key == 61)
		data->fractol.zoom -= 0.5;
	else if (key == 65307)
		close_program(data);
	else if (key == 99)
		new_color(data);
	else if (key == 65307)
		close_program(data);
	else if (key == 'a')
		data->fractol.max_iter += 10;
	else if (key == 'd')
		data->fractol.max_iter -= 10;
	printf("%d\n", key);
	return (0);
}
