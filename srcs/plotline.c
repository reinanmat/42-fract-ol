/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:58:10 by revieira          #+#    #+#             */
/*   Updated: 2022/11/17 18:44:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int draw(t_data *data)
{
    if (data->mlx_ptr != NULL && data->color)
    {
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
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    return (0);
}

void plot_line_low(int x0, int y0, int x1, int y1, t_img *img)
{
    int dx;
    int dy;
    int yi;
    int D;
    int x;

    dx = x1 - x0;
    dy = y1 - y0;
    yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    D = 2 * dy - dx;
    x = x0;
    while (x <= x1)
    {
        img_pix_put(img, x, y0, 0xFFFFFF);
        if (D > 0)
        {
            y0 = y0 + yi;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
        x++;
    }
}

void plot_line_hight(int x0, int y0, int x1, int y1, t_img *img)
{
    int dx;
    int dy;
    int xi;
    int D;
    int y;

    dx = x1 - x0;
    dy = y1 - y0;
    xi = 1;
    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    D = 2 * dx - dy;
    y = y0;
    while (y <= y1)
    {
        img_pix_put(img, x0, y, 0xFFFFFF);
        if (D > 0)
        {
            x0 = x0 + xi;
            D = D - 2 * dy;
        }
        D = D + 2 * dx;
        y++;
    }
}

void plot_line(t_pos *pos, t_img *img)
{
    if (abs(pos->y1 - pos->y0) < abs(pos->x1 - pos->x0))
    {
        if (pos->x0 > pos->x1)
            plot_line_low(pos->x1, pos->y1, pos->x0, pos->y0, img);
        else
            plot_line_low(pos->x0, pos->y0, pos->x1, pos->y1, img);
    }
    else
    {
        if (pos->y0 > pos->y1)
            plot_line_hight(pos->x1, pos->y1, pos->x0, pos->y0, img);
        else
            plot_line_hight(pos->x0, pos->y0, pos->x1, pos->y1, img);
    }
}
