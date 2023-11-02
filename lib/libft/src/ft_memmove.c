/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:35:02 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 17:07:36 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*out;
	const char	*in;

	if (!dst && !src)
		return (0);
	out = dst;
	in = src;
	i = 0;
	if (dst > src)
	{
		out += len - 1;
		in += len - 1;
	}
	while (i++ < len)
	{
		if (dst <= src)
			*out++ = *in++;
		else
			*out-- = *in--;
	}
	return (dst);
}
/*
#include <stdio.h>

int main(void)
{
	char	*dst;
	char	src[] = "lorem ipsum dolor sit amet";
	dst = src + 1;
	printf("%s", ft_memmove(dst,"consectetur", 5));
	return (0);
}*/