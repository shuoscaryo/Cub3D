#include "cub3d.h"
#include <math.h>

#define cuadrado_lado 30

typedef struct s_ray
{
	float	x;
	float	y;
	float	delta_x;
	float	delta_y;
	int		next_x;
	int		next_y;
	t_img	*img;
}	t_ray;

float g_x;
static void	move_next_point(t_ray *ray, int *new_x, int *new_y)
{
	float	tx;
	float	ty;

	tx = (ray->next_x - ray->x) / ray->delta_x; //calculate time to right grid
	ty = (ray->next_y - ray->y) / ray->delta_y; //calculate time to up grid
	if (ty < tx && ty > 0) // if time to right grid is bigger than time to up grid
	{
		*new_y += (ray->delta_y > 0) - (ray->delta_y < 0);
		ray->next_y += (ray->delta_y > 0) - (ray->delta_y < 0);
		tx = ty;
	}
	else
	{
		*new_x += (ray->delta_x > 0) - (ray->delta_x < 0) ;
		ray->next_x += (ray->delta_x > 0) - (ray->delta_x < 0);
	}
	ray->x += ray->delta_x * tx;
	ray->y += ray->delta_y * tx;
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
/*
		1
	 ___________
	|			|
0	|			|  2
	|			|
	|___________|

		3
*/
void	print_pixels(t_game *game, int x, int y, t_ray *ray, int img_x)
{
	int		face;
	float	percentage;
	int		pixel_x;
	int		pixel_y;

	if ((ray->x - 0.005) < (float)x)
	{
		face = 0;
		percentage = ray->y - (float)y;
	}
	else if ((ray->x + 0.005) > (float) x + 1)
	{
		face = 2;
		percentage = 1 - (ray->y - (float)y);
	}
	else if ((ray->y - 0.0005) < (float) y)
	{
		face = 1;
		percentage = 1 - (ray->x - (float)x);
	}
	else
	{
		face = 3;
		percentage = ray->x - (float)x;
	}
	pixel_x = (int)(percentage * game->textures[face]->width);
	float dist_screen = ray->img->height / (2.0f * tan(FOV * PI * ray->img->height/ (360.0f * ray->img->width)));
	float dist_wall = sqrt((game->player.x - ray->x) * (game->player.x - ray->x) + (game->player.y - ray->y) * (game->player.y - ray->y));
	float tan_beta = 0.5 / dist_wall;
	for ( int i = 0; i < ray->img->height; i++)
	{
		float img_tan_beta = (ray->img->height/2 - i) / dist_screen;
		//printf("max_fov : %f, dist_screen = %f, img_tan_beta: %f, dist_wall= %f, tan_beta : %f\n",FOV * PI * ray->img->height/ (360.0f * ray->img->width), dist_screen, img_tan_beta, dist_wall, tan_beta);
		if (img_tan_beta < -tan_beta)
			ray->img->put_pixel(ray->img, img_x, i, game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
		else if (img_tan_beta < tan_beta)
		{
			//printf("antes\n");
			pixel_y = (0.5- img_tan_beta * dist_wall) * game->textures[face]->height;
			(void)pixel_x;
			(void)pixel_y;
			ray->img->put_pixel(ray->img, img_x, i, game->textures[face]->get_pixel(game->textures[face], pixel_x, pixel_y));
			//printf("despues\n");
		}
		else
			ray->img->put_pixel(ray->img, img_x, i, game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
	}
}

static void	put_vertical_line(t_game *game, t_ray *ray, int x)
{
	int		new_x;
	int		new_y;

	new_x = ray->x;
	new_y = ray->y;
	#include <math.h>
	while (sqrt((game->player.x - ray->x) * (game->player.x - ray->x) + (game->player.y - ray->y) * (game->player.y - ray->y)) < RENDER_DISTANCE)
	{
		move_next_point(ray, &new_x, &new_y);
		if (is_wall(game->map.map, new_x, new_y))
		{
			//printf("x: %d, y: %d\n", new_x, new_y);
			//rayo(game->img, game->player.x * cuadrado_lado, game->player.y * cuadrado_lado, ray->x * cuadrado_lado, ray->y * cuadrado_lado, 0x000000FF /*| ((int)((float)g_x /WIN_WIDTH * (1 << 8) - 1 )<< 8)*/);
			//exit(1);
			print_pixels(game, new_x, new_y, ray,x);
			return ;
		}
	}
	//rayo(game->img, game->player.x * cuadrado_lado, game->player.y * cuadrado_lado, ray->x * cuadrado_lado, ray->y * cuadrado_lado, 0x000000FF /*| ((int)((float)g_x /WIN_WIDTH * (1 << 8) - 1 )<< 8)*/);
	for (int i = 0; i < ray->img->height; i++)
	{
		if (i < ray->img->height / 2)
			ray->img->put_pixel(ray->img, x, i, game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
		else
			ray->img->put_pixel(ray->img, x, i, game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
	}
	//print_background(game, img, x);
	//return (game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
	//return (game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]); */
}

t_img *render(t_game *game , t_img *img, char **map)
{
	int x;
	t_ray ray;
	float	alpha;
	(void)map;
	x = -1;
	//frame_dist = img->width / ( 2.0f * tan(FOV * PI / 360.0f));
	ray.img = img;
	while (++x < img->width)
	{
			//alpha = game->player.rotation + atan2(img->width/2 - x, frame_dist); //NOTE UPDATE WITH NEW COORDINATES
			alpha = game->player.rotation + (-FOV/2.0 + (float)x * FOV / img->width) * PI / 180; 
			g_x = alpha;
			ray.x = game->player.x;
			ray.y = game->player.y;
			ray.delta_x =  cos(alpha); //NOTE UPDATE WITH NEW COORDINATES
			ray.delta_y =  sin(alpha); //NOTE UPDATE WITH NEW COORDINATES
			ray.next_x = ray.x + (ray.delta_x > 0);
			ray.next_y = ray.y + (ray.delta_y > 0);
			put_vertical_line(game, &ray, x);
	}
	return (img);
}
