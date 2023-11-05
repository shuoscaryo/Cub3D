/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:39:08 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 13:41:39 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_textures.h"

void   textures_init(t_textures *this)
{
	this->textures = NULL;
	this->add_texture = textures_add_texture;
	this->get_texture = textures_get_texture;
	this->free = textures_free;
}
