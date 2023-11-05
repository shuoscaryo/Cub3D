/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_get_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:07:56 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 18:58:00 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_textures.h"

t_img	*textures_get_texture(t_textures *this, char *filename)
{
	t_list	*list;

	list = this->textures;
	while (list)
	{
		if (ft_strcmp(((t_img *)list->content)->filename, filename) == 0)
			return ((t_img *)list->content);
		list = list->next;
	}
	return (NULL);
}
