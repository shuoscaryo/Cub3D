/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:09:12 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/05 18:46:50 by iortega-         ###   ########.fr       */
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

int	check_params(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (printf("Error.\nPlease enter Map.\n"), 0);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		return (printf("Error.\nPlease enter a valid Map.\n"), 0);
	game->map.fd = open(argv[1], O_RDONLY);
	if (game->map.fd == -1)
		return (printf("Error.\nMap doesn't exist.\n"), 0);
	close(game->map.fd);
	return (1);
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
