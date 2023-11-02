/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:43:43 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/02 20:49:52 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_params(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (printf("Error.\nPlease enter Map.\n"), 0);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		return (printf("Error.\nPlease enter a valid Map.\n"), 0);
	game->map.fd = open(argv[1], O_RDONLY);
	if (game->map.fd == -1)
		return (printf("Error.\nMap doesn't exist.\n"), 0);
	return (1);
}

void delete_n(char *line)
{
	int i;

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

int	read_map(t_map *map)
{
	char	*line;
	int		i;
	char	**aux;
	char	**colors;

	i = 0;
	init_var(map);
	while ((line = get_next_line(map->fd)) > 0)
	{
		delete_n(line);
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		aux = ft_split(line, ' ');
		if (!aux)
			return (printf("Error.\nMap is empty.\n"), 0);
		else if (ft_strcmp(aux[0], "NO") == 0)
		{
			if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1)
				return (printf("Error.\nTexture NO doesn't exist.\n"), 0);
			if (map->NO != NULL)
				return (printf("Error.\nTexture NO is duplicated.\n"), 0);
			map->NO = ft_strdup(aux[1]);
		}
		else if (ft_strcmp(aux[0], "SO") == 0)
		{
			if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1)
				return (printf("Error.\nTexture SO doesn't exist.\n"), 0);
			if (map->SO != NULL)
				return (printf("Error.\nTexture SO is duplicated.\n"), 0);
			map->SO = ft_strdup(aux[1]);
		}
		else if (ft_strcmp(aux[0], "WE") == 0)
		{
			if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1)
				return (printf("Error.\nTexture WE doesn't exist.\n"), 0);
			if (map->WE != NULL)
				return (printf("Error.\nTexture WE is duplicated.\n"), 0);
			map->WE = ft_strdup(aux[1]);
		}
		else if (ft_strcmp(aux[0], "EA") == 0)
		{
			if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1)
				return (printf("Error.\nTexture EA doesn't exist.\n"), 0);
			if (map->EA != NULL)
				return (printf("Error.\nTexture EA is duplicated.\n"), 0);
			map->EA = ft_strdup(aux[1]);
		}
		else if (ft_strcmp(aux[0], "F") == 0)
		{
			if (aux[1] == NULL)
				return (printf("Error.\nColor F doesn't exist.\n"), 0);
			colors = ft_split(aux[1], ',');
			if (!colors || !colors[0] || !colors[1] || !colors[2])
				return (printf("Error.\nColor F doesn't exist.\n"), 0);
			if (map->F[0] != -1)
				return (printf("Error.\nColor F is duplicated.\n"), 0);
			map->F[0] = ft_atoi(colors[0]);
			map->F[1] = ft_atoi(colors[1]);
			map->F[2] = ft_atoi(colors[2]);
			ft_array_free(colors);
		}
		else if (ft_strcmp(aux[0], "C") == 0)
		{
			if (aux[1] == NULL)
				return (printf("Error.\nColor C doesn't exist.\n"), 0);
			colors = ft_split(aux[1], ',');
			if (!colors || !colors[0] || !colors[1] || !colors[2])
				return (printf("Error.\nColor C doesn't exist.\n"), 0);
			if (map->C[0] != -1)
				return (printf("Error.\nColor C is duplicated.\n"), 0);
			map->C[0] = ft_atoi(colors[0]);
			map->C[1] = ft_atoi(colors[1]);
			map->C[2] = ft_atoi(colors[2]);
			ft_array_free(colors);
		}
		else
		{
			ft_array_free(aux);
			free(line);
			return (printf("Error.\nMap is invalid.\n"), 0);
		}
		ft_array_free(aux);
		free(line);
	}
	return (1);
}