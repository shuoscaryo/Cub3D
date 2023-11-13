/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:14:02 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/13 14:48:39 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void fps();
void dibu_player(t_game *game);
unsigned long millis();

static void	ft_scale_pixels(t_img *new_img, t_img *img, int width, int height)
{
	int	i;
	int	j;

	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
			new_img->put_pixel(new_img, i, j, img->get_pixel(img,
					(int)((float)i / width * img->width),
					(int)((float)j / height * img->height)));
	}
}

int update(t_game *game)
{
	fps();
	//fps();
	game->player.move(&game->player, game, 0.06);
	//printf("x: %f, y: %f, angle: %f\n", game->player.x, game->player.y, game->player.rotation);
	//dibuja(game);
	render(game, game->img);
	ft_scale_pixels(game->img2, game->img, game->img2->width, game->img2->height);
	//dibu_player(game);
	
	mlx_put_image_to_window(game->mlx, game->win, game->img2->img, 0, 0);
	return (0);
}

int textures_init(t_game *game)
{
	int	i;

	game->textures[0] = img_new(game->mlx, game->map.WE);
	game->textures[1] = img_new(game->mlx, game->map.NO);
	game->textures[2] = img_new(game->mlx, game->map.EA);
	game->textures[3] = img_new(game->mlx, game->map.SO);
	if (!game->textures[0] || !game->textures[1] || !game->textures[2] || !game->textures[3])
	{
		i = 0;
		while (i < 4)
		{
			game->textures[i]->free(game->textures[i], game->mlx);
			i++;
		}
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!check_params(argc, argv, &game))
		return (0);
	if (!read_map(&game.map, argv[1]))
		return (free_map(&game.map), 0);
	//game_init(&game);
	keys_init(&game.keys);
	player_init(&game.player, game.map.x + 0.5, game.map.y + 0.5, game.map.rotation);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game.img = img_new2(game.mlx, WIN_WIDTH * RESOLUTION, WIN_HEIGHT * RESOLUTION);
	game.img2 = img_new2(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!textures_init(&game))
		return (free_map(&game.map), 0);
	mlx_hook(game.win, ON_DESTROY, NO_EVENT_MASK, game_exit, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, ON_KEYDOWN, KEY_PRESS_MASK, on_key_down, &game);
	mlx_hook(game.win, ON_KEYUP, KEY_RELEASE_MASK, on_key_up, &game);
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_loop(game.mlx);
	return (0);
}
