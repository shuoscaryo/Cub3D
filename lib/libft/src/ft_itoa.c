/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:25:47 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 17:00:37 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(int n)
{
	int	i;

	i = 1;
	while (n < -9 || n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		i;
	int		is_negative;

	is_negative = (n < 0);
	i = ft_get_len(n);
	out = malloc (i + is_negative + 1);
	if (out == NULL)
		return (NULL);
	out[0] = '-';
	out[i + is_negative] = '\0';
	while (i > 0)
	{
		out[i-- - 1 + is_negative] = n % 10 * ((n > 0) - (n < 0)) + '0';
		n /= 10;
	}
	return (out);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(1));
}
*/