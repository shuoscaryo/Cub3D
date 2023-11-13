/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_img.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:43:22 by orudek            #+#    #+#             */
/*   Updated: 2023/11/13 17:13:29 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_IMG_H
# define T_IMG_H

typedef struct s_img
{
	char	*filename;
	void	*img;
	char	*addr;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
	int		height;
	int		width;
}	t_img;

t_img	*img_new(void *mlx, char *filename);
t_img	*img_new2(void *mlx, int width, int height);
int		img_get_pixel(t_img *this, int x, int y);
void	img_pixel_put(t_img *this, int x, int y, int color);
int		img_cmp(void *img1, void *img2);
void	img_free(t_img *this, void *mlx);

#endif