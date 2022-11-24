/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:55:58 by revieira          #+#    #+#             */
/*   Updated: 2022/11/24 15:29:28 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	new_img(t_fractol *f)
{
	if (f->img.mlx_img != NULL)
		mlx_destroy_image(f->mlx_ptr, f->img.mlx_img);
	if (f->mlx_ptr != NULL)
	{
		f->img.mlx_img = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
		f->img.addr = mlx_get_data_addr(f->img.mlx_img, &f->img.bpp,
				&f->img.line_len, &f->img.endian);
	}
}
