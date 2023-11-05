/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:43:43 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/05 15:42:29 by orudek           ###   ########.fr       */
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
	close(game->map.fd);
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

void	free_map(t_map *map)
{
	if (map->NO)
		free(map->NO);
	if (map->SO)
		free(map->SO);
	if (map->WE)
		free(map->WE);
	if (map->EA)
		free(map->EA);
}

int	all_data(t_map *map)
{
	if (map->NO && map->SO && map->WE && map->EA && map->F[0] != -1 && map->C[0] != -1)
		return (1);
	return (0);
}

int	parse_line(char *str, int *player)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
		{
			if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
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

int	get_map(t_map *map)
{
	char	*buff;
	t_list	*list;
	t_list	*aux;
	int		i;
	int		player;

	list = NULL;
	player = 0;
	buff = get_next_line(map->fd);
	while (buff != NULL && buff[0] == '\n')
	{
		free(buff);
		buff = get_next_line(map->fd);
	}
	while (buff != NULL)
	{
		if (buff[0] == '\n')
		{
			free(buff);
			buff = get_next_line(map->fd);
			break;
		}
		delete_n(buff);
		if (parse_line(buff, &player))
			ft_lstadd_back_content(&list, buff);
		else
		{
			printf("Error.\nMap is invalid.\n");
			free(buff);
			return (ft_lstfree(list, free), 0);
		}
		buff = get_next_line(map->fd);
	}
	if (player == 0)
	{
		printf("Error.\nMap is invalid.\n");
		free(buff);
		return (ft_lstfree(list, free), 0);
	}
	while (buff != NULL)
	{
		if (buff[0] == '\n')
		{
			free(buff);
			buff = get_next_line(map->fd);
			continue ;
		}
		else
		{
			printf("Error.\nMap is invalid.\n");
			free(buff);
			return (ft_lstfree(list, free), 0);
		}
	}
	map->map = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!map->map)
		return (printf("Error.\nMalloc error (map).\n"), 0);
	i = 0;
	while (list)
	{
		map->map[i] = list->content;
		aux = list;
		list = list->next;
		free(aux);
		printf("%s\n", map->map[i]);
		i++;
	}
	map->map[i] = NULL;
	close(map->fd);
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
			if (i == 0 || i == last)
			{
				if (map[i][j] != '1' && map[i][j] != ' ')
					return (printf("Error.\nMap is invalid.\n"), 0);
			}
			else
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
						if (j > (int)(ft_strlen(map[i + 1]) - 1) || j > (int)(ft_strlen(map[i - 1]) - 1))
							return (printf("Error.\nMap is invalid.\n"), 0);
						if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
							return (printf("Error.\nMap is invalid.\n"), 0);
					}
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	read_map(t_map *map, char *path)
{
	char	*line;
	char	**aux;
	char	**colors;

	map->fd = open(path, O_RDONLY);
	if (map->fd == -1)
		return (printf("Error.\nUnexpected error reading Map.\n"), 0);
	init_var(map);
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
		aux = ft_split(line, ' ');
		if (!aux)
			return (printf("Error.\nMap is empty.\n"), 0);
		else if (ft_strcmp(aux[0], "NO") == 0)
		{
			if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1 || map->NO != NULL)
			{
				ft_array_free(aux);
				free(line);
				return (printf("Error.\nTexture NO bad set.\n"), 0);
			}
			map->NO = ft_strdup(aux[1]);
		}
		else if (ft_strcmp(aux[0], "SO") == 0)
		{
			if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1 || map->SO != NULL)
			{
				ft_array_free(aux);
				free(line);
				return (printf("Error.\nTexture SO bad set.\n"), 0);
			}
			map->SO = ft_strdup(aux[1]);
		}
		else if (ft_strcmp(aux[0], "WE") == 0)
		{
			if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1 || map->WE != NULL)
			{
				ft_array_free(aux);
				free(line);
				return (printf("Error.\nTexture WE doesn't exist.\n"), 0);
			}
			map->WE = ft_strdup(aux[1]);
		}
		else if (ft_strcmp(aux[0], "EA") == 0)
		{
			if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1 || map->EA != NULL)
			{
				ft_array_free(aux);
				free(line);
				return (printf("Error.\nTexture EA doesn't exist.\n"), 0);
			}
			map->EA = ft_strdup(aux[1]);
		}
		else if (ft_strcmp(aux[0], "F") == 0)
		{
			if (aux[1] == NULL || map->F[0] != -1)
			{
				ft_array_free(aux);
				free(line);
				return (printf("Error.\nColor F bad set.\n"), 0);
			}
			colors = ft_split(aux[1], ',');
			if (!colors || !colors[0] || !colors[1] || !colors[2])
			{
				ft_array_free(aux);
				ft_array_free(colors);
				free(line);
				return (printf("Error.\nColor F doesn't exist.\n"), 0);
			}
			map->F[0] = ft_atoi(colors[0]);
			map->F[1] = ft_atoi(colors[1]);
			map->F[2] = ft_atoi(colors[2]);
			ft_array_free(colors);
		}
		else if (ft_strcmp(aux[0], "C") == 0)
		{
			if (aux[1] == NULL || map->C[0] != -1)
			{
				ft_array_free(aux);
				ft_array_free(colors);
				free(line);
				return (printf("Error.\nColor C bad set.\n"), 0);
			}
			colors = ft_split(aux[1], ',');
			if (!colors || !colors[0] || !colors[1] || !colors[2])
			{
				ft_array_free(aux);
				free(line);
				return (printf("Error.\nColor C doesn't exist.\n"), 0);
			}
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
		if (all_data(map))
			break ;
		line = get_next_line(map->fd);
	}
	if (!get_map(map))
		exit(0);
	if (!valid_map(map->map))
		exit(0);
	return (1);
}