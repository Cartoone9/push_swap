/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_finder_utils_deux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:08:18 by *******           #+#    #+#             */
/*   Updated: 2025/01/13 20:43:03 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	ft_check_min_travel_top(t_cursor *csr)
{
	if (!csr->min_travel || csr->src_top->cost
		+ csr->src_top->rr < csr->min_travel->cost + csr->min_travel->rr
		+ csr->min_travel->rrr)
		csr->min_travel = csr->src_top;
}

void	ft_check_min_travel_bot(t_cursor *csr)
{
	if (!csr->min_travel || csr->src_bot->cost
		+ csr->src_bot->rrr < csr->min_travel->cost + csr->min_travel->rr
		+ csr->min_travel->rrr)
		csr->min_travel = csr->src_bot;
}

void	ft_update_cost_top(t_cursor *csr, t_price *price, t_travel *travel)
{
	if (price->dwn < price->up)
	{
		csr->src_top->cost = price->dwn + travel->top_half;
		csr->src_top->go_up = 0;
	}
	else
	{
		csr->src_top->cost = price->up + travel->top_half;
		csr->src_top->go_down = 0;
		csr->src_top->go_up = price->up;
		csr->src_top->rr = 0;
	}
}

void	ft_update_cost_bot(t_cursor *csr, t_price *price, t_travel *travel)
{
	if (price->up < price->dwn)
	{
		csr->src_bot->cost = price->up + travel->bot_half;
		csr->src_bot->go_down = 0;
	}
	else
	{
		csr->src_bot->cost = price->dwn + travel->bot_half;
		csr->src_bot->go_up = 0;
		csr->src_bot->go_down = price->dwn;
		csr->src_bot->rrr = 0;
	}
}
