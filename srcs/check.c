/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:05:18 by revieira          #+#    #+#             */
/*   Updated: 2022/11/23 19:49:56 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    msg_error(void)
{
    ft_printf("Usage: ./fractol [fractal]\n");
    ft_printf("Available fractals:\n");
    ft_printf("1. Mandelbrot\n");
    ft_printf("2. Julia\n");
}

int     check_args(int argc, char **argv, t_data *data)
{
    if (argc != 2)
    {
        msg_error();
        return (0);
    }
    /*if (ft_strncmp(argv[1], "mandelbrot", 11) != 0 && ft_strncmp(argv[1], "julia", 5) != 0)
    {
        msg_error();
        return (0);
    }*/
    //else
    //{
        if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
            data->fractol.fractal = 1;
        else
        {
            data->fractol.fractal = 2;
            data->fractol.arg_re =  0.4;
            data->fractol.arg_im = 0.6;
        }
    //}
    return (1);
}
