/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_textures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:40:30 by orudek            #+#    #+#             */
/*   Updated: 2023/11/06 19:44:15 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TEXTURES_H
# define T_TEXTURES_H
# include "libft.h"
# include "t_img.h"

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