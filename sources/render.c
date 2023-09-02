/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:46:41 by revieira          #+#    #+#             */
/*   Updated: 2023/09/01 22:01:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

double	map_re(int x, t_fractol *f)
{
	double	range;

	range = f->max_re - f->min_re;
	return (f->min_re + (x * range) / WIDTH);
}

double	map_im(int y, t_fractol *f)
{
	double	range;

	range = f->max_im - f->min_im;
	return (f->min_im + (y * range) / HEIGHT);
}

void	set_fractal(t_fractol *f)
{
	double	x;
	double	y;
	int		iter;

	x = -1;
	iter = 0;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (f->fractal == 1)
				iter = mandelbrot(map_re(x, f), map_im(y, f), f);
			else if (f->fractal == 2)
				iter = julia(map_re(x, f), map_im(y, f), f);
			if (iter == f->max_iter)
				img_pix_put(&f->img, x, y, 0x000000);
			else
				img_pix_put(&f->img, x, y, f->color * iter * iter);
		}
	}
}

int	render(t_fractol *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	set_fractal(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.mlx_img, 0, 0);
	return (1);
}
