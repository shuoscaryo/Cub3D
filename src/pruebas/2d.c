#include "cub3d.h"
#include <math.h>

#define cuadrado_lado 30

void my_pixel(t_img *img, int x, int y, int color)
{
	if(x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	img->put_pixel(img, x, y, color);
}
int cuadro(t_game *game, int x, int y, int color)
{
	int i;
	int j;
	i = 0;
	while (i < cuadrado_lado)
	{
		j = 0;
		while (j < cuadrado_lado)
		{
			my_pixel(game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}
void flechita(t_game *game, int x, int y, int color)
{
	//printf("x: %d, y: %d, angle: %f\n", x, y, game->player.rotation);
	for (int i = 0; i < cuadrado_lado * 3; i++)
	{
		float x1 =x +i* cos(game->player.rotation);
		float y1 =y -i* sin(game->player.rotation);
		my_pixel(game->img,x1 ,y1 , color);
		my_pixel(game->img,x1 + 1 , y1 , color);
		my_pixel(game->img,x1 - 1 ,y1 , color);
		my_pixel(game->img,x1 ,y1 + 1, color);
		my_pixel(game->img,x1 ,y1 - 1, color);
		my_pixel(game->img,x1 + 1 ,y1 + 1, color);
		my_pixel(game->img,x1 - 1 ,y1 + 1, color);
		my_pixel(game->img,x1 + 1 ,y1 - 1, color);
		my_pixel(game->img,x1 - 1 ,y1 - 1, color);

	}
}

void dibu_player(t_game *game)
{
	cuadro(game, (game->player.x - 0.5) * cuadrado_lado, (game->player.y - 0.5) * cuadrado_lado, 0x000000FF);
	flechita(game, (game->player.x)* cuadrado_lado, (game->player.y) * cuadrado_lado, 0x000000FF);
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
				cuadro(game, j * cuadrado_lado, i * cuadrado_lado, 0x00FFFFFF);
			else if (game->map.map[i][j] == '0')
				cuadro(game, j * cuadrado_lado, i * cuadrado_lado, 0x00FF0000);
			else if (game->map.map[i][j] == 'N')
				cuadro(game, j * cuadrado_lado, i * cuadrado_lado, 0x00FF9999);
			j++;
		}
		i++;
	}
	dibu_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	printf("x: %f, y: %f, angle: %f\n", game->player.x, game->player.y, game->player.rotation);
	return (0);
}