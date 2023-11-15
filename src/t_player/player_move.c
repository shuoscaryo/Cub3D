/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:44:16 by orudek            #+#    #+#             */
/*   Updated: 2023/11/15 21:54:37 by orudek           ###   ########.fr       */
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

static int	collision(char **map, float new_x, float new_y, float size)
{
	if (is_wall(map, new_x + size, new_y)
		|| is_wall(map, new_x - size, new_y)
		|| is_wall(map, new_x, new_y + size)
		|| is_wall(map, new_x, new_y - size))
		return (1);
	return (0);
}

void	player_move(t_player *p, t_game *game, float delta_time)
{
	float	vx;
	float	vy;
	float	new_x;
	float	new_y;

	vx = p->v_front * cos(p->rotation)
		- p->v_side * sin(p->rotation);
	vy = p->v_front * sin(p->rotation)
		+ p->v_side * cos(p->rotation);
	new_x = p->x + vx * delta_time;
	new_y = p->y + vy * delta_time;
	p->rotation += p->v_rotation * delta_time;
	adjust_rotation(&p->rotation);
	if (collision(game->map.map, new_x, new_y, p->size))
		return ;
	p->x = new_x;
	p->y = new_y;
}
