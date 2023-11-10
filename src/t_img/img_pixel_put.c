/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:15:48 by orudek            #+#    #+#             */
/*   Updated: 2023/11/10 13:23:08 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
#include "defines.h"

void	img_pixel_put(t_img *this, int x, int y, int color)
{
	char	*dst;

	if(x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	dst = this->addr + (y * this->size_line + x * (this->bits_per_pixel / 8));
	unsigned int alfa = (color >> 24) & 0xff;
	if (!alfa)
	{
		*(unsigned int *)dst = color;
		return ;
	}
	unsigned int *pixel = (unsigned int *)dst;
	unsigned int r = (((color >> 16) & 0xff) * (255 - alfa) + alfa * ((*pixel >> 16) & 0xff)) >> 8;
	unsigned int g = (((color >> 8) & 0xff) * (255-alfa) + alfa * ((*pixel >> 8) & 0xff)) >> 8;
	unsigned int b = ((color & 0xff) * (255 - alfa)  + alfa * (*pixel & 0xff)) >> 8;
	#include <stdio.h>
	static int first = 0;
	if (alfa != 0 && first == 0)
	{
		printf("first_color : %d, %d, %d, %d\n", (*pixel >> 24) & 0xff ,(*pixel >> 16) & 0xff, (*pixel >> 8) & 0xff, *pixel & 0xff);
		printf("second_color : %d, %d, %d, %d\n", (color >> 24) & 0xff,(color >> 16) & 0xff, (color >> 8) & 0xff, color & 0xff);
		printf("new_color: %d, %d, %d, %d\n", alfa, r, g, b);
		first = 1;
	}
	*pixel = (r << 16) | (g << 8) | b;
}
