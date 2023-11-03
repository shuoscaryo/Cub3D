/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:53:08 by orudek            #+#    #+#             */
/*   Updated: 2023/11/03 14:56:09 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfind(t_list *lst, void *data, int (*cmp)(void *, void *))
{
	while (lst)
	{
		if (cmp(lst->content, data) == 0)
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
