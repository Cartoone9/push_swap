/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:41:59 by *******           #+#    #+#             */
/*   Updated: 2025/01/13 21:27:17 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

size_t	ft_find_way(t_list *hdr)
{
	t_list	*cursor;
	size_t	top;
	size_t	bot;

	top = 0;
	bot = 0;
	cursor = hdr;
	while (cursor->value < cursor->next->value)
	{
		bot++;
		cursor = cursor->next;
	}
	cursor = hdr;
	while (cursor->value > cursor->prev->value)
	{
		top++;
		cursor = cursor->prev;
	}
	if (bot < top)
		return (1);
	return (0);
}

void	ft_sort_min(t_list **lst_src, t_list **lst_dst, t_list *min_travel)
{
	size_t	i;

	if (min_travel->rr || min_travel->rrr)
	{
		i = 0;
		while (i < min_travel->rr)
		{
			double_rotate(lst_src, lst_dst);
			i++;
		}
		while (i < min_travel->rrr)
		{
			double_reverse_rotate(lst_src, lst_dst);
			i++;
		}
	}
	while ((*lst_src)->value != min_travel->value)
	{
		if (min_travel->top_half)
			rotate(lst_src, 'b');
		if (min_travel->bot_half)
			reverse_rotate(lst_src, 'b');
	}
	ft_sort_min_suite(lst_src, lst_dst);
}

void	ft_sort_min_suite(t_list **lst_src, t_list **lst_dst)
{
	size_t	i;

	i = 0;
	if ((*lst_src)->go_down)
	{
		while (i < (*lst_src)->go_down)
		{
			rotate(lst_dst, 'a');
			i++;
		}
	}
	else
	{
		while (i < (*lst_src)->go_up)
		{
			reverse_rotate(lst_dst, 'a');
			i++;
		}
	}
	push(lst_src, lst_dst, 'a');
}

size_t	ft_is_sorted(t_list *list)
{
	if (!list)
		return (1);
	while (!list->last_el)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}
