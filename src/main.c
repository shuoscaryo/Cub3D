/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:14:02 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/14 16:03:02 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



float fps();
static int	update(t_game *game)
{
	player_move(&game->player, game, 0.06);
	render(game, game->img);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	char *frames = ft_itoa(fps());
	mlx_string_put(game->mlx, game->win, 10, 20, 0x00ff00, frames);
	free(frames);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("Error: Invalid number of arguments.\n"), 1);
	if (!game_init(&game, argv[1]))
		return (1);
	mlx_hook(game.win, ON_DESTROY, NO_EVENT_MASK, game_exit, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, ON_KEYDOWN, KEY_PRESS_MASK, on_key_down, &game);
	mlx_hook(game.win, ON_KEYUP, KEY_RELEASE_MASK, on_key_up, &game);
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_loop(game.mlx);
	return (0);
}
