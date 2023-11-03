/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_keys.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:38:58 by orudek            #+#    #+#             */
/*   Updated: 2023/11/03 15:15:50 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HANDLE_H
# define KEY_HANDLE_H

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
	void	(*update)(struct s_keys *this, int keycode, int status);
	void	(*free)(struct void *this);
	int		(*get_status)(struct s_keys *this, int keycode);
}	t_keys;

void	keys_init(t_keys *this);
void	keys_update(t_keys *this, int keycode, int status);
void	keys_free(void *this);
int		keys_get_status(t_keys *this, int keycode);

#endif