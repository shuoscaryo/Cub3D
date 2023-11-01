/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by orudek            #+#    #+#             */
/*   Updated: 2023/03/18 16:55:59 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n < -9)
		ft_putnbr_fd(-(n / 10), fd);
	n %= 10;
	if (n < 0)
		n *= -1;
	n += '0';
	ft_putchar_fd((char)n, fd);
}
/*
int main ()
{
	ft_putnbr_fd(0x80000000,1);
	write(1,"$\n",2);
}*/