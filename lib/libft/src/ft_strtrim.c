/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:35 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 14:39:42 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static size_t	ft_get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (ft_is_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	ft_get_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (ft_is_in_set(s1[end], set) && end > 0)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	start;
	size_t	end;
	size_t	k;

	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	if (start > end)
		start = end;
	else
		end++;
	out = malloc(end - start + 1);
	if (out == NULL)
		return (NULL);
	k = 0;
	while (end > start)
		out[k++] = s1[start++];
	out[k] = 0;
	return (out);
}
/*
#include <stdio.h>

int main()
{
	char s1[] = "abcdba";
	printf("%s$\n",ft_strtrim(s1,"acb"));
}*/