/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:31:01 by orudek            #+#    #+#             */
/*   Updated: 2023/11/14 15:00:49 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
#include "mlx.h"
#include "libft.h"

static char	malloc_img(t_img **img)
{
	*img = malloc(sizeof(t_img));
	if (!(*img))
		return (0);
	(*img)->filename = NULL;
	(*img)->img = NULL;
	(*img)->addr = NULL;
	return (1);
}

t_img	*img_new(void *mlx, char *filename)
{
	t_img	*img;

	if (!filename || !malloc_img(&img))
		return (NULL);
	img->filename = ft_strdup(filename);
	if (!(img->filename))
		return (img_free(img, mlx), free(img), NULL);
	img->img = mlx_xpm_file_to_image(mlx, filename, &img->width,
			&img->height);
	if (!(img->img))
		return (img_free(img, mlx), free(img), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	return (img);
}
