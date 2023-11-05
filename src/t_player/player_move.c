/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:44:16 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 17:06:35 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player.h"
#include "defines.h"
#include <math.h>

static void	adjust_rotation(float *rotation)
{
	while (*rotation > PI)
		*rotation -= 2 * PI;
	while (*rotation < -PI)
		*rotation += 2 * PI;
}

void	player_move(t_player *this, float delta_time)
{
	this->x += (this->v_front * cos(this->rotation)
			+ this->v_side * sin(this->rotation)) * delta_time;
	this->y += (this->v_front * sin(this->rotation)
			- this->v_side * cos(this->rotation)) * delta_time;
	this->rotation += this->v_rotation * delta_time;
	adjust_rotation(&this->rotation);
}
