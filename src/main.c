/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:14:02 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/13 17:28:19 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void fps();
void dibu_player(t_game *game);
unsigned long millis();

int update(t_game *game)
{
	fps();
	player_move(&game->player, game, 0.06);
	render(game, game->img);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	return (0);
}

int textures_init(t_game *game)
{
	int	i;

	game->textures[0] = img_new(game->mlx, game->map.WE);
	game->textures[1] = img_new(game->mlx, game->map.NO);
	game->textures[2] = img_new(game->mlx, game->map.EA);
	game->textures[3] = img_new(game->mlx, game->map.SO);
	if (!game->textures[0] || !game->textures[1]
		|| !game->textures[2] || !game->textures[3])
	{
		i = 0;
		while (i < 4)
		{
			img_free(game->textures[i], game->mlx);
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
	game.keys = NULL;
	player_init(&game.player, game.map.x + 0.5, game.map.y + 0.5, game.map.rotation);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game.img = img_new2(game.mlx, WIN_WIDTH, WIN_HEIGHT);
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
