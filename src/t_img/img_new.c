/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:31:01 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 14:08:12 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
#include "mlx.h"
#include "libft.h"

static char	ft_set_filename(t_img *img, const char *filename)
{
	img->filename = ft_strdup(filename);
	if (!(img->filename))
		return (0);
	return (1);
}

static char	ft_malloc_img(t_img **img)
{
	*img = malloc(sizeof(t_img));
	if (!(*img))
		return (0);
	(*img)->filename = NULL;
	(*img)->img = NULL;
	(*img)->addr = NULL;
	return (1);
}

t_img	*ft_img_new(void *mlx, char *filename, int width, int height)
{
	t_img	*img;

	if (!filename || !ft_malloc_img(&img))
		return (NULL);
	if (!ft_set_filename(img, filename))
		return ((void *)(long)ft_img_free(mlx, &img));
	img->img = mlx_xpm_file_to_image(mlx, filename, &img->width, &img->height);
	if (!(img->img))
		return ((void *)(long)ft_img_free(mlx, &img));
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	if (height <= 0 && width <= 0)
	{
		height = img->height;
		width = img->width;
		return (img);
	}
	else if (height <= 0)
		height = (int)((float)img->height / img->width * width);
	else if (width <= 0)
		width = (int)((float)img->width / img->height * height);
	if (!ft_img_resize(mlx, img, width, height))
		return ((void *)(long)ft_img_free(mlx, &img));
	return (img);
}
