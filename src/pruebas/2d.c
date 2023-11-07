#include "cub3d.h"

#define cuadrado_lado 30

int cuadro(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	if(x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (0);
	i = 0;
	while (i < cuadrado_lado)
	{
		j = 0;
		while (j < cuadrado_lado)
		{
			game->img->put_pixel(game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}

void dibu_player(t_game *game)
{
	cuadro(game, game->player.x * cuadrado_lado, game->player.y * cuadrado_lado, 0x000000FF);
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
	return (0);
}