/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_keys.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:38:58 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 19:25:24 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_KEYS_H
# define T_KEYS_H

# include "libft.h"

typedef struct s_key
{
	int		keycode;
	int		status;
}	t_key;

int	key_cmp(void *key1, void *key2);

typedef struct s_keys
{
	t_list	*keys;
	int		(*update)(struct s_keys *this, int keycode, int status);
	void	(*free)(void *this);
	int		(*get_status)(struct s_keys *this, int keycode);
}	t_keys;

void	keys_init(t_keys *this);
int		keys_update(t_keys *this, int keycode, int status);
void	keys_free(void *this);
int		keys_get_status(t_keys *this, int keycode);

#endif