/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:44:16 by orudek            #+#    #+#             */
/*   Updated: 2023/11/12 14:36:33 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player.h"
#include "defines.h"
#include <math.h>
#include "cub3d.h"

static void	adjust_rotation(float *rotation)
{
	while (*rotation > PI)
		*rotation -= 2 * PI;
	while (*rotation < -PI)
		*rotation += 2 * PI;
}

void	player_move(t_player *this, t_game *game, float delta_time)
{
	float x;
	float y;
	float vx;
	float vy;
	float previous_x;
	float previous_y;

	previous_x = this->x;
	previous_y = this->y;
	vx = this->v_front * cos(this->rotation)
		- this->v_side * sin(this->rotation);
	vy = + this->v_front * sin(this->rotation)
		+ this->v_side * cos(this->rotation);
	x = this->x + vx * delta_time;
	y = this->y + vy * delta_time;
	this->rotation += this->v_rotation * delta_time;
	adjust_rotation(&this->rotation);
	//printf("vx: %f, vy: %f\n", vx, vy);
	if (is_wall(game->map.map, (int)(x + this->size * ((vx > 0) - (vx < 0))), y))
		this->x = (int)(x) + (vx > 0) + this->size * ((vx < 0) - (vx > 0));
	else
		this->x = x;
	if (is_wall(game->map.map, x, (int)(y + this->size * ((vy > 0) - (vy < 0)))))
		this->y = (int)(y) + (vy > 0) + this->size * ((vy < 0) - (vy > 0));
	else
		this->y = y;
	if (is_wall(game->map.map, (int)this->x, (int)this->y))
	{
		this->x = previous_x;
		this->y = previous_y;
	}
}
