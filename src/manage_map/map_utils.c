/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:09:12 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/14 15:15:09 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	are_nbr(char **colors)
{
	int	i;
	int	j;

	i = 0;
	while (colors[i])
	{
		j = 0;
		while (colors[i][j])
		{
			if (colors[i][j] < '0' || colors[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_line(char *str, int *player)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
		{
			if (str[i] == 'N' || str[i] == 'S'
				|| str[i] == 'W' || str[i] == 'E')
			{
				if (*player == 1)
					return (0);
				*player = 1;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	delete_n(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}

void	init_var(t_map *map)
{
	map->NO = NULL;
	map->SO = NULL;
	map->WE = NULL;
	map->EA = NULL;
	map->F[0] = -1;
	map->F[1] = -1;
	map->F[2] = -1;
	map->C[0] = -1;
	map->C[1] = -1;
	map->C[2] = -1;
}
