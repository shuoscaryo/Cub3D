/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:44:43 by orudek            #+#    #+#             */
/*   Updated: 2023/09/11 15:03:21 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget_index(t_list *list, int index)
{
	if (index >= ft_lstsize(list) || index < 0)
		return (NULL);
	while (index-- > 0)
		list = list->next;
	return (list);
}
