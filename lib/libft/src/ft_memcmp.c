/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:42:51 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 16:41:33 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*in1;
	const unsigned char	*in2;

	in1 = s1;
	in2 = s2;
	i = 0;
	if (!n)
		return (0);
	while (in1[i] == in2[i] && i < n - 1)
		i++;
	return (in1[i] - in2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	printf("%d\n",ft_memcmp(s2,s3,4));
//	printf("%d\n",memcmp(v[1],v[2],10));
}*/
