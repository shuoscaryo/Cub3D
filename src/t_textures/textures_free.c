/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:17:40 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 14:42:28 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_textures.h"

void	textures_free(t_textures *this, void *mlx)
{
	t_list	*tmp;

	if (!this)
		return ;
	while(this->textures)
	{
		tmp = this->textures;
		this->textures = this->textures->next;
		((t_img *)tmp->content)->free((t_img *)tmp->content, mlx);
		free(tmp->content);
		free(tmp);
	}
	this->textures = NULL;
}
