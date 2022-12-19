/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:46:41 by revieira          #+#    #+#             */
/*   Updated: 2022/12/19 16:35:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render(t_fractol *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	set_fractal(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.mlx_img, 0, 0);
	return (1);
}
