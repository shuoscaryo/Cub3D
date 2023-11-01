/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:31:37 by orudek            #+#    #+#             */
/*   Updated: 2023/08/07 17:20:32 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_lstadd_back_content(t_list **lst, void *content)
{
	t_list	*new_obj;

	if (!content)
		return (0);
	new_obj = ft_lstnew(content);
	if (!new_obj)
		return (0);
	ft_lstadd_back(lst, new_obj);
	return (1);
}
