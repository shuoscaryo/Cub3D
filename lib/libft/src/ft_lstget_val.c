/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:41:39 by orudek            #+#    #+#             */
/*   Updated: 2023/08/07 19:06:08 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstget_val(t_list *list, int index)
{
	int		i;

	if (index >= ft_lstsize(list) || index < 0)
		return (NULL);
	i = -1;
	while (++i < index)
		list = list->next;
	return (list->content);
}
