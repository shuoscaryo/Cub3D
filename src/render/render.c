#include "cub3d.h"
#include <math.h>

typedef struct s_ray
{
	float	x;
	float	y;
	float	z;
	float	delta_x;
	float	delta_y;
	float	delta_z;
}	t_ray;

int	collision(t_game *game, t_ray *ray)
{
	return (0);
}

static float	move_next_point(t_ray *ray, char **map)
{
	float	tx;
	float	ty;

	if (ray->delta_x > 0) // if ray is going right
		tx = ((int)ray->x + 1 - ray->x) / ray->delta_x; //calculate time to right grid
	else
		tx = ((int)ray->x - ray->x) / ray->delta_x; //calculate time to left grid
	if (ray->delta_y > 0) // if ray is going up
		ty = ((int)ray->y + 1 - ray->y) / ray->delta_y; //calculate time to up grid
	else
		ty = ((int)ray->y - ray->y) / ray->delta_y; //calculate time to down grid
	if (tx > ty) // if time to right grid is bigger than time to up grid
	{
		tx = ty;
		if (is_wall(map, (int)ray->x, (int)ray->y))
			return (tx);
	}
	ray->x += ray->delta_x * tx;
	ray->y += ray->delta_y * tx;
	ray->z += ray->delta_z * tx;
	return (tx);
}

static int	get_pixel(t_game *game, t_ray *ray)
{
	int		t;

	t = 0;
	t += move_next_point(ray, game->map.map);
	while (t < RENDER_DISTANCE)
	{
		if (ray->z > 1)
			return (game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
		if (ray->z < 0)
			return (game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
		if (collision(game, ray))
			return ();
		t += move_next_point(ray, game->map.map);
	}
	if (ray->z < game->player.z)
		return (game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
	return (game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
}

t_img *render(t_game *game , t_img *img)
{
	int x;
	int y;
	t_ray ray;
	int	alpha;
	int	beta;
	int frame_dist;

	x = -1;
	frame_dist = img->width / ( 2.0f * tan(FOV * PI / 360.0f));
	while (++x < img->width)
	{
		y = -1;
		while (++y < img->height)
		{
			alpha = game->player.rotation + tan((img->width - x) / frame_dist);
			beta = tan((img->height - y) / frame_dist);
			ray.x = game->player.x;
			ray.y = game->player.y;
			ray.z = game->player.z;
			ray.delta_x = cos(beta) * cos(alpha);
			ray.delta_y = cos(beta) * sin(alpha);
			ray.delta_z = sin(beta);
			img->put_pixel(img, x, y, get_pixel(game, &ray));
		}
	}
	return (img);
}
