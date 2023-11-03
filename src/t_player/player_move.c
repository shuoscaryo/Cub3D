/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:44:16 by orudek            #+#    #+#             */
/*   Updated: 2023/11/03 22:32:19 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player.h"
#include "defines.h"

static void	adjust_rotation(float *rotation)
{
	while (*rotation > PI)
		*rotation -= 2 * PI;
	while (*rotation < -PI)
		*rotation += 2 * PI;
}

void	player_move(t_player *this, float delta_time)
{
	this->x += this->vx * delta_time;
	this->y += this->vy * delta_time;
	this->rotation += this->rotation_speed * delta_time;
	adjust_rotation(&this->rotation);
}
