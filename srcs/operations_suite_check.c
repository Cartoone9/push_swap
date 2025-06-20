/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_suite_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/01/14 19:54:14 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	rotate_ch(t_list **hdr)
{
	if (!hdr || !(*hdr) || (*hdr)->next == *hdr)
		return ;
	(*hdr)->prev->last_el = 0;
	(*hdr)->last_el = 1;
	*hdr = (*hdr)->next;
}

void	reverse_rotate_ch(t_list **hdr)
{
	if (!hdr || !(*hdr) || (*hdr)->next == *hdr)
		return ;
	(*hdr)->prev->last_el = 0;
	*hdr = (*hdr)->prev;
	(*hdr)->prev->last_el = 1;
}
