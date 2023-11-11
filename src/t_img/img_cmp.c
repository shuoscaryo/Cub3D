/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:58:45 by orudek            #+#    #+#             */
/*   Updated: 2023/11/11 16:16:05 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
#include "libft.h"

int	img_cmp(void *img1, void *img2)
{
	t_img	*i1;
	t_img	*i2;

	i1 = (t_img *)img1;
	i2 = (t_img *)img2;
	return (ft_strcmp(i1->filename, i2->filename));
}
