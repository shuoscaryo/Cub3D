/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:32:03 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/01 13:36:50 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	select_move(int key, t_game *game)
{
	if (key == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
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