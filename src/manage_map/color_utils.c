/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:16:03 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/23 15:33:38 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	correct_commas(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == ',')
			i++;
		str++;
	}
	if (i != 2)
		return (0);
	return (1);
}

int	n_col(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
		return (0);
	return (1);
}
