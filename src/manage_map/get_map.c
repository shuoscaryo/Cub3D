/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:29:49 by iortega-          #+#    #+#             */
/*   Updated: 2023/11/13 17:04:38 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	have_player(int player, char *buff, t_list *list)
{
	if (player == 0)
	{
		printf("Error.\nMap is invalid.\n");
		free(buff);
		return (ft_lstfree(list, free), 0);
	}
	return (1);
}

int	get_map_content(t_map *map, char **buff, t_list **list)
{
	int	player;

	player = 0;
	while (*buff != NULL)
	{
		if (*buff[0] == '\n')
		{
			free(*buff);
			*buff = get_next_line(map->fd);
			break ;
		}
		delete_n(*buff);
		if (parse_line(*buff, &player))
			ft_lstadd_back_content(list, *buff);
		else
		{
			printf("Error.\nMap is invalid.\n");
			free(*buff);
			return (ft_lstfree(*list, free), 0);
		}
		*buff = get_next_line(map->fd);
	}
	if (!have_player(player, *buff, *list))
		return (0);
	return (1);
}

int	save_map(t_map *map, t_list **list)
{
	int		i;
	t_list	*aux;

	map->map = malloc(sizeof(char *) * (ft_lstsize(*list) + 1));
	if (!map->map)
	{
		ft_lstfree(*list, free);
		return (printf("Error.\nMalloc error (map).\n"), 0);
	}
	i = 0;
	while (*list)
	{
		map->map[i] = (*list)->content;
		aux = *list;
		*list = (*list)->next;
		free(aux);
		i++;
	}
	map->map[i] = NULL;
	close(map->fd);
	return (1);
}

int	after_map(t_map *map, char **buff, t_list **list)
{
	while (*buff != NULL)
	{
		if (*buff[0] == '\n')
		{
			free(*buff);
			*buff = get_next_line(map->fd);
			continue ;
		}
		else
		{
			printf("Error.\nMap is invalid aa a.\n");
			free(*buff);
			return (ft_lstfree(*list, free), 0);
		}
	}
	return (1);
}

int	get_map(t_map *map)
{
	char	*buff;
	t_list	*list;

	list = NULL;
	buff = get_next_line(map->fd);
	while (buff != NULL && buff[0] == '\n')
	{
		free(buff);
		buff = get_next_line(map->fd);
	}
	if (!get_map_content(map, &buff, &list))
		return (0);
	if (!after_map(map, &buff, &list))
		return (0);
	if (!save_map(map, &list))
		return (0);
	set_player(map);
	return (1);
}
