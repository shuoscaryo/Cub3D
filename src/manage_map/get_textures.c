/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:30:39 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/23 15:37:01 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_no_so(char **aux, t_map *map)
{
	if (ft_strcmp(aux[0], "NO") == 0)
	{
		if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1
			|| map->no != NULL || aux[2] != NULL)
			return (printf("Error.\nTexture NO bad set.\n"), -1);
		map->no = ft_strdup(aux[1]);
	}
	else if (ft_strcmp(aux[0], "SO") == 0)
	{
		if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1
			|| map->so != NULL || aux[2] != NULL)
			return (printf("Error.\nTexture SO bad set.\n"), -1);
		map->so = ft_strdup(aux[1]);
	}
	else
		return (0);
	return (1);
}

int	get_we_ea(char **aux, t_map *map)
{
	if (ft_strcmp(aux[0], "WE") == 0)
	{
		if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1
			|| map->we != NULL || aux[2] != NULL)
			return (printf("Error.\nTexture WE bad set.\n"), -1);
		map->we = ft_strdup(aux[1]);
	}
	else if (ft_strcmp(aux[0], "EA") == 0)
	{
		if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1
			|| map->ea != NULL || aux[2] != NULL)
			return (printf("Error.\nTexture EA bad set.\n"), -1);
		map->ea = ft_strdup(aux[1]);
	}
	else
		return (0);
	return (1);
}

int	get_f(char **aux, t_map *map)
{
	char	**colors;

	if (ft_strcmp(aux[0], "F") == 0)
	{
		if (aux[1] == NULL || map->floor != -1 || aux[2] != NULL)
			return (printf("Error.\nColor F bad set.\n"), -1);
		colors = ft_split(aux[1], ',');
		if (!colors || !colors[0] || !colors[1] || !colors[2])
		{
			ft_array_free(colors);
			return (printf("Error.\nColor F doesn't exist.\n"), -1);
		}
		if (!are_nbr(colors) || !correct_commas(aux[1]) || !n_col(colors))
		{
			ft_array_free(colors);
			return (printf("Error.\nColor F doesn't exist.\n"), -1);
		}
		map->floor = get_intcolor(colors);
		if (map->floor == -1)
			return (ft_array_free(colors), -1);
		ft_array_free(colors);
	}
	else
		return (0);
	return (1);
}

int	get_c(char **aux, t_map *map)
{
	char	**colors;

	if (ft_strcmp(aux[0], "C") == 0)
	{
		if (aux[1] == NULL || map->ceiling != -1 || aux[2] != NULL)
			return (printf("Error.\nColor C bad set.\n"), -1);
		colors = ft_split(aux[1], ',');
		if (!colors || !colors[0] || !colors[1] || !colors[2])
		{
			ft_array_free(colors);
			return (printf("Error.\nColor C doesn't exist.\n"), -1);
		}
		if (!are_nbr(colors) || !correct_commas(aux[1]) || !n_col(colors))
		{
			ft_array_free(colors);
			return (printf("Error.\nColor C doesn't exist.\n"), -1);
		}
		map->ceiling = get_intcolor(colors);
		if (map->ceiling == -1)
			return (ft_array_free(colors), -1);
		ft_array_free(colors);
	}
	else
		return (0);
	return (1);
}

int	get_textures(char **aux, t_map *map)
{
	int	result[4];

	result[0] = get_no_so(aux, map);
	result[1] = get_we_ea(aux, map);
	result[2] = get_f(aux, map);
	result[3] = get_c(aux, map);
	if (result[0] == -1 || result[1] == -1
		|| result[2] == -1 || result[3] == -1)
		return (0);
	if (result[0] == 1 || result[1] == 1
		|| result[2] == 1 || result[3] == 1)
		return (1);
	return (printf("Error.\nInvalid map.\n"), 0);
}
