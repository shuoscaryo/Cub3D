/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_get_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:13:55 by orudek            #+#    #+#             */
/*   Updated: 2023/11/13 17:24:05 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_keys.h"

int	keys_get_status(t_list *list, int keycode)
{
	t_key	*key_ref;
	t_key	aux_key;

	aux_key.keycode = keycode;
	key_ref = ft_lstfind(list, &aux_key, key_cmp);
	if (!key_ref)
		return (0);
	return (key_ref->status);
}
