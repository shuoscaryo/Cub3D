#include "cub3d.h"
#include <math.h>

typedef struct s_ray
{
	int	x;
	int	y;
	int	z;
	int	delta_x;
	int	delta_y;
	int	delta_z;
}	t_ray;

int	collision(t_wall wall, t_ray *ray)
{
	int		x; //coordinates of the img, starts from the left top corner positive to the right
	int		y; //coordinates of the img, starts from the left top corner positive to the bottom
}

static float	move_next_point(t_ray *ray , int *new_x, int *new_i)
{
	float	tx;
	float	ty;

	*new_x = (int)ray->x + (ray->delta_x > 0 ) - (ray->delta_x < 0 );
		tx = (*new_x - ray->x) / ray->delta_x; //calculate time to right grid
	*new_y = (int)ray->y + (ray->delta_y > 0 );
		ty = (*new_y - ray->y) / ray->delta_y; //calculate time to up grid
	if (tx > ty) // if time to right grid is bigger than time to up grid
		tx = ty;
	ray->x += ray->delta_x * tx;
	ray->y += ray->delta_y * tx;
	ray->z += ray->delta_z * tx;
	return (tx);
}

static int	get_pixel(t_game *game, t_ray *ray)
{
	int		t;
	t_wall	wall;

	t = 0;
	while (t < RENDER_DISTANCE)
	{
		if (ray->z > 1)
			return (game->maps.F[0] << 16 | game->maps.F[1] << 8 | game->maps.F[2]);
		if (ray->z < 0)
			return (game->maps.C[0] << 16 | game->maps.C[1] << 8 | game->maps.C[2]);
		wall = get_next_tile(game, ray);
		if (wall)
			return (colision(wall, ray));
		t += move_next_point(ray);
	}
	if (ray->z < player->z)
		return (game->maps.F[0] << 16 | game->maps.F[1] << 8 | game->maps.F[2]);
	return (game->maps.C[0] << 16 | game->maps.C[1] << 8 | game->maps.C[2]);
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
			alpha = game->player.rotation + tan((img->weight - x) / ray->frame_dist);
			beta = tan((img->height - y) / ray->frame_dist);
			ray->x = game->player.x;
			ray->y = game->player.y;
			ray->z = game->player.z;
			ray->delta_x = cos(beta) * cos(alpha);
			ray->delta_y = cos(beta) * sin(alpha);
			ray->delta_z = sin(beta);
			my_mlx_pixel_put(&game->img, x, y, get_pixel(game, ray));
		}
	}
	return (img);
}
