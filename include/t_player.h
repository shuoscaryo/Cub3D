/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:24:20 by orudek            #+#    #+#             */
/*   Updated: 2023/11/03 22:04:50 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H
# include "t_keys.h"

typedef struct s_player
{
	float x;
	float y;
	float rotation;
	float vx;
	float vy;
	float rotation_speed;
	float size; // player is a cylinder, size is the diameter
	void (*move)(struct s_player *this, float delta_time); //TODO check for collisions
	void (*on_key)(struct s_player *this, t_keys *game);
}   t_player;

void	player_init(t_player *player, float x, float y, float rotation);
void	player_move(t_player *this, float delta_time);
void	player_on_key(t_player *this, t_keys *keys);

# endif