/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_finder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:06:56 by *******           #+#    #+#             */
/*   Updated: 2025/01/13 20:08:08 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	ft_is_min(t_cursor *csr, t_travel *travel, int which)
{
	if (which == 1)
	{
		if (csr->src_top->cost + csr->src_top->rr <= travel->top_half + 1
			&& csr->src_top->cost + csr->src_top->rr <= csr->min_travel->cost
			+ csr->min_travel->rr + csr->min_travel->rrr)
		{
			csr->min_travel = csr->src_top;
			return (1);
		}
	}
	else
	{
		if (csr->src_bot->cost + csr->src_bot->rrr <= travel->bot_half
			&& csr->src_bot->cost + csr->src_bot->rrr <= csr->min_travel->cost
			+ csr->min_travel->rr + csr->min_travel->rrr)
		{
			csr->min_travel = csr->src_bot;
			return (1);
		}
	}
	return (0);
}

void	ft_update_moves_top(t_cursor *csr, t_price *price, t_travel *travel)
{
	if (price->dwn >= travel->top_half)
	{
		csr->src_top->rr = travel->top_half;
		price->dwn -= travel->top_half;
		csr->src_top->go_down = price->dwn;
	}
	else
	{
		csr->src_top->rr = price->dwn;
		price->dwn = 0;
		csr->src_top->go_down = 0;
	}
}

void	ft_update_moves_bot(t_cursor *csr, t_price *price, t_travel *travel)
{
	if (price->up >= travel->bot_half)
	{
		csr->src_bot->rrr = travel->bot_half;
		price->up -= travel->bot_half;
		csr->src_bot->go_up = price->up;
	}
	else
	{
		csr->src_bot->rrr = price->up;
		price->up = 0;
		csr->src_bot->go_up = 0;
	}
}

void	ft_add_weight_cost(t_cursor *csr, size_t src_size, int pivot, int which)
{
	if (which == 1)
	{
		if (csr->src_top->value < pivot)
			csr->src_top->cost += src_size / 10;
	}
	else
	{
		if (csr->src_bot->value < pivot)
			csr->src_bot->cost += src_size / 10;
	}
}

void	ft_reinit_list(t_list *list)
{
	while (1)
	{
		list->cost = 0;
		list->rr = 0;
		list->rrr = 0;
		list->go_down = 0;
		list->go_up = 0;
		list->top_half = 0;
		list->bot_half = 0;
		if (list->last_el)
			break ;
		list = list->next;
	}
}
