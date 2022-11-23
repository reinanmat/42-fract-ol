/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:46:41 by revieira          #+#    #+#             */
/*   Updated: 2022/11/23 17:40:32 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	new_color(t_data *data)
{
	static int	i;

	i = i + 0x010203;
	data->color = i;
	if (data->img.mlx_img)
	{
		new_img(data);
	}
	return (0);
}

int	render(t_data *data)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
	set_fractal(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
                            data->img.mlx_img, 0, 0);
	return (1);
}
