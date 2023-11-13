/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:32:03 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/13 17:30:54 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int on_key_up(int key, t_game *game)
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
	{
		mlx_destroy_window(game->mlx, game->win); //NOTE CALL game_exit
		game->win = NULL;
		ft_lstfree(game->keys, free);
		ft_array_free(game->map.map);
		free(game->map.SO);
		free(game->map.NO);
		free(game->map.WE);
		free(game->map.EA);
		exit(0);
	}
	return (0);
}