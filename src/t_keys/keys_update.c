/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:51:17 by orudek            #+#    #+#             */
/*   Updated: 2023/11/03 15:18:17 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_keys.h"

int	keys_update(t_keys *this, int keycode, int status)
{
	t_key	aux_key;
	t_key	*key_ref;

	aux_key.keycode = keycode;
	key_ref = (t_key *)ft_lstfind(this->keys, &aux_key, key_cmp);
	if (!key_ref)
	{
		key_ref = malloc(sizeof(t_key));
		if (!key_ref)
			return (0);
		key_ref->keycode = keycode;
		key_ref->status = status;
		return (ft_lstadd_back_content(&this->keys, key_ref));
	}
	key_ref->status = status;
	return (1);
}
