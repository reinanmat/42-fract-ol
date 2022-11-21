/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:35:44 by revieira          #+#    #+#             */
/*   Updated: 2022/11/21 19:32:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse(int x, int y)
{
	printf("x: %i\n", x);
	printf("y: %i\n", y);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	set_mandelbrot(int x, int y, int color, t_img *img)
{
	t_fractal	fractal;
    int         max_iter;
    int         iter;

	max_iter = 100;
	iter = -1;
	fractal.x0 = (x - WIDTH / 2 - 200) / (0.3 * WIDTH);
	fractal.y0 = (y - HEIGHT / 2) / (0.3 * HEIGHT);
	fractal.xx = 0;
	fractal.yy = 0;
	while (pow(fractal.xx, 2) + pow(fractal.yy, 2) < 4 && ++iter < max_iter)
	{
		fractal.xtemp = pow(fractal.xx, 2) - pow(fractal.yy, 2) + fractal.x0;
		fractal.yy = 2 * fractal.xx * fractal.yy + fractal.y0;
		fractal.xx = fractal.xtemp;
	}
	if (iter == max_iter)
		img_pix_put(img, x, y, color);
	else
		img_pix_put(img, x, y, 0xFFFFFF);
}

void	ft_fractal(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
            set_mandelbrot(x, y, data->color, &data->img);
		}
	}
}

void	new_img(t_data *data)
{
	if (data->img.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->mlx_ptr != NULL)
	{
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
				&data->img.line_len, &data->img.endian);
	}
}

int	draw(t_data *data)
{
	ft_fractal(data);
	//draw_l(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (1);
}

int	new_color(t_data *data)
{
	static int	i;
	int colors[8] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF, 0xFFFFFF, 0x000000};

	i = -1;
	if (i == 7)
		i = -1;
	data->color = colors[++i];
	if (data->img.mlx_img)
	{
		new_img(data);
	}
	return (0);
}

void	close_program(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	handle_input(int key, t_data *data)
{
	if (key == 99)
		new_color(data);
	if (key == 65307)
		close_program(data);
	printf("%d\n", key);
	return (0);
}

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->color = 0x000000;
}

int	render(t_data *data)
{
	draw(data);
	return (1);
}

int	main(void)
{
	t_data	data;

	init_data(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_hook(data.win_ptr, 6, 1L << 6, &mouse, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
