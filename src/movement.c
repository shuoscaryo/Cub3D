/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:32:03 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/03 14:18:27 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int on_key_up(int key, t_game *game)
{
	printf("called on_key_up :");
	if (key == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
		free(game->map.SO);
		free(game->map.NO);
		free(game->map.WE);
		free(game->map.EA);
		exit(0);
	}
	else if (key == W)
		printf("W\n");
	else if (key == A)
		printf("A\n");
	else if (key == S)
		printf("S\n");
	else if (key == D)
		printf("D\n");
	return (0);
}

int	on_key_down(int key, t_game *game)
{
	printf("called on_key_down: ");
	if (key == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
		free(game->map.SO);
		free(game->map.NO);
		free(game->map.WE);
		free(game->map.EA);
		exit(0);
	}
	else if (key == W)
		printf("W\n");
	else if (key == A)
		printf("A\n");
	else if (key == S)
		printf("S\n");
	else if (key == D)
		printf("D\n");
	return (0);
}