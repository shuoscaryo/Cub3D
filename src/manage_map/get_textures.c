/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:30:39 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/15 18:50:53 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_no_so(char **aux, t_map *map)
{
	if (ft_strcmp(aux[0], "NO") == 0)
	{
		if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1
			|| map->no != NULL || aux[2] != NULL)
			return (printf("Error.\nTexture NO bad set.\n"), 0);
		map->no = ft_strdup(aux[1]);
	}
	else if (ft_strcmp(aux[0], "SO") == 0)
	{
		if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1
			|| map->so != NULL || aux[2] != NULL)
			return (printf("Error.\nTexture SO bad set.\n"), 0);
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
			return (printf("Error.\nTexture WE bad set.\n"), 0);
		map->we = ft_strdup(aux[1]);
	}
	else if (ft_strcmp(aux[0], "EA") == 0)
	{
		if (aux[1] == NULL || open(aux[1], O_RDONLY) == -1
			|| map->ea != NULL || aux[2] != NULL)
			return (printf("Error.\nTexture EA bad set.\n"), 0);
		map->ea = ft_strdup(aux[1]);
	}
	else
		return (0);
	return (1);
}

int get_intcolor(char **colors)
{
	int r;
	int g;
	int b;
	int color;

	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (printf("Error.\nColor doesn't exist.\n"), -1);
	color = (r << 16 | g << 8 | b);
	return (color);
}

int	get_f(char **aux, t_map *map)
{
	char	**colors;

	if (ft_strcmp(aux[0], "F") == 0)
	{
		if (aux[1] == NULL || map->floor != -1 || aux[2] != NULL)
			return (printf("Error.\nColor F bad set.\n"), 0);
		colors = ft_split(aux[1], ',');
		if (!colors || !colors[0] || !colors[1] || !colors[2])
		{
			ft_array_free(colors);
			return (printf("Error.\nColor F doesn't exist.\n"), 0);
		}
		if (!are_nbr(colors))
		{
			ft_array_free(colors);
			return (printf("Error.\nColor F doesn't exist.\n"), 0);
		}
		map->floor = get_intcolor(colors);
		if (map->floor == -1)
			return (ft_array_free(colors), 0);
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
			return (printf("Error.\nColor C bad set.\n"), 0);
		colors = ft_split(aux[1], ',');
		if (!colors || !colors[0] || !colors[1] || !colors[2])
		{
			ft_array_free(colors);
			return (printf("Error.\nColor C doesn't exist.\n"), 0);
		}
		if (!are_nbr(colors))
		{
			ft_array_free(colors);
			return (printf("Error.\nColor C doesn't exist.\n"), 0);
		}
		map->ceiling = get_intcolor(colors);
		if (map->ceiling == -1)
			return (ft_array_free(colors), 0);
		ft_array_free(colors);
	}
	else
		return (0);
	return (1);
}

int	get_textures(char **aux, t_map *map)
{
	if (!get_no_so(aux, map) && !get_we_ea(aux, map)
		&& !get_f(aux, map) && !get_c(aux, map))
		return (printf("Error.\nMap is invalid.\n"), 0);
	else
		return (1);
}
