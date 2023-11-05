/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:56:22 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 22:57:27 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_walls.h"

void	walls_free(t_walls *walls)
{
	int	i;

	i = 0;
	while (i < walls->size)
	{
		ft_lstfree(walls->walls[i], free);
		i++;
	}
	free(walls->walls);
}
