/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:11:53 by orudek            #+#    #+#             */
/*   Updated: 2023/11/23 15:08:09 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_WIDTH 1080
# define WIN_HEIGHT 720

# if defined(__linux__)
#  define D 100
#  define W 119
#  define A 97
#  define S 115
#  define RIGHT 65363
#  define LEFT 65361
#  define ESC 65307
# elif defined(__APPLE__)
#  define D 2
#  define W 13
#  define A 0
#  define S 1
#  define RIGHT 124
#  define LEFT 123
#  define ESC 53
# endif

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	NO_EVENT_MASK = 0L,
	KEY_PRESS_MASK = (1L<<0),
	KEY_RELEASE_MASK = (1L<<1)
};

# define PLAYER_SIZE 0.2f
# define PLAYER_MOVE_SPEED 1.0f
# define PLAYER_ROT_SPEED 0.6f

# define PI 3.14159265359
# define FOV 50.0f
# define RENDER_DISTANCE 40

#endif
