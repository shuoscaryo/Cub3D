/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:49:00 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 14:08:21 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
#include "mlx.h"

void	ft_img_pixel_put(t_img *img, int x, int y, int color);
int		ft_img_get_pixel(t_img img, int x, int y);

static void	ft_scale_pixels(t_img *new_img, t_img img, int width, int height)
{
	int	i;
	int	j;

	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
			ft_img_pixel_put(new_img, i, j, ft_img_get_pixel(img,
					(int)((float)i / width * img.width),
					(int)((float)j / height * img.height)));
	}
}

char	ft_img_resize(void *mlx, t_img *img, int width, int height)
{
	t_img	aux;

	if (!img || (width <= 0 && height <= 0))
		return (0);
	if (height <= 0)
		height = (int)((float)img->height / img->width * width);
	if (width <= 0)
		width = (int)((float)img->width / img->height * height);
	aux.img = mlx_new_image(mlx, width, height);
	if (!aux.img)
		return (0);
	aux.addr = mlx_get_data_addr(aux.img, &aux.bits_per_pixel, &aux.size_line,
			&aux.endian);
	ft_scale_pixels(&aux, *img, width, height);
	mlx_destroy_image(mlx, img->img);
	img->img = aux.img;
	img->addr = aux.addr;
	img->size_line = aux.size_line;
	img->width = width;
	img->height = height;
	return (1);
}
