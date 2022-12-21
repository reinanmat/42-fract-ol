/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:03:56 by revieira          #+#    #+#             */
/*   Updated: 2022/12/21 14:22:10 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../../Libft/includes/ft_printf.h"
# include "../../../Libft/includes/libft.h"
# include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000.00
# define HEIGHT 1000.00

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
	void	*mlx_ptr;
	void	*win_ptr;
	int		max_iter;
	int		fractal;
	int		color;
	double	x0;
	double	y0;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	int		args;
	double	arg_re;
	double	arg_im;
	t_img	img;
}			t_fractol;

int			check_args(int argc, char **argv, t_fractol *f);
int			check_fractal(char *str);
int			check_julia(int argc, char **argv, t_fractol *f);
int			msg_error(void);

int			init_data(t_fractol *fractol);
void		init_fractal(t_fractol *f);
void		init_julia(t_fractol *f);
void		init_mandelbrot(t_fractol *f);
void		init_burning_ship(t_fractol *f);
void		init_tricorn(t_fractol *f);

void		set_fractal(t_fractol *f);
double		map_re(int x, t_fractol *f);
double		map_im(int y, t_fractol *f);
int			julia(double n_re, double n_im, t_fractol *f);
int			mandelbrot(double n_re, double n_im, t_fractol *f);
int			burning_ship(double n_re, double n_im, t_fractol *f);
int			tricorn(double n_re, double n_im, t_fractol *f);

int			mouse(int x, int y, t_fractol *f);
int			handle_input(int key, t_fractol *f);
void		arrows(int key, t_fractol *f);
void		new_max_iter(int key, t_fractol *f);
void		zoom(double zoom, char up_down, t_fractol *f);
void		move_for_mouse(double value, char direction, t_fractol *f);
int			mouse_zoom(int key, int x, int y, t_fractol *f);
void		key_zoom(int key, t_fractol *f);

int			render(t_fractol *f);
void		img_pix_put(t_img *img, int x, int y, int color);
void		set_color(int x, int y, int i, t_fractol *f);
int			colors_set_1(int n);
int			colors_set_2(int n);
int			colors_set_3(int n);
int			colors_set_4(int n);

int			ft_invert(int n);
int			check_double(const char *str);
double		ft_fabs(double n);
double		ft_atof(const char *str);

int			close_program(t_fractol *f);

#endif
