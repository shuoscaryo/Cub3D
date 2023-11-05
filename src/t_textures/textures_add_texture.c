/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_add_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:42:01 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 18:57:46 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_textures.h"

int	textures_add_texture(t_textures *this, char *filename, void *mlx)
{
	t_img	*new;

	new = img_new(mlx, filename);
	if (!new)
		return (0);
	if (ft_lstfind(this->textures, new, new->cmp))
		return (new->free(new, mlx), free(new), 1);
	if (!ft_lstadd_back_content(&this->textures, new))
		return (new->free(new, mlx), free(new), 0);
	return (1);
}
