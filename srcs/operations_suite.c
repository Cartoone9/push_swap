/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_suite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/01/14 19:51:27 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	double_rotate(t_list **hdr_A, t_list **hdr_B)
{
	write(1, "rr\n", 3);
	rotate(hdr_A, 'r');
	rotate(hdr_B, 'r');
}

void	rotate(t_list **hdr, char c)
{
	if (!hdr || !(*hdr) || (*hdr)->next == *hdr)
		return ;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
	(*hdr)->prev->last_el = 0;
	(*hdr)->last_el = 1;
	*hdr = (*hdr)->next;
}

void	double_reverse_rotate(t_list **hdr_A, t_list **hdr_B)
{
	write(1, "rrr\n", 4);
	reverse_rotate(hdr_A, 'r');
	reverse_rotate(hdr_B, 'r');
}

void	reverse_rotate(t_list **hdr, char c)
{
	if (!hdr || !(*hdr) || (*hdr)->next == *hdr)
		return ;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
	(*hdr)->prev->last_el = 0;
	*hdr = (*hdr)->prev;
	(*hdr)->prev->last_el = 1;
}
