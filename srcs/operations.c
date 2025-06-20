/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:39:46 by *******           #+#    #+#             */
/*   Updated: 2025/01/14 19:51:33 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	swap(t_list **hdr, char c)
{
	t_list	*temp;

	if (!hdr || !(*hdr) || (*hdr)->next == *hdr)
		return ;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
	if ((*hdr)->next->last_el)
	{
		(*hdr)->next->last_el = 0;
		(*hdr)->last_el = 1;
	}
	temp = (*hdr)->next->next;
	(*hdr)->prev->next = (*hdr)->next;
	(*hdr)->next->prev = (*hdr)->prev;
	(*hdr)->next->next->prev = *hdr;
	(*hdr)->next->next = *hdr;
	(*hdr)->prev = (*hdr)->next;
	(*hdr)->next = temp;
	*hdr = (*hdr)->prev;
}

void	push(t_list **hdr_src, t_list **hdr_dest, char c)
{
	t_list	*temp;

	if (!hdr_src || !(*hdr_src))
		return ;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
	if ((*hdr_src)->last_el)
	{
		(*hdr_src)->prev->last_el = 1;
		(*hdr_src)->last_el = 0;
	}
	temp = *hdr_src;
	if ((*hdr_src)->next == (*hdr_src))
		(*hdr_src) = NULL;
	else
	{
		(*hdr_src)->prev->next = (*hdr_src)->next;
		(*hdr_src)->next->prev = (*hdr_src)->prev;
		*hdr_src = (*hdr_src)->next;
	}
	push_suite(hdr_dest, temp);
}

void	push_suite(t_list **hdr_dest, t_list *temp)
{
	if (!(*hdr_dest))
	{
		temp->next = temp;
		temp->prev = temp;
		temp->last_el = 1;
		*hdr_dest = temp;
	}
	else
	{
		temp->next = *hdr_dest;
		temp->prev = (*hdr_dest)->prev;
		(*hdr_dest)->prev->next = temp;
		(*hdr_dest)->prev = temp;
		*hdr_dest = temp;
	}
}
