/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:52:00 by orudek            #+#    #+#             */
/*   Updated: 2023/08/20 14:16:44 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_msg_err(const char *msg, long ret_val)
{
	if (msg)
	{
		write(2, "ERROR: ", 7);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	return (ret_val);
}
