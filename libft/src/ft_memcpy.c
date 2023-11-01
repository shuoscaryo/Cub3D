/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:06:00 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 17:06:54 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*out;
	const unsigned char	*in;

	if (!dst && !src)
		return (0);
	out = dst;
	in = src;
	i = 0;
	while (i++ < len)
		*out++ = *in++;
	return (dst);
}
