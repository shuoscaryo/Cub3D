/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_textures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:40:30 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 20:50:26 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TEXTURES_H
# define T_TEXTURES_H
# include "libft.h"

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
	int		(*cmp)(void *img1, void *img2);
	void	(*free)(struct s_img *this, void *mlx);
}	t_img;

t_img	*img_new(void *mlx, char *filename);
int		img_get_pixel(t_img *this, int x, int y);
void	img_pixel_put(t_img *this, int x, int y, int color);
int		img_cmp(void *img1, void *img2);
void	img_free(t_img *this, void *mlx);

typedef struct s_textures
{
	t_list	*textures;
	int		(*add_texture)(struct s_textures *this, char *filename, void *mlx);
	t_img	*(*get_texture)(struct s_textures *this, char *filename);
	void	(*free)(struct s_textures *this, void *mlx);
}	t_textures;

void	textures_init(t_textures *this);
int		textures_add_texture(t_textures *this, char *filename, void *mlx);
t_img	*textures_get_texture(t_textures *this, char *filename);
void	textures_free(t_textures *this, void *mlx);

#endif