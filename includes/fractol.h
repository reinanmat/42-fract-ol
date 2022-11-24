/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:03:56 by revieira          #+#    #+#             */
/*   Updated: 2022/11/24 18:54:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

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
    void        *mlx_ptr;
    void        *win_ptr;
	int			max_iter;
	int			fractal;
	int			color;
	double		pos_x;
	double		pos_y;
	double		x0;
	double		y0;
	double		zoom;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		arg_re;
	double		arg_im;
	double		mouse_x;
	double		mouse_y;
    t_img       img;
}				t_fractol;

//all the functions
void			close_program(t_fractol *f);

double			map_re(int x, t_fractol *f);
double			map_im(int y, t_fractol *f);
void			set_fractal(t_fractol *f);
int				julia(double n_re, double n_im, t_fractol *f);
int				mandelbrot(double n_re, double n_im, t_fractol *f);
int				burning_ship(double n_re, double n_im, t_fractol *f);

int				check_args(int argc, char **argv, t_fractol *f);

void			init_data(t_fractol *fractol);
void			init_julia(t_fractol *f);
void			init_mandelbrot(t_fractol *f);
void			init_burning_ship(t_fractol *f);

int				mouse(int x, int y, t_fractol *f);
void			new_img(t_fractol *f);
int				new_color(t_fractol *f);
void			colors(t_fractol *f, int i);
int				render(t_fractol *f);
int				handle_input(int key, t_fractol *f);
void			img_pix_put(t_img *img, int x, int y, int color);

#endif
