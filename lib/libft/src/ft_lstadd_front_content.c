/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:33:18 by orudek            #+#    #+#             */
/*   Updated: 2023/11/05 22:33:32 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_front_content(t_list **list, void *content)
{
	t_list	*new;

	if (!content || !list)
		return (0);
	new = ft_lstnew(content);
	if (!new)
		return (0);
	new->next = *list;
	*list = new;
	return (1);
}
