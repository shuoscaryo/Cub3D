/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:32:03 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/14 16:42:54 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_key_up(int key, t_game *game)
{
	keys_update(&game->keys, key, 0);
	player_on_key(&game->player, game->keys);
	return (0);
}

int	on_key_down(int key, t_game *game)
{
	keys_update(&game->keys, key, 1);
	player_on_key(&game->player, game->keys);
	if (key == ESC)
		game_exit(game);
	return (0);
}
