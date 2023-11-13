#include "cub3d.h"
#include <math.h>

typedef struct s_ray
{
	float	x;
	float	y;
	float	delta_x;
	float	delta_y;
	int		next_x;
	int		next_y;
	int 	face;
	float	alpha;
	t_img	*img;
}	t_ray;

static void	move_next_point(t_ray *ray, int *new_x, int *new_y)
{
	float	tx;
	float	ty;

	tx = (ray->next_x - ray->x) / ray->delta_x;
	ty = (ray->next_y - ray->y) / ray->delta_y;
	if (ty < tx && ty > 0) // if time to right grid is bigger than time to up grid
	{
		*new_y += (ray->delta_y > 0) - (ray->delta_y < 0);
		ray->next_y += (ray->delta_y > 0) - (ray->delta_y < 0);
		tx = ty;
		ray->face = 1 + 2 * (ray->delta_y < 0);
	}
	else
	{
		*new_x += (ray->delta_x > 0) - (ray->delta_x < 0) ;
		ray->next_x += (ray->delta_x > 0) - (ray->delta_x < 0);
		ray->face = 0 + 2 * (ray->delta_x < 0);
	}
	ray->x += ray->delta_x * tx;
	ray->y += ray->delta_y * tx;
}

/*
		1
	 ___________
	|			|
0	|			|  2
	|			|
	|___________|

		3
*/
static void	print_pixels(t_game *game, int x, int y, t_ray *ray, int img_x)
{
	float	percentage;
	int		pixel_x;
	int		pixel_y;

	if (ray->face == 0)
		percentage = ray->y - (float)y;
	else if (ray->face == 2)
		percentage = 1 - (ray->y - (float)y);
	else if (ray->face == 1)
		percentage = 1 - (ray->x - (float)x);
	else
		percentage = ray->x - (float)x;
	pixel_x = (int)(percentage * game->textures[ray->face]->width);
	float dist_screen = ray->img->height / (2.0f * tan(FOV * PI * ray->img->height/ (360.0f * ray->img->width)));
	float dist_wall;
	dist_wall = sqrt((game->player.x - ray->x) * (game->player.x - ray->x) + (game->player.y - ray->y) * (game->player.y - ray->y)) * fabs(cos(ray->alpha));
	for ( int i = 0; i < ray->img->height; i++)
	{
		float img_tan_beta = (ray->img->height/2 - i) / dist_screen;
		if (img_tan_beta < -0.5 / dist_wall)
			ray->img->put_pixel(ray->img, img_x, i, game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
		else if (img_tan_beta < 0.5 / dist_wall)
		{
			pixel_y = (0.5- img_tan_beta * dist_wall) * game->textures[ray->face]->height;
			ray->img->put_pixel(ray->img, img_x, i, game->textures[ray->face]->get_pixel(game->textures[ray->face], pixel_x, pixel_y));
		}
		else
			ray->img->put_pixel(ray->img, img_x, i, game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
	}
}

static void	print_filler(t_game *game, t_ray *ray, int x)
{
	for (int i = 0; i < ray->img->height; i++)
	{
		if (i < ray->img->height / 2)
			img_pixel_put(ray->img, x, i, game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
		else
			img_pixel_put(ray->img, x, i, game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
	}	
}





static void	put_vertical_line(t_game *game, t_ray *ray, int x)
{
	int		new_x;
	int		new_y;
	float	dx;
	float	dy;

	new_x = ray->x;
	new_y = ray->y;
	while (1)
	{
		move_next_point(ray, &new_x, &new_y);
		dx = game->player.x - ray->x;
		dy = game->player.y - ray->y;
		if (sqrt(dx * dx + dy * dy) > RENDER_DISTANCE)
			break;
		if (is_wall(game->map.map, new_x, new_y))
			return (print_pixels(game, new_x, new_y, ray,x));
	}
	print_filler(game, ray, x);										
}

t_img *render(t_game *game , t_img *img)
{
	int		x;
	t_ray	ray;

	x = -1;
	ray.img = img;
	while (++x < img->width)
	{
		ray.alpha = (-FOV/2.0 + (float)x * FOV / img->width) * PI / 180;
		ray.x = game->player.x;
		ray.y = game->player.y;
		ray.delta_x =  cos(ray.alpha + game->player.rotation);
		ray.delta_y =  sin(ray.alpha + game->player.rotation);
		ray.next_x = ray.x + (ray.delta_x > 0);
		ray.next_y = ray.y + (ray.delta_y > 0);
		put_vertical_line(game, &ray, x);
	}
	return (img);
}
