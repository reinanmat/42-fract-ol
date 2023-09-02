/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:10:16 by revieira          #+#    #+#             */
/*   Updated: 2023/09/01 21:52:31 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (!(check_args(argc, argv, &f)))
		return (-1);
	if (!(init_data(&f)))
		return (-1);
	mlx_loop_hook(f.mlx_ptr, &render, &f);
	mlx_hook(f.win_ptr, 2, 1L << 0, &handle_input, &f);
	mlx_hook(f.win_ptr, 17, 0L, &close_program, &f);
	mlx_hook(f.win_ptr, 6, 1L << 6, &mouse, &f);
	mlx_hook(f.win_ptr, 4, 1L << 2, &mouse_zoom, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
