/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:36:35 by *******           #+#    #+#             */
/*   Updated: 2025/01/20 16:09:43 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/get_next_line.h"
#include "../hdrs/push_swap.h"

int	main(int ac, char **av)
{
	char	**numbers;
	t_list	*list_a;
	t_list	*list_b;

	if (ac >= 2)
	{
		list_b = NULL;
		numbers = ft_split_ncheck(av);
		if (!numbers)
			return (write(2, "Error\n", 6), 1);
		if (ft_numbers_size(numbers) <= 1)
			return (ft_free_strr(numbers), 0);
		list_a = ft_convlist_ncheck(numbers);
		ft_free_strr(numbers);
		if (!list_a)
			return (write(2, "Error\n", 6), 1);
		ft_checker(list_a, list_b);
	}
	return (0);
}

void	ft_checker(t_list *list_a, t_list *list_b)
{
	int	val;

	val = ft_gnl_loop(&list_a, &list_b);
	if (val == 2)
	{
		write(2, "Error\n", 6);
		ft_free_list(list_a, 0);
		ft_free_list(list_b, 0);
		return ;
	}
	if (list_b)
	{
		write(1, "KO\n", 3);
		ft_free_list(list_b, 0);
	}
	else if (list_a)
	{
		if (ft_is_sorted(list_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free_list(list_a, 0);
	}
}
