/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:35:44 by revieira          #+#    #+#             */
/*   Updated: 2022/11/24 15:27:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mandelbrot(t_fractol *f)
{
	f->pos_x = 0;
	f->pos_y = 0;
	f->zoom = 1;
	f->min_re = -2.1;
	f->max_re = 0.6;
	f->min_im = -1.2;
	f->max_im = 1.2;
    f->max_iter = 100;
    f->color = 265;
}

void    init_julia(t_fractol *f)
{
	f->pos_x = 0;
	f->pos_y = 0;
	f->zoom = 1;
	f->min_re = -1.8;
	f->max_re = 1.8;
	f->min_im = -1.2;
	f->max_im = 1.2;
    f->max_iter = 100; 
    f->color = 265;
}

void	init_data(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	f->img.mlx_img = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.mlx_img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
    if (f->fractal == 1)
        init_mandelbrot(f);
    else if (f->fractal == 2)
        init_julia(f);
}

void	close_program(t_fractol *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img.mlx_img);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_display(f->mlx_ptr);
	free(f->mlx_ptr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (!(check_args(argc, argv, &f)))
		return (0);
	init_data(&f);
	mlx_loop_hook(f.mlx_ptr, &render, &f);
	mlx_key_hook(f.win_ptr, &handle_input, &f);
	mlx_hook(f.win_ptr, 6, 1L << 6, &mouse, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
