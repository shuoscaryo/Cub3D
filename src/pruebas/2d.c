#include "cub3d.h"
#include <math.h>

#define cuadrado_lado 30

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

int cuadro(t_img *img, int x, int y, int color, int size)
{
	int i;
	int j;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			img->put_pixel(img, x + i, y + j, color);
			if (j == size - 1 || i == size - 1 || j == 0 || i == 0)
				img->put_pixel(img, x + i, y + j, 0x55888888);
			j++;
		}
		i++;
	}
	return (0);
}

void flechita(t_game *game, int x, int y, int color)
{
	//printf("x: %d, y: %d, angle: %f\n", x, y, game->player.rotation);
	for (int i = 0; i < cuadrado_lado * 3 * game->player.size; i++)
	{
		float x1 =x +i* cos(game->player.rotation);
		float y1 =y +i* sin(game->player.rotation);
		game->img->put_pixel(game->img,x1 ,y1 , color);
		game->img->put_pixel(game->img,x1 + 1 , y1 , color);
		game->img->put_pixel(game->img,x1 - 1 ,y1 , color);
		game->img->put_pixel(game->img,x1 ,y1 + 1, color);
		game->img->put_pixel(game->img,x1 ,y1 - 1, color);
		game->img->put_pixel(game->img,x1 + 1 ,y1 + 1, color);
		game->img->put_pixel(game->img,x1 - 1 ,y1 + 1, color);
		game->img->put_pixel(game->img,x1 + 1 ,y1 - 1, color);
		game->img->put_pixel(game->img,x1 - 1 ,y1 - 1, color);

	}
}

void dibu_player(t_game *game)
{
	flechita(game, (game->player.x)* cuadrado_lado, (game->player.y) * cuadrado_lado, 0x0000aa00);
	cuadro(game->img, (game->player.x - game->player.size) * cuadrado_lado, (game->player.y - game->player.size) * cuadrado_lado, 0x0099FF99,game->player.size * 2 * cuadrado_lado);
	//game->img->put_pixel(game->img, game->player.x * cuadrado_lado, game->player.y * cuadrado_lado, 0x000000FF);
}

int dibuja(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while(game->map.map[i][j])
		{
			if (game->map.map[i][j] == '1')
				cuadro(game->img, j * cuadrado_lado, i * cuadrado_lado, 0x00eeeeee, cuadrado_lado);
			else if (game->map.map[i][j] == '0')
				cuadro(game->img, j * cuadrado_lado, i * cuadrado_lado, 0x00dd3333, cuadrado_lado);
			j++;
		}
		i++;
	}
	//printf("x: %f, y: %f, angle: %f\n", game->player.x, game->player.y, game->player.rotation);
	return (0);
}
