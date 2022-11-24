/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:46:41 by revieira          #+#    #+#             */
/*   Updated: 2022/11/24 15:28:20 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	new_color(t_fractol *f)
{
	static int	i;

	i = i + 0x010203;
	f->color = i;
	return (0);
}

int	render(t_fractol *f)
{
    mlx_clear_window(f->mlx_ptr, f->win_ptr);
	set_fractal(f);
    mlx_put_image_to_window(f->mlx_ptr, f->win_ptr,
                            f->img.mlx_img, 0, 0);
	return (1);
}
