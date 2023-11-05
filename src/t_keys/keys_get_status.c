/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_get_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:13:55 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 15:30:54 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_keys.h"

int	keys_get_status(t_keys *this, int keycode)
{
	t_key	*key_ref;
	t_key	aux_key;

	aux_key.keycode = keycode;
	key_ref = ft_lstfind(this->keys, &keycode, key_cmp);
	if (!key_ref)
		return (0);
	return (key_ref->status);
}
