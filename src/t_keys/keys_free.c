/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:10:56 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 14:17:48 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_keys.h"

void	keys_free(void *this)
{
	ft_lstfree(((t_keys *)this)->keys, free);
	((t_keys *)this)->keys = NULL;
	//free(this); maybe?
}
