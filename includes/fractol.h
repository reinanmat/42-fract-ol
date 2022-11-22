/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:03:56 by revieira          #+#    #+#             */
/*   Updated: 2022/11/22 13:53:41 by revieira         ###   ########.fr       */
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

typedef struct s_fractol
{
    int     max_iter;
    double  x0;
    double  y0;
}			t_fractol;

typedef struct s_data
{
	void	    *mlx_ptr;
	void	    *win_ptr;
	int		    win_width;
	int		    win_height;
	int		    color;
	t_img	    img;
    t_fractol   fractol;
}			t_data;


//all the functions
void		close_program(t_data *data);
int			draw(t_data *data);
int			draw_l(t_data *data);
void        set_mandelbrot(int x, int y, t_data *data);
void        ft_fractal(t_data *data);
void		new_img(t_data *data);
int		    new_color(t_data *data);
int		    background(t_img *img, int color);
void		init_data(t_data *data);
int			handle_input(int key, t_data *data);
void		img_pix_put(t_img *img, int x, int y, int color);

#endif
