/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:51:13 by *******           #+#    #+#             */
/*   Updated: 2025/01/20 16:11:58 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/get_next_line.h"
#include "../hdrs/push_swap.h"

int	ft_gnl_loop(t_list **list_a, t_list **list_b)
{
	int		val;
	char	*ope;

	ope = get_next_line(0);
	if (!ope && ft_is_sorted(*list_a))
		return (0);
	if (!ope)
		return (1);
	while (ope)
	{
		val = ft_comp(ope, list_a, list_b);
		if (val == 2)
			return (free(ope), 2);
		else if (!val)
			return (free(ope), 0);
		free(ope);
		ope = get_next_line(0);
	}
	return (1);
}

int	ft_comp(char *str, t_list **list_a, t_list **list_b)
{
	if (!ft_strncmp("sa\n", str, 3))
		swap_ch(list_a);
	else if (!ft_strncmp("sb\n", str, 3))
		swap_ch(list_b);
	else if (!ft_strncmp("ss\n", str, 3))
	{
		swap_ch(list_a);
		swap_ch(list_b);
	}
	else if (!ft_strncmp("pa\n", str, 3))
		push_ch(list_b, list_a);
	else if (!ft_strncmp("pb\n", str, 3))
		push_ch(list_a, list_b);
	else if (!ft_strncmp("ra\n", str, 3))
		rotate_ch(list_a);
	else if (!ft_strncmp("rb\n", str, 3))
		rotate_ch(list_b);
	else if (!ft_strncmp("rr\n", str, 3))
	{
		rotate_ch(list_a);
		rotate_ch(list_b);
	}
	else
		return (ft_comp_suite(str, list_a, list_b));
	return (1);
}

int	ft_comp_suite(char *str, t_list **list_a, t_list **list_b)
{
	if (!ft_strncmp("rra\n", str, 4))
		reverse_rotate_ch(list_a);
	else if (!ft_strncmp("rrb\n", str, 4))
		reverse_rotate_ch(list_b);
	else if (!ft_strncmp("rrr\n", str, 4))
	{
		reverse_rotate_ch(list_a);
		reverse_rotate_ch(list_b);
	}
	else if (!ft_strncmp("\n", str, 1))
		return (0);
	else
		return (2);
	return (1);
}

size_t	ft_numbers_size(char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i])
		i++;
	return (i);
}
