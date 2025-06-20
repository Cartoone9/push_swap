/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:57:25 by *******           #+#    #+#             */
/*   Updated: 2025/01/13 21:27:30 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	ft_quicksort(t_list **list_a)
{
	long long	pivot;
	t_list		*list_b;

	if (ft_is_sorted(*list_a))
		return (0);
	list_b = NULL;
	pivot = ft_quickselect(*list_a);
	if (pivot > INT_MAX)
		return (-1);
	ft_split_list(list_a, &list_b, pivot);
	ft_fewval(list_a, 3, 'a');
	ft_merge_lists(&list_b, list_a, pivot);
	ft_order_list(list_a);
	return (0);
}

void	ft_split_list(t_list **list_a, t_list **list_b, long long pivot)
{
	int	lista_size;

	lista_size = ft_lstsize(*list_a);
	while (*list_a && lista_size > 3)
	{
		if ((*list_a)->value == pivot)
			rotate(list_a, 'a');
		else
		{
			push(list_a, list_b, 'b');
			if ((*list_b)->value < pivot)
				rotate(list_b, 'b');
			lista_size--;
		}
	}
}

void	ft_merge_lists(t_list **list_b, t_list **list_a, long long pivot)
{
	t_list	*min_travel;

	while (*list_b)
	{
		min_travel = ft_find_cost(*list_b, *list_a, pivot);
		ft_sort_min(list_b, list_a, min_travel);
	}
}

void	ft_order_list(t_list **list)
{
	size_t	dir;

	dir = ft_find_way(*list);
	if (dir)
	{
		while ((*list)->value < (*list)->next->value)
			rotate(list, 'a');
		if ((*list)->value > (*list)->next->value)
			rotate(list, 'a');
	}
	else
	{
		while ((*list)->value > (*list)->prev->value)
			reverse_rotate(list, 'a');
	}
}
