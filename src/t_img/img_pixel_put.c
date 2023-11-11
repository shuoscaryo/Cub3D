/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:15:48 by orudek            #+#    #+#             */
/*   Updated: 2023/11/11 16:38:21 by orudek           ###   ########.fr       */
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
	*pixel = (r << 16) | (g << 8) | b;
}
