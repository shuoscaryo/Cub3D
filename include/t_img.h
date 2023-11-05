/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_img.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:40:30 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 13:12:54 by orudek           ###   ########.fr       */
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
	void	(*put_pixel)(struct s_img *this, int x, int y, int color);
	int		(*get_pixel)(struct s_img *this, int x, int y);
	void	(*free)(struct s_img *this, void *mlx);
}	t_img;

t_img	*img_new(void *mlx, char *filename);
int		img_get_pixel(t_img *this, int x, int y);
void	img_pixel_put(t_img *this, int x, int y, int color);
void	img_free(t_img *this, void *mlx);

#endif