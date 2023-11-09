/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:46:35 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/09 13:46:54 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_array_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_wall(char **map, int x, int y)
{
	//printf("x: %d, y: %d\n", x, y);
	if (x < 0 || y < 0)
		return (1);
	if (y >= ft_array_len(map) || x >= (int)ft_strlen(map[y]))
		return (1);
	return (map[y][x] == '1');
}
