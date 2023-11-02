/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:07:05 by orudek            #+#    #+#             */
/*   Updated: 2023/09/11 16:00:49 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **list, int index, void (*del)(void *))
{
	t_list	*previous_lst;
	t_list	*aux;

	if (!list || !*list)
		return ;
	aux = *list;
	if (index <= 0)
	{
		*list = (*list)->next;
		ft_lstdelone(aux, del);
		return ;
	}
	while (index-- > 0 && aux->next)
	{
		previous_lst = aux;
		aux = aux->next;
	}
	previous_lst->next = aux->next;
	ft_lstdelone(aux, del);
}
