/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:18:14 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/03 14:13:32 by orudek           ###   ########.fr       */
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
//# include <X11/keysym.h>
//# include <X11/X.h>
//# include "get_next_line/get_next_line.h"

# define IMG_SIZE 100

typedef struct s_map {
	int		fd;
	char	**map;
	int		F[3];
	int		C[3];
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
}	t_map;

typedef struct s_img {
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;
}	t_img;

typedef struct s_game {
	void	*mlx;
	void	*win;
	t_map	map;
}	t_game;

int 	on_key_up(int key, t_game *game);
int		on_key_down(int key, t_game *game);
int		check_params(int argc, char **argv, t_game *game);
int		read_map(t_map *map);
void	free_map(t_map *map);

#endif