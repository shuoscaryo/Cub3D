/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:14:02 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/05 18:34:59 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int update(t_game *game)
{
	game->player.move(&game->player, 0.001);
	return (0);
}

void print_img(void *img) //XXX
{
	t_img *i = (t_img *)img;

	printf("IMAGE INFO:\n");
	printf("\tfilename: %s\n", i->filename);
	printf("\timg: %p\n", i->img);
	printf("\taddr: %p\n", i->addr);
	printf("\tsize_line: %d\n", i->size_line);
	printf("\tbits_per_pixel: %d\n", i->bits_per_pixel);
	printf("\tendian: %d\n", i->endian);
	printf("\theight: %d\n", i->height);
	printf("\twidth: %d\n", i->width);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!check_params(argc, argv, &game))
		return (0);
	if (!read_map(&game.map, argv[1]))
		return (free_map(&game.map), 0);
	//game_init(&game);
	keys_init(&game.keys);
	player_init(&game.player, 0, 0, 0);
	printf("adding textures...\n");
	textures_init(&game.textures);
	printf("adding NO\n");
	game.textures.add_texture(&game.textures, game.map.NO, game.mlx);
	printf("adding SO\n");
	game.textures.add_texture(&game.textures, game.map.SO, game.mlx);
	printf("adding EA\n");
	game.textures.add_texture(&game.textures, game.map.EA, game.mlx);
	printf("adding WE\n");
	game.textures.add_texture(&game.textures, game.map.WE, game.mlx);
	
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	//mlx_hook(game.win, ON_DESTROY, NO_EVENT_MASK, ft_game_exit, &game);
	mlx_hook(game.win, ON_KEYDOWN, KEY_PRESS_MASK, on_key_down, &game);
	mlx_hook(game.win, ON_KEYUP, KEY_RELEASE_MASK, on_key_up, &game);
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
