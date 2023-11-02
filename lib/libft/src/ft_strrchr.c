/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:56:12 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 16:06:42 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (last);
}
/*
#include <stdio.h>
#include <string.h>

int main(int c, char **v)
{
	if ( c == 3)
	{
		printf("mio>>%s\n",ft_strrchr(v[1],v[2][0]));
		printf("oficial>>%s\n",strrchr(v[1],v[2][0]));
	}
	return (1);
}*/
