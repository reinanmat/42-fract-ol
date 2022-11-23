/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:03:56 by revieira          #+#    #+#             */
/*   Updated: 2022/11/23 18:33:35 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdio.h> //delet
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 10

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_fractol
{
	int			max_iter;
	double		pos_x;
	double		pos_y;
	int			mouse_x;
	int			mouse_y;
	double		x0;
	double		y0;
	double		width;
	double		height;
	double		zoom;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
}				t_fractol;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	int			color;
	t_img		img;
	t_fractol	fractol;
}				t_data;

//all the functions
void			close_program(t_data *data);

double			map_re(int x, t_fractol *fractol);
double			map_im(int y, t_fractol *fractol);
void			set_fractal(t_data *data);
int			    mandelbrot(double n_re, double n_im);

void            check_args(int argc, char **argv, t_data *data);

int				mouse(int x, int y, t_data *data);
void			init_data(t_data *data);
void			new_img(t_data *data);
int				new_color(t_data *data);
void            colors(t_data *data, int i);
int				background(t_img *img, int color);
int				render(t_data *data);
void			init_data(t_data *data);
void			init_fractol(t_fractol *fractol);
int				handle_input(int key, t_data *data);
void			img_pix_put(t_img *img, int x, int y, int color);

#endif
