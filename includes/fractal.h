/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:03:56 by revieira          #+#    #+#             */
/*   Updated: 2022/11/17 18:32:53 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h> //delet

# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct s_pos
{
    int x0;
    int y0;
    int x1;
    int y1;
}   t_pos;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     win_width;
    int     win_height;
    int     color;
    t_img   img;
    t_pos pos;
}   t_data;

void    new_img(t_data *data);
int     draw(t_data *data);
void    img_pix_put(t_img *img, int x, int y, int color);
void    plot_line(t_pos *pos, t_img *img);
void    plot_line_low(int x0, int y0, int x1, int y1, t_img *img);
void    plot_line_hight(int x0, int y0, int x1, int y1, t_img *img);

#endif
