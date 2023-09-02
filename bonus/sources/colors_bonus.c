/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:52:57 by revieira          #+#    #+#             */
/*   Updated: 2023/09/01 21:51:26 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	colors_set_1(int n)
{
	int	color;

	color = 0;
	if (n % 8 == 7)
		color = 0x0000FF;
	else if (n % 8 == 6)
		color = 0x00FF00;
	else if (n % 8 == 5)
		color = 0x00FFFF;
	else if (n % 8 == 4)
		color = 0xFF0000;
	else if (n % 8 == 3)
		color = 0xFF00FF;
	else if (n % 8 == 2)
		color = 0xFFFF00;
	else if (n % 8 == 1)
		color = 0xFFFFFF;
	else if (n % 8 == 0)
		color = 0x000000;
	return (color);
}

int	colors_set_2(int n)
{
	int	color;

	color = 0;
	if (n % 8 == 7)
		color = 0x0000FF;
	else if (n % 8 == 6)
		color = 0x0000AA;
	else if (n % 8 == 5)
		color = 0x000055;
	else if (n % 8 == 4)
		color = 0x000000;
	else if (n % 8 == 3)
		color = 0x550000;
	else if (n % 8 == 2)
		color = 0xAA0000;
	else if (n % 8 == 1)
		color = 0xFF0000;
	else if (n % 8 == 0)
		color = 0xFFFFFF;
	return (color);
}

int	colors_set_3(int n)
{
	int	color;

	color = 0;
	if (n % 8 == 7)
		color = 0x000000;
	else if (n % 8 == 6)
		color = 0x111111;
	else if (n % 8 == 5)
		color = 0x222222;
	else if (n % 8 == 4)
		color = 0x333333;
	else if (n % 8 == 3)
		color = 0x444444;
	else if (n % 8 == 2)
		color = 0x555555;
	else if (n % 8 == 1)
		color = 0x666666;
	else if (n % 8 == 0)
		color = 0x777777;
	return (color);
}

int	colors_set_4(int n)
{
	int	color;

	color = 0;
	if (n % 8 == 7)
		color = 0xff5232;
	else if (n % 8 == 6)
		color = 0xFF0000;
	else if (n % 8 == 5)
		color = 0xd11507;
	else if (n % 8 == 4)
		color = 0xa51b0b;
	else if (n % 8 == 3)
		color = 0x7a1b0c;
	else if (n % 8 == 2)
		color = 0x52170b;
	else if (n % 8 == 1)
		color = 0x2d1106;
	else if (n % 8 == 0)
		color = 0x000000;
	return (color);
}

void	set_color(int x, int y, int i, t_fractol *f)
{
	int	color;

	color = 0;
	if (i == f->max_iter)
		color = 0x000000;
	else if (f->color == 0)
		color = 265 * i;
	else if (f->color == 1)
		color = colors_set_1(i);
	else if (f->color == 2)
		color = colors_set_2(i);
	else if (f->color == 3)
		color = colors_set_3(i);
	else if (f->color == 4)
		color = colors_set_4(i);
	img_pix_put(&f->img, x, y, color);
}
