/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:52:57 by revieira          #+#    #+#             */
/*   Updated: 2022/11/28 17:38:47 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	colors_set_1(int n)
{
	int	color;

	color = 0;
	if (n % 8 == 7)
		color = 0x0225D1;
	else if (n % 8 == 6)
		color = 0x0220B8;
	else if (n % 8 == 5)
		color = 0x011161;
	else if (n % 8 == 4)
		color = 0x0227DE;
	else if (n % 8 == 3)
		color = 0x011991;
	else if (n % 8 == 2)
		color = 0x0225D1;
	else if (n % 8 == 1)
		color = 0x011161;
	else if (n % 8 == 0)
		color = 0x010A38;
	return (color);
}

int	colors_set_2(int n)
{
	int	color;

	color = 0;
	if (n % 8 == 7)
		color = 0x827872;
	else if (n % 8 == 6)
		color = 0xCFC5C0;
	else if (n % 8 == 5)
		color = 0xCACCCE;
	else if (n % 8 == 4)
		color = 0x827F72;
	else if (n % 8 == 3)
		color = 0xCFCBBA;
	else if (n % 8 == 2)
		color = 0xFFFFFF;
	else if (n % 8 == 1)
		color = 0xCFCBBA;
	else if (n % 8 == 0)
		color = 0x66645C;
	return (color);
}

int	colors_set_3(int n)
{
	int	color;

	color = 0;
	if (n % 8 == 7)
		color = 0x8A02CF;
	else if (n % 8 == 6)
		color = 0x9302D8;
	else if (n % 8 == 5)
		color = 0x7902B5;
	else if (n % 8 == 4)
		color = 0x60018F;
	else if (n % 8 == 3)
		color = 0x3D015C;
	else if (n % 8 == 2)
		color = 0x60018F;
	else if (n % 8 == 1)
		color = 0x8A02CF;
	else if (n % 8 == 0)
		color = 0x9302D8;
	return (color);
}

int	colors_set_4(int n)
{
	int	color;

	color = 0;
	if (n % 8 == 7)
		color = 0xD10E03;
	else if (n % 8 == 6)
		color = 0xDE0D02;
	else if (n % 8 == 5)
		color = 0xB80B02;
	else if (n % 8 == 4)
		color = 0xDE0D02;
	else if (n % 8 == 3)
		color = 0x5E0601;
	else if (n % 8 == 2)
		color = 0x910901;
	else if (n % 8 == 1)
		color = 0xB80B02;
	else if (n % 8 == 0)
		color = 0x5e0601;
	return (color);
}

int	colors_set_5(int n)
{
	int	color;

	color = 0;
	if (n % 8 == 7)
		color = 0xFFFFFF;
	else if (n % 8 == 6)
		color = 0x9400D3;
	else if (n % 8 == 5)
		color = 0x4B0082;
	else if (n % 8 == 4)
		color = 0x0000FF;
	else if (n % 8 == 3)
		color = 0x00FF00;
	else if (n % 8 == 2)
		color = 0xFFFF00;
	else if (n % 8 == 1)
		color = 0xFF7F00;
	else if (n % 8 == 0)
		color = 0xFF0000;
	return (color);
}
