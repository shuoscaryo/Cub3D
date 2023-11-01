/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:19:48 by orudek            #+#    #+#             */
/*   Updated: 2023/09/17 17:15:48 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Function for dealocating char **
void	ft_array_free(void *array)
{
	int		i;
	char	**aux;

	aux = (char **)array;
	if (!aux)
		return ;
	i = -1;
	while (aux[++i])
		free(aux[i]);
	free(aux);
}
