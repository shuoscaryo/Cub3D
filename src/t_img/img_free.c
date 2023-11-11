/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:24:00 by orudek            #+#    #+#             */
/*   Updated: 2023/11/11 16:14:25 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
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
