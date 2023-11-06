/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_new2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:35:45 by orudek            #+#    #+#             */
/*   Updated: 2023/11/06 19:42:14 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"

static char	malloc_img(t_img **img)
{
	*img = malloc(sizeof(t_img));
	if (!(*img))
		return (0);
	(*img)->filename = NULL;
	(*img)->img = NULL;
	(*img)->addr = NULL;
	(*img)->put_pixel = img_pixel_put;
	(*img)->get_pixel = img_get_pixel;
	(*img)->cmp = img_cmp;
	(*img)->free = img_free;
	return (1);
}

t_img	*img_new2(void *mlx, int width, int height)
{
	t_img	*img;

	if (!malloc_img(&img)
		return (NULL);
	img->img = mlx_new_image(mlx, width, height);
	if (!img->img)
		return (img->free(img, mlx), free(this), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	img->width = width;
	img->height = height;
	return (img);
}