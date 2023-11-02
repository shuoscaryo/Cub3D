/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:38:58 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 15:40:05 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	while (dst[i])
		i++;
	while (*src && i + 1 < size)
	{
		dst[i++] = *src++;
	}
	dst[i] = 0;
	if (dst_len <= size)
		return (src_len + dst_len);
	return (src_len + size);
}
/*
#include <stdio.h>

int main()
{
	char dst[30] = "CCCCCC";
	const char src[] = "AAAAAAAAA";
	
	dst[10] = 'a';
	size_t i = ft_strlcat(dst, src, -1);
	printf("%ld||%s\n", i, dst);
}*/