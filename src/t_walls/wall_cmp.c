/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:46:45 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 22:48:38 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_walls.h"

int	wall_cmp(void *wall1, void *wall2)
{
	t_wall	*w1;
	t_wall	*w2;

	w1 = (t_wall *)wall1;
	w2 = (t_wall *)wall2;
	if (w1->x == w2->x && w1->y == w2->y)
		return (1);
	return (0);
}
