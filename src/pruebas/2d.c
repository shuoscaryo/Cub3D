#include "cub3d.h"

int cuadro(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			game->img->put_pixel(game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}

int dibuja(t_game *game)
{
	cuadro(game, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}