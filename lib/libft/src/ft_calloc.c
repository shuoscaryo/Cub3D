/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:29:12 by orudek            #+#    #+#             */
/*   Updated: 2023/03/17 13:23:05 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*out;
	size_t	i;

	i = 0;
	out = malloc (number * size);
	if (!out)
		return (NULL);
	while (i < number * size)
		((char *)out)[i++] = 0;
	return (out);
}
/*
int	main()
{
	char *hola = calloc(5, 4);
	int i = 0;
	for (i = 0; i < 20; i++)
		printf("%d", hola[i++]);
}*/