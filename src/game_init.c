/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:27:36 by orudek            #+#    #+#             */
/*   Updated: 2023/11/14 16:28:12 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	textures_init(t_game *game)
{
	game->textures[0] = img_new(game->mlx, game->map.WE);
	if (!game->textures[0])
		printf("Error: Couldn't load texture WE\n");
	game->textures[1] = img_new(game->mlx, game->map.NO);
	if (!game->textures[1])
		printf("Error: Couldn't load texture NO\n");
	game->textures[2] = img_new(game->mlx, game->map.EA);
	if (!game->textures[2])
		printf("Error: Couldn't load texture EA\n");
	game->textures[3] = img_new(game->mlx, game->map.SO);
	if (!game->textures[3])
		printf("Error: Couldn't load texture SO\n");
	if (!game->textures[0] || !game->textures[1]
		|| !game->textures[2] || !game->textures[3])
		return (0);
	return (1);
}

static void	set_null(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->keys = NULL;
	game->textures[0] = NULL;
	game->textures[1] = NULL;
	game->textures[2] = NULL;
	game->textures[3] = NULL;
}

static void	game_free(t_game *game)
{
	img_free(game->img, game->mlx);
	free(game->img);
	img_free(game->textures[0], game->mlx);
	img_free(game->textures[1], game->mlx);
	img_free(game->textures[2], game->mlx);
	img_free(game->textures[3], game->mlx);
	free(game->textures[0]);
	free(game->textures[1]);
	free(game->textures[2]);
	free(game->textures[3]);
	ft_lstfree(game->keys, free);
	map_free(&game->map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	game_init(t_game *game, char *file)
{
	set_null(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (printf("Error: Couldn't init mlx\n"), game_free(game), 0);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		return (printf("Error: Couldn't create window\n"), game_free(game), 0);
	game->img = img_new2(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img)
		return (printf("Error: Couldn't create img\n"), game_free(game), 0);
	if (!read_map(&game->map, file))
		return (game_free(game), 0);
	if (!textures_init(game))
		return (game_free(game), 0);
	player_init(&game->player, game->map.x + 0.5,
			game->map.y + 0.5, game->map.rotation);
	return (1);
}
