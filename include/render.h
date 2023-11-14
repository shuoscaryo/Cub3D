/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:12:52 by orudek            #+#    #+#             */
/*   Updated: 2023/11/14 17:17:03 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef struct s_game	t_game;
typedef struct s_img	t_img;

typedef struct s_ray
{
	float	x;
	float	y;
	float	delta_x;
	float	delta_y;
	int		next_x;
	int		next_y;
	int		face;
	float	alpha;
	t_img	*img;
}	t_ray;

t_img	*render(t_game *game, t_img *img);

#endif