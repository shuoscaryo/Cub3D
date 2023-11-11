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
	int		next_x;
	int		next_y;
	//int		next_z;	
}	t_ray;

t_img *g_img;
int g_x;
int print = 0;
static float	move_next_point(t_ray *ray, int *new_x, int *new_y)
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
	ray->z += ray->delta_z * tx;
	g_img->put_pixel(g_img, ray->x * cuadrado_lado , ray->y * cuadrado_lado, 0x00aaffaa);
	g_img->put_pixel(g_img, ray->x * cuadrado_lado +1, ray->y * cuadrado_lado, 0x00aaffaa);
	g_img->put_pixel(g_img, ray->x * cuadrado_lado , ray->y * cuadrado_lado +1, 0x00aaffaa);
	g_img->put_pixel(g_img, ray->x * cuadrado_lado , ray->y * cuadrado_lado-1, 0x00aaffaa);
	g_img->put_pixel(g_img, ray->x * cuadrado_lado -1 , ray->y * cuadrado_lado, 0x00aaffaa);
	g_img->put_pixel(g_img, ray->x * cuadrado_lado -1 , ray->y * cuadrado_lado-1, 0x00aaffaa);
	g_img->put_pixel(g_img, ray->x * cuadrado_lado -1 , ray->y * cuadrado_lado+1, 0x00aaffaa);
	g_img->put_pixel(g_img, ray->x * cuadrado_lado +1 , ray->y * cuadrado_lado-1, 0x00aaffaa);
	g_img->put_pixel(g_img, ray->x * cuadrado_lado +1 , ray->y * cuadrado_lado+1, 0x00aaffaa);
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
/*
		1
	 ___________
	|			|
0	|			|  2
	|			|
	|___________|

		3
*/
int	get_wall_pixel(t_game *game, int x, int y, t_ray *ray)
{
	int		face;
	float	percentage;
	int		pixel_x;
	int		pixel_y;

	if ((ray->x - 0.05) < (float) x)
	{
		face = 0;
		percentage = ray->y - (float)y;
		pixel_x = (int)(percentage * game->textures[face]->width);
		pixel_y = (int)((1 - ray->z) * game->textures[face]->height);
		return (game->textures[face]->get_pixel(game->textures[face], pixel_x, pixel_y));
	}
	else if ((ray->x + 0.05) > (float) x + 1)
	{
		face = 2;
		percentage = 1 - (ray->y - (float)y);
		pixel_x = (int)(percentage * game->textures[face]->width);
		pixel_y = (int)((1 - ray->z) * game->textures[face]->height);
		return (game->textures[face]->get_pixel(game->textures[face], pixel_x, pixel_y));
	}
	else if ((ray->y - 0.05) < (float) y)
	{
		face = 1;
		percentage = 1 - (ray->x - (float)x);
		pixel_x = (int)(percentage * game->textures[face]->width);
		pixel_y = (int)((1 - ray->z) * game->textures[face]->height);
		return (game->textures[face]->get_pixel(game->textures[face], pixel_x, pixel_y));
	}
	else
	{
		face = 3;
		percentage = ray->x - (float)x;
		pixel_x = (int)(percentage * game->textures[face]->width);
		pixel_y = (int)((1 - ray->z) * game->textures[face]->height);
		return (game->textures[face]->get_pixel(game->textures[face], pixel_x, pixel_y));
	}
}

static int	get_pixel(t_game *game, t_ray *ray, char **map)
{
	float		t;
	int		new_x;
	int		new_y;

	t = 0;
	new_x = ray->x;
	new_y = ray->y;
	t += move_next_point(ray, &new_x, &new_y);
	while (t < RENDER_DISTANCE)
	{
		if(print)printf("x: %f, y: %f, nx: %d, ny: %d, newx: %d, newy: %d\n", ray->x, ray->y, ray->next_x, ray->next_y, new_x, new_y);
		if (ray->z > 1)
			return (game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
		if (ray->z < 0)
			return (game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
		if (is_wall(map, new_x, new_y))
		{
			//printf("x: %d, y: %d\n", new_x, new_y);
			rayo(game->img, game->player.x * cuadrado_lado, game->player.y * cuadrado_lado, ray->x * cuadrado_lado, ray->y * cuadrado_lado, 0x000000FF /*| ((int)((float)g_x /WIN_WIDTH * (1 << 8) - 1 )<< 8)*/);
			//exit(1);
			//get_wall_pixel(game, new_x, new_y, ray);
			return (0x000000ff);
		}
		t += move_next_point(ray, &new_x, &new_y);
	}
	rayo(game->img, game->player.x * cuadrado_lado, game->player.y * cuadrado_lado, ray->x * cuadrado_lado, ray->y * cuadrado_lado, 0x000000FF /*| ((int)((float)g_x /WIN_WIDTH * (1 << 8) - 1 )<< 8)*/);
	if (ray->z < game->player.z)
		return (game->map.F[0] << 16 | game->map.F[1] << 8 | game->map.F[2]);
	return (game->map.C[0] << 16 | game->map.C[1] << 8 | game->map.C[2]);
}

t_img *render(t_game *game , t_img *img, char **map)
{
	g_img = img;
	int x;
	//int y;
	t_ray ray;
	float	alpha;
	float	beta;
	static int last_pressed= 0;
	if (game->keys.get_status(&game->keys, E) && !last_pressed)
	{
		printf("NEW_RAY\n");
		last_pressed = 1;
		print = 1;
	}
	if (!game->keys.get_status(&game->keys, E))
		last_pressed = 0;
//	float frame_dist;
	x = -1;
	//frame_dist = img->width / ( 2.0f * tan(FOV * PI / 360.0f));
	while (++x < img->width)
	{
	///	//y = -1;
		//while (++y < img->height)
		//{
			//alpha = game->player.rotation + atan2(img->width/2 - x, frame_dist); //NOTE UPDATE WITH NEW COORDINATES
			//alpha = game->player.rotation;
			alpha = game->player.rotation + (-FOV/2.0 + (float)x * FOV / img->width) * PI / 180; 
			g_x = x;
			beta = 0;//tan((img->height - y) / frame_dist); //NOTE UPDATE WITH NEW COORDINATES
			ray.x = game->player.x;
			ray.y = game->player.y;
			ray.z = game->player.z;
			ray.delta_x = cos(beta) * cos(alpha); //NOTE UPDATE WITH NEW COORDINATES
			ray.delta_y = cos(beta) * sin(alpha); //NOTE UPDATE WITH NEW COORDINATES
			ray.delta_z = sin(beta); //NOTE UPDATE WITH NEW COORDINATES
			ray.next_x = ray.x + (ray.delta_x > 0);
			ray.next_y = ray.y + (ray.delta_y > 0);
			if(print)printf("x: %f, y: %f, dx: %f, dy: %f, nx: %d, ny: %d\n", ray.x, ray.y, ray.delta_x, ray.delta_y, ray.next_x, ray.next_y);
			get_pixel(game, &ray, map);
			//img->put_pixel(img, x, y, get_pixel(game, &ray, map));
		//}
	}
	print = 0;
	return (img);
}
