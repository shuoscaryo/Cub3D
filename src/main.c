/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:14:02 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/05 20:21:17 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int update(t_game *game)
{
	game->player.move(&game->player, 0.001);
	return (0);
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
	player_init(&game.player, 0, 0, 0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	mlx_hook(game.win, ON_DESTROY, NO_EVENT_MASK, game_exit, &game);
	mlx_hook(game.win, ON_KEYDOWN, KEY_PRESS_MASK, on_key_down, &game);
	mlx_hook(game.win, ON_KEYUP, KEY_RELEASE_MASK, on_key_up, &game);
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
