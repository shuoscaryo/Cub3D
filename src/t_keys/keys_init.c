/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:47:37 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 12:10:34 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_keys.h"

void	keys_init(t_keys *this)
{
	this->keys = NULL;
	this->update = keys_update;
	this->free = keys_free;
	this->get_status = keys_get_status;
}