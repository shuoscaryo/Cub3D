/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:12:52 by orudek            #+#    #+#             */
/*   Updated: 2023/11/16 18:13:36 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>

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
	float	dist_wall;
	float	dist_screen;
	int		new_xy[2];
	int		pixel_x;
	int		pixel_y;
	t_img	*img;
}	t_ray;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

t_img	*render(t_game *game, t_img *img);
float	dist(float x1, float y1, float x2, float y2);
float	get_percentage(int x, int y, t_ray *ray);
void	print_pixaux(t_game *game, t_ray *ray, int img_x);

#endif