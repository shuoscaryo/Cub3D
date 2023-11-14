/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:18:14 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/14 16:38:27 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "defines.h"
# include "libft.h"
# include "get_next_line.h"
# include "t_keys.h"
# include "t_player.h"
# include "t_map.h"
# include "t_img.h"

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_img		*img;
	t_list		*keys;
	t_img		*textures[4];
	t_map		map;
	t_player	player;
}	t_game;

int		game_init(t_game *game, char *file);
int		on_key_up(int key, t_game *game);
int		on_key_down(int key, t_game *game);
int		game_exit(t_game *game);
int		dibuja(t_game *game);
t_img	*render(t_game *game, t_img *img);

#endif