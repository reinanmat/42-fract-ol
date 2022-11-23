/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:05:18 by revieira          #+#    #+#             */
/*   Updated: 2022/11/23 18:33:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int     check_args(int argc, char **argv, t_data *data)
{
    if (argc != 2)
    {
        ft_printf("Usage: ./fractol [fractal]\n");
        return (0);
    }
    if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1], "julia") != 0)
    {
        ft_printf("Usage: ./fractol [fractal]\n");
        return (0);
    }
    return (1);
}
