/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:35:44 by revieira          #+#    #+#             */
/*   Updated: 2022/11/23 18:23:34 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->max_iter = 10;
    fractol->pos_x = 0;
    fractol->pos_y = 0;
	fractol->zoom = 1;
    fractol->pos_x = 0;
    fractol->pos_y = 0;
	fractol->min_re = -2.1;
    fractol->max_re = 0.6;
    fractol->min_im = -1.2;
    fractol->max_im = 1.2;
    fractol->height = HEIGHT;
    fractol->width = WIDTH;
}

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->color = 265;
	init_fractol(&data->fractol);
}

void	close_program(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

    if (check_args(argc, argv, &data) == 0)
        return (0);
	init_data(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_hook(data.win_ptr, 6, 1L << 6, &mouse, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
