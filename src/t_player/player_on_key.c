/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_on_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:03:53 by orudek            #+#    #+#             */
/*   Updated: 2023/11/03 22:33:44 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player.h"
#include <math.h>
#include "defines.h"

void	player_on_key(t_player *this, t_keys *keys)
{
	int	front_mov;
	int	side_mov;
	int	rot_mov;

	front_mov = keys->get_status(keys, W) - keys->get_status(keys, S);
	side_mov = keys->get_status(keys, D) - keys->get_status(keys, A);
	rot_mov = keys->get_status(keys, LEFT) - keys->get_status(keys, RIGHT);
	this->vx = front_mov * cos(this->rotation) * PLAYER_MOVE_SPEED;
	this->vy = front_mov * sin(this->rotation) * PLAYER_MOVE_SPEED;
	this->vx += side_mov * sin(this->rotation) * PLAYER_MOVE_SPEED;
	this->vy -= side_mov * cos(this->rotation) * PLAYER_MOVE_SPEED;
	this->rotation_speed = rot_mov * PLAYER_ROT_SPEED;
}
