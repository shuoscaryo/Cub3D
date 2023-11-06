/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:15:48 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 14:33:44 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_textures.h"

void	img_pixel_put(t_img *this, int x, int y, int color)
{
	char	*dst;

	dst = this->addr + (y * this->size_line + x * (this->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
