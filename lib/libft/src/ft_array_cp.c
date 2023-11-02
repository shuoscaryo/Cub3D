/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_cp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:55:55 by orudek            #+#    #+#             */
/*   Updated: 2023/08/09 00:21:45 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_cp(char **array)
{
	char	**new_array;
	int		size;
	int		i;

	if (!array)
		return (NULL);
	size = 0;
	while (array[size])
		size++;
	new_array = malloc(sizeof(char *) * (size + 1));
	if (!new_array)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		new_array[i] = ft_strdup(array[i]);
		if (new_array[i] == NULL)
		{
			ft_array_free(new_array);
			return (NULL);
		}
	}
	new_array[size] = NULL;
	return (new_array);
}
