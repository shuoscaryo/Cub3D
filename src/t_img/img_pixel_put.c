/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:15:48 by orudek            #+#    #+#             */
/*   Updated: 2023/11/09 21:05:54 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_textures.h"
#include "defines.h"

void	img_pixel_put(t_img *this, int x, int y, int color)
{
	char	*dst;

	if(x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	dst = this->addr + (y * this->size_line + x * (this->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
