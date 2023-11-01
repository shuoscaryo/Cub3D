/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:39:24 by orudek            #+#    #+#             */
/*   Updated: 2023/03/17 15:40:27 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	is_negative;

	num = 0;
	is_negative = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (ft_isdigit(*str))
		num = num * 10 + *str++ - '0';
	return (num * is_negative);
}
/*
int main()
{
    char *hola= "546:5";
    printf("mi atoi: %d\natoi oficial: %d\n", ft_atoi(hola),atoi(hola));
}*/