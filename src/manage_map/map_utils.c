/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:09:12 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/16 17:34:11 by iortega-         ###   ########.fr       */
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
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->floor = -1;
	map->ceiling = -1;
}

int	get_intcolor(char **colors)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (printf("Error.\nColor doesn't exist.\n"), -1);
	color = (r << 16 | g << 8 | b);
	return (color);
}
