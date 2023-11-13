/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_on_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:03:53 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 16:14:24 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player.h"
#include "defines.h"

void	player_on_key(t_player *this, t_list *keys)
{
	int		front_mov;
	int		side_mov;
	int		rot_mov;
	float	aux;

	front_mov = keys_get_status(keys, W) - keys_get_status(keys, S);
	side_mov = keys_get_status(keys, D) - keys_get_status(keys, A);
	rot_mov = keys_get_status(keys, RIGHT) - keys_get_status(keys, LEFT);
	if (front_mov && side_mov)
		aux = 0.70710678118;
	else
		aux = 1;
	this->v_front = front_mov * PLAYER_MOVE_SPEED * aux;
	this->v_side = side_mov * PLAYER_MOVE_SPEED * aux;
	this->v_rotation = rot_mov * PLAYER_ROT_SPEED;
}
