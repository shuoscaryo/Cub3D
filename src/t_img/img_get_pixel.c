/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_get_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:18:13 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 13:40:25 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_textures.h"

int	img_get_pixel(t_img *this, int x, int y)
{
	int	color;

	color = *(int *)(this->addr + (y * this->size_line
				+ x * (this->bits_per_pixel / 8)));
	return (color);
}
