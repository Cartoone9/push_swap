/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickselect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:36:33 by *******           #+#    #+#             */
/*   Updated: 2025/01/12 21:48:19 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

long long	ft_quickselect(t_list *list)
{
	t_array	ar;
	size_t	list_len;
	size_t	array_len;
	int		ret;

	list_len = ft_lstsize(list);
	if (!list || !list_len)
		return (INT_ERROR);
	if (ft_init_array(&ar, list_len) == -1)
		return (INT_ERROR);
	ret = 0;
	array_len = 0;
	while (1)
	{
		ar.orig[array_len] = list->value;
		array_len++;
		if (list->last_el)
			break ;
		list = list->next;
	}
	ret = ft_quickselect_suite(&ar, array_len);
	return (ret);
}

int	ft_quickselect_suite(t_array *ar, size_t array_len)
{
	t_counter	cnt;
	size_t		median_index;
	int			pivot;

	median_index = (array_len - 1) / 2;
	ft_init_counter(&cnt);
	while (1)
	{
		if (array_len == 2)
			return (ft_find_smallest_two(ar));
		pivot = ft_median_ofthr(ar->orig, array_len);
		ft_partition_array(ar, array_len, pivot, &cnt);
		if ((cnt.k - 1) == median_index)
			return (ft_free_array(ar), pivot);
		if ((cnt.k - 1) > median_index)
			array_len = ft_handle_more(ar, &cnt);
		else
		{
			array_len = ft_handle_less(ar, &cnt);
			median_index -= cnt.k;
		}
		ft_init_counter(&cnt);
	}
}

size_t	ft_handle_more(t_array *ar, t_counter *cnt)
{
	ft_reinit_array(ar->more, cnt->j);
	ft_cpyar_nreinit(ar, cnt->k, 0);
	return (cnt->k);
}

size_t	ft_handle_less(t_array *ar, t_counter *cnt)
{
	ft_reinit_array(ar->less, cnt->k);
	ft_cpyar_nreinit(ar, cnt->j, 1);
	return (cnt->j);
}

void	ft_partition_array(t_array *ar, size_t array_len, int pivot,
		t_counter *cnt)
{
	while (cnt->i < array_len)
	{
		if (ar->orig[cnt->i] > pivot)
		{
			ar->more[cnt->j] = ar->orig[cnt->i];
			ar->orig[cnt->i] = 0;
			cnt->j++;
			cnt->i++;
		}
		else
		{
			ar->less[cnt->k] = ar->orig[cnt->i];
			ar->orig[cnt->i] = 0;
			cnt->k++;
			cnt->i++;
		}
	}
}
