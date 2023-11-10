#include "cub3d.h"
#include <math.h>

#define cuadrado_lado 30

typedef struct s_ray
{
	float	x;
	float	y;
	float	z;
	float	delta_x;
	float	delta_y;
	float	delta_z;
}	t_ray;

static float	move_next_point(t_ray *ray, int *new_x, int *new_y)
{
	float	tx;
	float	ty;

	*new_x = (int)ray->x + (ray->delta_x > 0 ) - (ray->delta_x < 0 );
		tx = (*new_x - ray->x) / ray->delta_x; //calculate time to right grid
	*new_y = (int)ray->y + (ray->delta_y > 0 ) - (ray->delta_y < 0 );
		ty = (*new_y - ray->y) / ray->delta_y; //calculate time to up grid
	if (ray->delta_y < 0)
		(*new_y)--;
	if (ray->delta_x < 0)
		(*new_x)--;
	if (tx > ty && ty > 0) // if time to right grid is bigger than time to up grid
	{
		*new_x = (int)ray->x;
		tx = ty;
	}
	else
		*new_y = (int)ray->y;
	ray->x += ray->delta_x * tx;
	ray->y += ray->delta_y * tx;
	ray->z += ray->delta_z * tx;
	return (tx);
}

static float	move_first_point(t_ray *ray, int *new_x, int *new_y)
{
	float	tx;
	float	ty;

	*new_x = (int)ray->x + (ray->delta_x > 0 );
		tx = (*new_x - ray->x) / ray->delta_x; //Check if delta_x is 0
	*new_y = (int)ray->y + (ray->delta_y > 0 );
		ty = (*new_y - ray->y) / ray->delta_y; //Check if delta_y is 0
	if (ray->delta_y < 0)
		(*new_y)--;
	if (ray->delta_x < 0)
		(*new_x)--;
	if (tx > ty && ty > 0) // if time to right grid is bigger than time to up grid
	{
		*new_x = (int)ray->x;
		tx = ty;
	}
	else
		*new_y = (int)ray->y;
	ray->x += ray->delta_x * tx;
	ray->y += ray->delta_y * tx;
	ray->z += ray->delta_z * tx;
	return (tx);
}

void rayo(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = -abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy;

	while (x0 != x1 || y0 != y1)
	{
		img->put_pixel(img, x0, y0, color);
		int e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

static int	get_pixel(t_game *game, t_ray *ray, char **map)
{
	int		t;
	int		new_x;
	int		new_y;

	t = 0;
	t += move_first_point(ray, &new_x, &new_y);
	while (t < RENDER_DISTANCE)
	{
		if (ray->z > 1)
			return (game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
		if (ray->z < 0)
			return (game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
		if (is_wall(map, new_x, new_y))
		{
			//printf("x: %d, y: %d\n", new_x, new_y);
			rayo(game->img, game->player.x * cuadrado_lado, game->player.y * cuadrado_lado, ray->x * cuadrado_lado, ray->y * cuadrado_lado, 0xf50000FF);
			//exit(1);
			return (0x00FFFFFF);
		}
		t += move_next_point(ray, &new_x, &new_y);
	}
	if (ray->z < game->player.z)
		return (game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
	return (game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
}

t_img *render(t_game *game , t_img *img, char **map)
{
	int x;
	//int y;
	t_ray ray;
	float	alpha;
	float	beta;
	float frame_dist;
	x = -1;
	frame_dist = img->width / ( 2.0f * tan(FOV * PI / 360.0f));
	while (++x < img->width)
	{
		//y = -1;
		//while (++y < img->height)
		//{
			alpha = game->player.rotation + atan2(img->width/2 - x, frame_dist); //NOTE UPDATE WITH NEW COORDINATES
			beta = 0;//tan((img->height - y) / frame_dist); //NOTE UPDATE WITH NEW COORDINATES
			ray.x = game->player.x;
			ray.y = game->player.y;
			ray.z = game->player.z;
			ray.delta_x = cos(beta) * cos(alpha); //NOTE UPDATE WITH NEW COORDINATES
			ray.delta_y = cos(beta) * sin(alpha); //NOTE UPDATE WITH NEW COORDINATES
			ray.delta_z = sin(beta); //NOTE UPDATE WITH NEW COORDINATES
			img->put_pixel(img, x, 0, get_pixel(game, &ray, map));
		//}
	}
	/* alpha = - game->player.rotation; //NOTE UPDATE WITH NEW COORDINATES
	beta = 0; //NOTE UPDATE WITH NEW COORDINATES
	ray.x = game->player.x;
	ray.y = game->player.y;
	ray.z = game->player.z;
	ray.delta_x = cos(beta) * cos(alpha); //NOTE UPDATE WITH NEW COORDINATES
	ray.delta_y = cos(beta) * sin(alpha); //NOTE UPDATE WITH NEW COORDINATES
	ray.delta_z = sin(beta); //NOTE UPDATE WITH NEW COORDINATES
	printf("x: %f, y: %f, z: %f alpha: %f\n", ray.delta_x, ray.delta_y, ray.delta_z, alpha);
	img->put_pixel(img, 0, 0, get_pixel(game, &ray, map)); */
	return (img);
}
