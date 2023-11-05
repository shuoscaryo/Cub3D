/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_get_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:42:41 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 22:48:46 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_walls.h"

t_wall	*walls_get_wall(t_walls *walls, int x, int y)
{
	int		index;
	t_wall	aux;

	index = walls_get_hash(walls->size, x, y);
	wall_init(&aux, walls, x, y);
	return (ft_lstfind(walls->walls[index], &aux, wall_cmp));
}
