/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:12:03 by orudek            #+#    #+#             */
/*   Updated: 2023/11/23 14:33:11 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
		1
	 ___________
	|			|
0	|			|  2
	|			|
	|___________|

		3
*/

static void	print_pixels(t_game *game, t_ray *ray, int img_x)
{
	ray->pixel_x = (int)(get_percentage(ray->new_xy[0],
				ray->new_xy[1], ray) * game->textures[ray->face]->width);
	ray->dist_screen = ray->img->height / (2.0f
			* tan(FOV * PI * ray->img->height / (360.0f * ray->img->width)));
	ray->dist_wall = dist(game->player.x,
			game->player.y, ray->x, ray->y) * cos(ray->alpha);
	print_pixaux(game, ray, img_x);
}

static void	move_next_point(t_ray *ray, int *new_x, int *new_y)
{
	float	tx;
	float	ty;

	tx = (ray->next_x - ray->x) / ray->delta_x;
	ty = (ray->next_y - ray->y) / ray->delta_y;
	if (ty < tx && ty > 0)
	{
		*new_y += (ray->delta_y > 0) - (ray->delta_y < 0);
		ray->next_y += (ray->delta_y > 0) - (ray->delta_y < 0);
		tx = ty;
		ray->face = 1 + 2 * (ray->delta_y < 0);
	}
	else
	{
		*new_x += (ray->delta_x > 0) - (ray->delta_x < 0);
		ray->next_x += (ray->delta_x > 0) - (ray->delta_x < 0);
		ray->face = 0 + 2 * (ray->delta_x < 0);
	}
	ray->x += ray->delta_x * tx;
	ray->y += ray->delta_y * tx;
}

static void	print_filler(t_game *game, t_ray *ray, int x)
{
	int	i;

	i = -1;
	while (++i < ray->img->height)
	{
		if (i < ray->img->height / 2)
			img_pixel_put(ray->img, x, i, game->map.ceiling);
		else
			img_pixel_put(ray->img, x, i, game->map.floor);
	}
}

static void	put_vertical_line(t_game *game, t_ray *ray, int x)
{
	float	dx;
	float	dy;

	ray->new_xy[0] = ray->x;
	ray->new_xy[1] = ray->y;
	while (1)
	{
		move_next_point(ray, &(ray->new_xy[0]), &(ray->new_xy[1]));
		dx = game->player.x - ray->x;
		dy = game->player.y - ray->y;
		if (sqrt(dx * dx + dy * dy) > RENDER_DISTANCE)
			break ;
		if (is_wall(game->map.map, ray->new_xy[0], ray->new_xy[1]))
			return (print_pixels(game, ray, x));
	}
	print_filler(game, ray, x);
}

t_img	*render(t_game *game, t_img *img)
{
	int		x;
	t_ray	ray;

	x = -1;
	ray.img = img;
	while (++x < img->width)
	{
		ray.alpha = (-FOV / 2.0 + (float)x * FOV / img->width) * PI / 180;
		ray.x = game->player.x;
		ray.y = game->player.y;
		ray.delta_x = cos(ray.alpha + game->player.rotation);
		ray.delta_y = sin(ray.alpha + game->player.rotation);
		ray.next_x = ray.x + (ray.delta_x > 0);
		ray.next_y = ray.y + (ray.delta_y > 0);
		put_vertical_line(game, &ray, x);
	}
	return (img);
}
