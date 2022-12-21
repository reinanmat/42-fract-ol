/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:05:18 by revieira          #+#    #+#             */
/*   Updated: 2022/12/21 14:16:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	msg_error(void)
{
	ft_printf("Usage: ./fractol [fractal]\n");
	ft_printf("Available fractals:\n");
	ft_printf("1. Mandelbrot\n");
	ft_printf("2. Julia [p_re] [p_im] \n");
	ft_printf("[p_re] the real part of the parameter\n");
	ft_printf("[p_im] the imaginary part of the parameter\n");
	ft_printf("p_re = -2.0 up to 2.0\n");
	ft_printf("p_im = -2.0 up to 2.0\n");
	ft_printf("suger: -0.8 0.156 | -0.4 0.6 | 0.285 0 | 0.45 0.1428\n");
	return (0);
}

int	check_fractal(char *str)
{
	if (ft_strncmp(str, "Mandelbrot", 11) == 0)
		return (1);
	else if (ft_strncmp(str, "Julia", 5) == 0)
		return (2);
	return (0);
}

int	check_julia(int argc, char **argv, t_fractol *f)
{
	if (argc != 4)
		return (0);
	f->arg_re = ft_atof(argv[2]);
	if (f->arg_re < -2.0 || f->arg_re > 2.0)
		return (0);
	if (!(check_double(argv[2])))
		return (0);
	if (!check_double(argv[3]))
		return (0);
	f->arg_re = ft_atof(argv[2]);
	f->arg_im = ft_atof(argv[3]);
	if (f->arg_im < -2 || f->arg_im > 2)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv, t_fractol *f)
{
	if (argc < 2 || argc > 4)
		return (msg_error());
	f->fractal = check_fractal(argv[1]);
	if (f->fractal == 0)
		return (msg_error());
	if (f->fractal != 2 && argc != 2)
		return (msg_error());
	if (f->fractal == 2 && !(check_julia(argc, argv, f)))
		return (msg_error());
	return (1);
}
