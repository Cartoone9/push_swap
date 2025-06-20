/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_findeer_utils_trois.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:09:41 by *******           #+#    #+#             */
/*   Updated: 2025/01/13 20:09:50 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	ft_calc_down_pr(t_list *src, t_list *dst)
{
	int	price_dwn;

	price_dwn = 0;
	while ((src->value > dst->value) || (src->value < dst->value
			&& src->value < dst->prev->value && dst->value > dst->prev->value))
	{
		if (src->value > dst->value && src->value > dst->prev->value
			&& dst->value < dst->prev->value)
			break ;
		price_dwn++;
		dst = dst->next;
	}
	return (price_dwn);
}

int	ft_calc_up_pr(t_list *src, t_list *dst)
{
	int	price_up;

	price_up = 0;
	while ((src->value < dst->value) || (src->value > dst->value
			&& src->value > dst->next->value && dst->value < dst->next->value))
	{
		if (src->value < dst->value && src->value < dst->next->value
			&& dst->value > dst->next->value)
			break ;
		price_up++;
		dst = dst->prev;
	}
	return (price_up);
}

void	ft_init_price_csr_top(t_price *price, t_cursor *csr, t_list *lst_dest)
{
	price->dwn = 0;
	price->up = 0;
	csr->src_top->top_half = 1;
	csr->dst_top = lst_dest;
}

void	ft_init_price_csr_bot(t_price *price, t_cursor *csr, t_list *lst_dest)
{
	price->dwn = 0;
	price->up = 0;
	csr->src_bot->bot_half = 1;
	csr->dst_bot = lst_dest;
}
