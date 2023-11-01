/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:46:32 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 17:48:47 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup("\0"));
	if (str_len - start <= len)
		str_len -= (int)start;
	else
		str_len = len;
	out = malloc (str_len + 1);
	if (out == NULL)
		return (NULL);
	(void)ft_strlcpy(out, &s[start], str_len + 1);
	return (out);
}
/*
#include <stdio.h>

int main()
{
	const char str[] = "lorem ipsum dolor sit amet";
	printf("%s$\n",ft_substr("",1,1));
	return (0);
}*/
