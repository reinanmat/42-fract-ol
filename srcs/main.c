/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:35:44 by revieira          #+#    #+#             */
/*   Updated: 2022/11/16 20:13:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void    img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

int draw_forms(t_img *img, int color)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT) 
    {
        x = 0;
        while (x < WIDTH)
            img_pix_put(img, x++, y, color);
        y++;
    }
    return (0);
}

int draw(t_data *data)
{
    if (data->mlx_ptr != NULL)
    {
        //draw_forms(&data->img, (t_format){0, 0, WIDTH, HEIGHT, 0xFFFF00});
        draw_forms(&data->img, 0x0000FF);
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    return (0);
}

int handle_input(int key, t_data *data)
{
    if (key == 65307)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        if (data->mlx_ptr)
            free(data->mlx_ptr);
        exit(0);
    }
    printf("%d\n", key);
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (-1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (-1);
    }
    data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
    data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
    mlx_loop_hook(data.mlx_ptr, &draw, &data);
    mlx_key_hook(data.win_ptr, &handle_input, &data);
    mlx_loop(data.mlx_ptr);
    mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
    if (data.img.mlx_img)
        free(data.img.mlx_img);
    return (0);
}

