/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:00 by revieira          #+#    #+#             */
/*   Updated: 2022/12/19 14:31:26 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_program(t_fractol *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img.mlx_img);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_display(f->mlx_ptr);
	free(f->mlx_ptr);
	exit(0);
}
