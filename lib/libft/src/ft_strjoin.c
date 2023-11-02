/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:05 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 13:46:24 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*out;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	out = malloc(len_s1 + len_s2 + 1);
	if (out == NULL)
		return (NULL);
	(void)ft_strlcpy(out, s1, len_s1 + 1);
	(void)ft_strlcpy(out + len_s1, s2, len_s2 + 1);
	return (out);
}
/*
#include <stdio.h>

int main()
{
		char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	printf("%s$\n",ft_strjoin(s1,s2));
}*/