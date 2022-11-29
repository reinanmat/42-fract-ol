/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:46:41 by revieira          #+#    #+#             */
/*   Updated: 2022/11/29 18:50:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	set_color(int x, int y, int i, t_fractol *f)
{
	int	color;

	color = 0;
	if (i == f->max_iter)
		color = 0x000000;
	else
	{
		if (f->color == 0)
                color = i * 265;
		else if (f->color == 1)
			color = i * 285;
		else if (f->color == 2)
			color = i * 300;
		else if (f->color == 3)
			color = i * 265265;
		else if (f->color == 4)
			color = colors_set_4(i);
		else if (f->color == 5)
			color = colors_set_5(i);
	}
	img_pix_put(&f->img, x, y, color);
}

int	render(t_fractol *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	set_fractal(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.mlx_img, 0, 0);
	return (1);
}
