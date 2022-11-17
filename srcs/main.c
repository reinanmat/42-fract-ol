/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:35:44 by revieira          #+#    #+#             */
/*   Updated: 2022/11/17 18:32:07 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void    img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

/*void    format(t_position *pos, t_img *img)
{
    int x;
    int y;

    pos->x = 0;
    pos->y = 0;
    pos->xx = WIDTH;
    pos->yy = HEIGHT;

    y = pos->y;
    x = pos->x;
    while (x < pos->xx && y < pos->yy)
    {
        img_pix_put(img, x, y, 0xFFFFFF);
        x++;
        y++;
    }
}*/

int background(t_img *img, int color)
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
    if (data->mlx_ptr != NULL && data->color)
    {
        //draw_forms(&data->img, (t_format){0, 0, WIDTH, HEIGHT, 0xFFFF00});
        background(&data->img, data->color);

        plot_line(&(t_pos){0, 0, WIDTH/2, HEIGHT/2}, &data->img);
        plot_line(&(t_pos){WIDTH/2, HEIGHT/2, WIDTH, 0}, &data->img);
        plot_line(&(t_pos){WIDTH/2, HEIGHT/2, WIDTH/2, HEIGHT}, &data->img);
        plot_line(&(t_pos){0, 0, WIDTH/2, HEIGHT}, &data->img);
        plot_line(&(t_pos){WIDTH, 0, WIDTH/2, HEIGHT}, &data->img);
        plot_line(&(t_pos){0, HEIGHT, WIDTH/2, HEIGHT/2}, &data->img);
        plot_line(&(t_pos){WIDTH, HEIGHT, WIDTH/2, HEIGHT/2}, &data->img);
        plot_line(&(t_pos){WIDTH/2, 0, WIDTH/2, HEIGHT/2}, &data->img);
        plot_line(&(t_pos){WIDTH/2, 0, 0, HEIGHT}, &data->img);
        plot_line(&(t_pos){WIDTH/2, 0, WIDTH, HEIGHT}, &data->img);
        plot_line(&(t_pos){0, HEIGHT/2, WIDTH, HEIGHT/2}, &data->img);
        plot_line(&(t_pos){0, HEIGHT/2, WIDTH/2, HEIGHT}, &data->img);
        plot_line(&(t_pos){WIDTH/2, HEIGHT, WIDTH, HEIGHT/2}, &data->img);
        plot_line(&(t_pos){WIDTH, HEIGHT/2, WIDTH/2, 0}, &data->img);
        plot_line(&(t_pos){WIDTH/2, 0, 0, HEIGHT/2}, &data->img); 
        plot_line(&(t_pos){0, HEIGHT/2, WIDTH, HEIGHT}, &data->img);
        plot_line(&(t_pos){0, HEIGHT/2, WIDTH, 0}, &data->img);
        plot_line(&(t_pos){WIDTH, HEIGHT/2, 0, 0}, &data->img);
        plot_line(&(t_pos){WIDTH, HEIGHT/2, 0, HEIGHT}, &data->img);
        
        //format(&data->pos, &data->img);
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    return (0);
}

void    close_program(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
}

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

void    init_data(t_data *data)
{
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
    data->color = 0x000000;
}

int new_color(t_data *data)
{
    int colors[8] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF, 0xFFFFFF, 0x000000};
    static int i = -1;

    if (i == 7)
        i = -1;
    data->color = colors[++i];
    if (data->img.mlx_img)
    {
        new_img(data);
    }
    return (0);
}

int handle_input(int key, t_data *data)
{
    if (key == 'c')
        new_color(data);
    if (key == 65307)
        close_program(data); 
    printf("%d\n", key);
    return (0);
}

int main(void)
{
    t_data data;

    init_data(&data);
    mlx_loop_hook(data.mlx_ptr, &draw, &data);
    mlx_key_hook(data.win_ptr, &handle_input, &data);
    mlx_loop(data.mlx_ptr); 
    return (0);
}

