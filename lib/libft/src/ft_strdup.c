/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:46:08 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 13:17:07 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*out;

	len = ft_strlen(s1);
	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	(void)ft_strlcpy(out, s1, len + 1);
	return (out);
}
