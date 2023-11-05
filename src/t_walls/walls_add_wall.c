/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_add_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:56:18 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 22:53:45 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_walls.h"

int	walls_add_wall(t_walls *walls, int x, int y)
{
	t_wall	*new;
	int		index;

	new = malloc(sizeof(t_wall));
	if (!new)
		return (0);
	wall_init(new, walls, x, y);
	index = walls_get_hash(walls->size, x, y);
	if (ft_lstfind(walls->walls[index], new, wall_cmp))
		return (free(new), 1);
	if (!ft_lstadd_front_content(&walls->walls[index], new))
		return (free(new), 0);
	return (1);
}
