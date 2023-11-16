/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:38:48 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/16 18:14:37 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	dist(float x1, float y1, float x2, float y2)
{
	return (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

float	get_percentage(int x, int y, t_ray *ray)
{
	float	percentage;

	if (ray->face == 0)
		percentage = ray->y - (float)y;
	else if (ray->face == 2)
		percentage = 1 - (ray->y - (float)y);
	else if (ray->face == 1)
		percentage = 1 - (ray->x - (float)x);
	else
		percentage = ray->x - (float)x;
	return (percentage);
}

void	print_pixaux(t_game *game, t_ray *ray, int img_x)
{
	int		i;
	float	img_tan_beta;

	i = -1;
	while (++i < ray->img->height)
	{
		img_tan_beta = (ray->img->height / 2 - i) / ray->dist_screen;
		if (img_tan_beta < -0.5 / ray->dist_wall)
			img_pixel_put(ray->img, img_x, i, game->map.floor);
		else if (img_tan_beta < 0.5 / ray->dist_wall)
		{
			ray->pixel_y = (0.5 - img_tan_beta
					* ray->dist_wall) * game->textures[ray->face]->height;
			img_pixel_put(ray->img, img_x, i,
				img_get_pixel(game->textures[ray->face],
					ray->pixel_x, ray->pixel_y));
		}
		else
			img_pixel_put(ray->img, img_x, i, game->map.ceiling);
	}
}
