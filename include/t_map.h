/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:33:02 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/16 17:34:28 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

typedef struct s_map {
	int		fd;
	char	**map;
	int		floor;
	int		ceiling;
	int		x;
	int		y;
	float	rotation;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_map;

int		read_map(t_map *map, char *path);
void	map_free(t_map *map);
int		get_textures(char **aux, t_map *map);
int		are_nbr(char **colors);
int		get_map(t_map *map);
int		parse_line(char *str, int *player);
void	delete_n(char *line);
int		valid_map(char **map);
void	init_var(t_map *map);
void	set_player(t_map *map);
int		is_wall(char **map, int x, int y);
int		get_intcolor(char **colors);

#endif