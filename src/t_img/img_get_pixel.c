/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_get_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:18:13 by orudek            #+#    #+#             */
/*   Updated: 2023/11/13 17:35:50 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"

int	img_get_pixel(t_img *this, int x, int y)
{
	int	color;

	if (x < 0 || x >= this->width || y < 0 || y >= this->height)
		return (0x00000000);
	color = *(int *)(this->addr + (y * this->size_line
				+ x * (this->bits_per_pixel / 8)));
	return (color);
}
