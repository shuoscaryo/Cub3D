/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:31:01 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 13:14:43 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
#include "mlx.h"
#include "libft.h"

static char	ft_malloc_img(t_img **img)
{
	*img = malloc(sizeof(t_img));
	if (!(*img))
		return (0);
	(*img)->filename = NULL;
	(*img)->img = NULL;
	(*img)->addr = NULL;
	(*img)->put_pixel = img_pixel_put;
	(*img)->get_pixel = img_get_pixel;
	(*img)->free = ft_img_free;
	return (1);
}

t_img	*img_new(void *mlx, char *filename)
{
	t_img *this;

	if (!filename || !ft_malloc_img(&this))
		return (NULL);
	this->filename = ft_strdup(filename);
	if (!(this->filename))
		return (this->free(img, mlx), free(img), NULL);
	this->img = mlx_xpm_file_to_image(mlx, filename, &this->width, &this->height);
	if (!(this->img))
		return (this->free(img, mlx), free(img), NULL);
	this->addr = mlx_get_data_addr(this->img, &this->bits_per_pixel,
			&this->size_line, &this->endian);
	return (this);
}
