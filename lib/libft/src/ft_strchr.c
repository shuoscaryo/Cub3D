/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:38:08 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 16:04:37 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s || !(char)c)
		return ((char *)s);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(int c, char **v)
{
	if ( c == 3)
	{
		printf("mio>>%s\n",ft_strchr(v[1],v[2][0]));
		printf("oficial>>%s\n",strchr(v[1],v[2][0]));
	}
	return (1);	
}*/
