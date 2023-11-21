/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:27:36 by orudek            #+#    #+#             */
/*   Updated: 2023/11/21 11:57:25 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	textures_init(t_game *game)
{
	game->textures[0] = img_new(game->mlx, game->map.we);
	if (!game->textures[0])
		printf("Error.\nCouldn't load texture WE\n");
	game->textures[1] = img_new(game->mlx, game->map.no);
	if (!game->textures[1])
		printf("Error.\nCouldn't load texture NO\n");
	game->textures[2] = img_new(game->mlx, game->map.ea);
	if (!game->textures[2])
		printf("Error.\nCouldn't load texture EA\n");
	game->textures[3] = img_new(game->mlx, game->map.so);
	if (!game->textures[3])
		printf("Error.\nCouldn't load texture SO\n");
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
	game->map.map = NULL;
	game->map.no = NULL;
	game->map.so = NULL;
	game->map.we = NULL;
	game->map.ea = NULL;
}

void	game_init(t_game *game, char *file)
{
	set_null(game);
	if (!read_map(&game->map, file))
		exit (1);
	game->mlx = mlx_init();
	if (!game->mlx)
		(void)(printf("Error.\nCouldn't init mlx.\n"), exit(1));
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		(void)(printf("Error.\nCouldn't create window.\n"), exit(1));
	game->img = img_new2(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img)
		(void)(printf("Error.\nCouldn't create img.\n"), exit(1));
	if (!textures_init(game))
		exit (1);
	player_init(&game->player, game->map.x + 0.5,
		game->map.y + 0.5, game->map.rotation);
}
