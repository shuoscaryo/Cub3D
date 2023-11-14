/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:11:27 by orudek            #+#    #+#             */
/*   Updated: 2023/11/14 16:15:05 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"
#include "libft.h"

void	map_free(t_map *map)
{
	if (map->map)
		ft_array_free(map->map);
	if (map->NO)
		free(map->NO);
	if (map->SO)
		free(map->SO);
	if (map->WE)
		free(map->WE);
	if (map->EA)
		free(map->EA);
}
