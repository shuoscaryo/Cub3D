/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:16:06 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 20:45:45 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int	gnl_strlen(const char *str)
{
	unsigned int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str++)
		count++;
	return (count);
}

unsigned char	gnl_strchr(const char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

char	gnl_strjoin(char **str, const char *buf, unsigned int size)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	j;

	if (size == 0)
		return (1);
	new_str = malloc(gnl_strlen(*str) + size + 1);
	if (!new_str)
		return (0);
	i = 0;
	while ((*str)[i])
	{
		new_str[i] = (*str)[i];
		i++;
	}
	j = 0;
	while (j < size)
		new_str[i + j++] = *buf++;
	new_str[i + j] = 0;
	free(*str);
	*str = new_str;
	return (1);
}

void	gnl_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	gnl_free(char *str)
{
	free(str);
	return (0);
}
