/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:38:13 by orudek            #+#    #+#             */
/*   Updated: 2023/11/11 18:41:24 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player.h"
#include "defines.h"

void	player_init(t_player *player, float x, float y, float rotation)
{
	player->x = x;
	player->y = y;
	player->z = PLAYER_HEIGHT;
	player->rotation = rotation;
	player->v_front = 0;
	player->v_side = 0;
	player->v_rotation = 0;
	player->size = PLAYER_SIZE;
	player->move = player_move;
	player->on_key = player_on_key;
}
