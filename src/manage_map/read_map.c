/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:43:43 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/23 14:37:03 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_data(t_map *map)
{
	if (map->no && map->so && map->we
		&& map->ea && map->floor != -1 && map->ceiling != -1)
		return (1);
	return (0);
}

int	parse_data(t_map *map, char *line)
{
	char	**aux;

	aux = ft_split(line, ' ');
	if (!aux)
		return (printf("Error.\nMap is empty.\n"), 0);
	if (!get_textures(aux, map))
	{
		ft_array_free(aux);
		return (0);
	}
	ft_array_free(aux);
	return (1);
}

int	get_data(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	while (line != NULL)
	{
		delete_n(line);
		if (*line == '\0')
		{
			free(line);
			line = get_next_line(map->fd);
			continue ;
		}
		if (!parse_data(map, line))
			return (free(line), 0);
		free(line);
		if (all_data(map))
			break ;
		line = get_next_line(map->fd);
	}
	return (1);
}

int	read_map(t_map *map, char *path)
{
	ft_bzero(map, sizeof(t_map));
	if (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4) != 0)
		return (printf("Error.\nInvalid map name.\n"), 0);
	map->fd = open(path, O_RDONLY);
	if (map->fd == -1)
		return (printf("Error.\nCouldn't open map.\n"), 0);
	init_var(map);
	if (!get_data(map))
		return (0);
	if (!get_map(map))
		exit(0);
	if (!valid_map(map->map))
		exit(0);
	return (1);
}
