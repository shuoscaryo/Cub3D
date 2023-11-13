/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_keys.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:38:58 by orudek            #+#    #+#             */
/*   Updated: 2023/11/13 17:26:03 by orudek           ###   ########.fr       */
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

int		key_cmp(void *key1, void *key2);
int		keys_update(t_list **list, int keycode, int status);
int		keys_get_status(t_list *list, int keycode);

#endif