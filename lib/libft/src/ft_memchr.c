/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:09:40 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 18:49:13 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		n--;
		str++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int c, char **v)
{
	if ( c == 4)
	{
		printf("mio>>%s\n",ft_memchr(v[1],v[2][0],atoi(v[3])));
		printf("oficial>>%s\n",memchr(v[1],v[2][0],atoi(v[3])));
	}
	return (1);
}*/
