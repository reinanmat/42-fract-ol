/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:03:56 by revieira          #+#    #+#             */
/*   Updated: 2022/11/21 19:30:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h> //delet
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_pos
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}			t_pos;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	int		color;
	t_img	img;
	t_pos	pos;
}			t_data;

typedef struct s_fractal
{
    int     x;
    int     y;
    double  x0;
    double  y0;
    double  xx;
    double  yy;
    double  xtemp;
}			t_fractal;

//all the functions
void		close_program(t_data *data);
int			draw(t_data *data);
int			draw_l(t_data *data);
void        set_mandelbrot(int x, int y, int color, t_img *img);
void        ft_fractal(t_data *data);
void		new_img(t_data *data);
int		    new_color(t_data *data);
int		    background(t_img *img, int color);
void		init_data(t_data *data);
int			handle_input(int key, t_data *data);
void		img_pix_put(t_img *img, int x, int y, int color);
void		plot_line(t_pos *pos, t_img *img);
void		plot_line_low(int x0, int y0, int x1, int y1, t_img *img);
void		plot_line_hight(int x0, int y0, int x1, int y1, t_img *img);

#endif
