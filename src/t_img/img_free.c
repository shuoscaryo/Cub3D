/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:24:00 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 14:34:19 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_textures.h"
#include "mlx.h"
#include <stdlib.h>

void	img_free(t_img *this, void *mlx)
{
	if (this->img)
	{
		mlx_destroy_image(mlx, this->img);
		this->img = NULL;
		this->addr = NULL;
	}
	if (this->filename)
	{
		free(this->filename);
		this->filename = NULL;
	}
}
