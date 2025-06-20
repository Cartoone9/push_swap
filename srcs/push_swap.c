/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:51:59 by *******           #+#    #+#             */
/*   Updated: 2025/01/13 22:07:03 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	main(int ac, char **av)
{
	char	**numbers;
	t_list	*list_a;
	size_t	la_size;

	if (ac >= 2)
	{
		numbers = ft_split_ncheck(av);
		if (!numbers)
			return (write(2, "Error\n", 6), 1);
		if (ft_numbers_size(numbers) <= 1)
			return (ft_free_strr(numbers), 0);
		list_a = ft_convlist_ncheck(numbers);
		ft_free_strr(numbers);
		if (!list_a)
			return (write(2, "Error\n", 6), 1);
		la_size = ft_lstsize(list_a);
		if (la_size <= 3)
			return (ft_fewval(&list_a, la_size, 'a'), ft_free_list(list_a, 0),
				0);
		else if (ft_quicksort(&list_a) == -1)
			return (ft_free_list(list_a, 0), write(2, "Error\n", 6), 1);
		ft_free_list(list_a, 0);
	}
	return (0);
}

// If 2 members not sorted, just swap
//
// Else if 3 members not sorted :
//
// 1 move :
// (6, 2, 9) -> bigger element last, swap
// (6, 9, 2) -> smaller element last, reverse_rotate
// (9, 2, 6) -> bigger element first rest ordered, rotate
// 2 moves :
// (9, 6, 2) -> bigger element first not ordered, rotate & swap
// (2, 9, 6) -> smaller element first not ordered, reverse_rotate & swap
void	ft_fewval(t_list **list, size_t mem, char c)
{
	if (!ft_is_sorted(*list))
	{
		if (mem == 2)
			swap(list, c);
		else
			ft_fewval_suite(list, c);
	}
}

void	ft_fewval_suite(t_list **list, char c)
{
	if ((*list)->value > (*list)->next->value
		&& (*list)->value < (*list)->next->next->value)
		swap(list, c);
	else if ((*list)->value < (*list)->next->value
		&& (*list)->value > (*list)->next->next->value)
		reverse_rotate(list, c);
	else if ((*list)->value > (*list)->next->value
		&& (*list)->value > (*list)->next->next->value)
	{
		rotate(list, c);
		if ((*list)->value > (*list)->next->value)
			swap(list, c);
	}
	else if ((*list)->value < (*list)->next->value
		&& (*list)->value < (*list)->next->next->value)
	{
		reverse_rotate(list, c);
		swap(list, c);
	}
}

size_t	ft_numbers_size(char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i])
		i++;
	return (i);
}
