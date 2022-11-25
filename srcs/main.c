/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:10:16 by revieira          #+#    #+#             */
/*   Updated: 2022/11/25 16:30:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (!(check_args(argc, argv, &f)))
		return (0);
	init_data(&f);
	mlx_loop_hook(f.mlx_ptr, &render, &f);
	mlx_key_hook(f.win_ptr, &handle_input, &f);
	mlx_hook(f.win_ptr, 6, 1L << 6, &mouse, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
