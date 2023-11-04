/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:24:00 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 14:06:53 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
#include "mlx.h"
#include <stdlib.h>

char	ft_img_free(void *mlx, t_img **img)
{
	if ((*img)->img)
	{
		mlx_destroy_image(mlx, (*img)->img);
		(*img)->img = NULL;
		(*img)->addr = NULL;
	}
	if ((*img)->filename)
	{
		free((*img)->filename);
		(*img)->filename = 0;
	}
	free(*img);
	*img = NULL;
	return (0);
}
