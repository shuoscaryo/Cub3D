/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:44:16 by orudek            #+#    #+#             */
/*   Updated: 2023/11/09 11:59:19 by iortega-         ###   ########.fr       */
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

int	ft_array_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_wall(char **map, int x, int y)
{
	printf("x: %d, y: %d\n", x, y);
	if (x < 0 || y < 0)
		return (1);
	if (y >= ft_array_len(map) || x >= (int)ft_strlen(map[y]))
		return (1);
	return (map[y][x] == '1');
}

void	player_move(t_player *this, t_game *game, float delta_time)
{
	float x;
	float y;
	float vx;
	float vy;
	
	vx = this->v_front * cos(this->rotation)
		+ this->v_side * sin(this->rotation);
	vy = this->v_front * sin(this->rotation)
		- this->v_side * cos(this->rotation);
	x = this->x + vx * delta_time;
	y = this->y - vy * delta_time;
	this->rotation += this->v_rotation * delta_time;
	adjust_rotation(&this->rotation);
	if (is_wall(game->map.map, (int)(x + this->size * ((vx > 0) - (vx < 0))), y))
		this->x = (int)(x + this->size * ((vx > 0) - (vx < 0))) + (vx < 0);
	else
		this->x = x;
	if (is_wall(game->map.map, x, (int)(y + this->size * ((vy > 0) - (vy < 0)))))
		this->y = (int)(y + this->size * ((vy > 0) - (vy < 0))) + (vy < 0);
	else
		this->y = y;
}
