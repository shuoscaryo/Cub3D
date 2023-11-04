/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_get_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:18:13 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 14:08:09 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"

int	ft_img_get_pixel(t_img img, int x, int y)
{
	int	color;

	color = *(int *)(img.addr + (y * img.size_line
				+ x * (img.bits_per_pixel / 8)));
	return (color);
}
