/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:24:20 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 20:49:30 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H
# include "t_keys.h"

//TODO check for collisions
typedef struct s_player
{
	float	x;
	float	y;
	float	rotation;
	float	v_front;
	float	v_side;
	float	v_rotation;
	float	size;
	void	(*move)(struct s_player *this, float delta_time);
	void	(*on_key)(struct s_player *this, t_keys *game);
}	t_player;

void	player_init(t_player *player, float x, float y, float rotation);
void	player_move(t_player *this, float delta_time);
void	player_on_key(t_player *this, t_keys *keys);

#endif