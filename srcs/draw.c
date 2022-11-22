/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:46:41 by revieira          #+#    #+#             */
/*   Updated: 2022/11/22 12:15:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


typedef struct s_fractol
{
    int		fractol;
    int		max_iter;
    int		color;
    double	zoom;
    double	x1;
    double	y1;
}				t_fractol;

void    init_fractol(t_fractol *fractol)
{
    fractol->fractol = 1;
    fractol->max_iter = 50;
    fractol->color = 0;
    fractol->zoom = 1;
    fractol->x1 = -2.1;
    

void    set_mandelbrotv2(int x, int y, t_fractol *fractol)
{
    int     i;
    double  tmp;
    double  z_r;
    double  z_i;
    double  c_r;
    double  c_i;

    i = 0;
    z_r = 0;
    z_i = 0;
    c_r = x / fractol->zoom + fractol->x1;
    c_i = y / fractol->zoom + fractol->y1;
    while (z_r * z_r + z_i * z_i < 4 && i < fractol->max_iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_i * tmp + c_i;
        i++;
    }
    if (i == fractol->max_iter)
        my_mlx_pixel_put(fractol, x, y, 0x000000);
    else
        my_mlx_pixel_put(fractol, x, y, i * fractol->color);
}
