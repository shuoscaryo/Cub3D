/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_walls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:30:38 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 22:54:15 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WALLS_H
# define T_WALLS_H

#include "cub3d.h"
#include "t_textures.h"
#include "libft.h"

typedef struct s_walls t_walls;

typedef struct s_wall
{
	int		x;
	int		y;
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
}	t_wall;

int		wall_cmp(void *wall1, void *wall2);
void	wall_init(t_wall *wall, t_walls *walls, int x, int y);

typedef struct s_walls
{
	t_list	**walls;
	int	size;
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
	int		(*add_wall)(struct s_walls *this, int x, int y);
	t_wall	*(*get_wall)(struct s_walls *this, int x, int y);
	void	(*free)(struct s_walls *this);
}	t_walls;

int		walls_init(t_walls *this, int size, t_game *game);
int		walls_add_wall(t_walls *this, int x, int y);
t_wall	*walls_get_wall(t_walls *this, int x, int y);
void	walls_free(t_walls *this);
int		walls_get_hash(int size, int x, int y);

#endif