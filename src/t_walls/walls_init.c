/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:44:18 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 22:55:44 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_walls.h"

int	walls_init(t_walls *walls, int size, t_game *game)
{
	walls->size = size;
	walls->walls = malloc(sizeof(t_list *) * size);
	if (!walls->walls)
		return (0);
	ft_bzero(walls->walls, sizeof(t_list *) * size);
	walls->no = game->textures.get_texture(&game->textures, game->map.NO);
	walls->so = game->textures.get_texture(&game->textures, game->map.SO);
	walls->ea = game->textures.get_texture(&game->textures, game->map.EA);
	walls->we = game->textures.get_texture(&game->textures, game->map.WE);
	if (!walls->no || !walls->so || !walls->ea || !walls->we)
		return (0);
	walls->add_wall = walls_add_wall;
	walls->get_wall = walls_get_wall;
	walls->free = walls_free;
	return (1);
}
