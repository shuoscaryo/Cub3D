/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:39:34 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/09 15:14:17 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_closed(char **map, int i, int j)
{
	if (j == 0 || j == (int)(ft_strlen(map[i]) - 1))
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (printf("Error.\nMap is invalid.\n"), 0);
	}
	else
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
		{
			if (j > (int)(ft_strlen(map[i + 1]) - 1)
				|| j > (int)(ft_strlen(map[i - 1]) - 1))
				return (printf("Error.\nMap is invalid.\n"), 0);
			if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
				|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
				return (printf("Error.\nMap is invalid.\n"), 0);
		}
	}
	return (1);
}

int	check_walls(char **map, int i, int j, int last)
{
	if (i == 0 || i == last)
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (printf("Error.\nMap is invalid.\n"), 0);
	}
	else
	{
		if (!is_closed(map, i, j))
			return (0);
	}
	return (1);
}

int	valid_map(char **map)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	while (map[i])
		i++;
	last = i - 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_walls(map, i, j, last))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void set_player(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (ft_strchr("NSEW", map->map[i][j]))
			{
				map->x = j + 0.5;
				map->y = i + 0.5;
				if (map->map[i][j] == 'N')
					map->rotation = - PI / 2;
				if (map->map[i][j] == 'S')
					map->rotation = PI / 2;
				if (map->map[i][j] == 'E')
					map->rotation = 0;
				if (map->map[i][j] == 'W')
					map->rotation = PI;
				map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}