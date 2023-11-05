/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:46:17 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 22:53:28 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_walls.h"

void	wall_init(t_wall *wall, t_walls *walls, int x, int y)
{
	wall->x = x;
	wall->y = y;
	wall->no = walls->no;
	wall->so = walls->so;
	wall->we = walls->we;
	wall->ea = walls->ea;
}
