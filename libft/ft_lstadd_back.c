/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:26:28 by *******           #+#    #+#             */
/*   Updated: 2025/01/05 00:24:09 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new_elem, size_t last_one)
{
	t_list	*last_elem;

	if (!new_elem)
		return ;
	if (*lst == NULL)
		*lst = new_elem;
	else
	{
		last_elem = (*lst)->prev;
		last_elem->next = new_elem;
		new_elem->prev = last_elem;
		(*lst)->prev = new_elem;
		new_elem->next = *lst;
		if (last_one)
			new_elem->last_el = 1;
	}
}
