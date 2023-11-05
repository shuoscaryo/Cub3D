/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:18:14 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/05 19:01:52 by iortega-         ###   ########.fr       */
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
# include "t_textures.h"
# include "t_map.h"

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_map		map;
	t_keys		keys;
	t_player	player;
	t_textures	textures;
}	t_game;

int 	on_key_up(int key, t_game *game);
int		on_key_down(int key, t_game *game);
int		check_params(int argc, char **argv, t_game *game);


#endif