/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:55:58 by revieira          #+#    #+#             */
/*   Updated: 2022/11/21 13:08:00 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    new_img(t_data *data)
{
    if (data->img.mlx_img != NULL)
        mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
    if (data->mlx_ptr != NULL)
    {
        data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
        data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
    }
}
