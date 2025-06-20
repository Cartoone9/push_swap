/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:57:25 by *******           #+#    #+#             */
/*   Updated: 2025/01/13 20:45:36 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

t_list	*ft_find_cost(t_list *lst_src, t_list *lst_dest, int pivot)
{
	t_cursor	csr;
	t_travel	travel;
	t_price		price;
	size_t		src_size;

	ft_init_all(&src_size, &travel, &csr, lst_src);
	while (travel.top_half <= (src_size - 1) / 2)
	{
		ft_top_part(&csr, &price, &travel, lst_dest);
		ft_add_weight_cost(&csr, src_size, pivot, 1);
		ft_check_min_travel_top(&csr);
		if (ft_is_min(&csr, &travel, 1) || src_size == 1)
			break ;
		ft_endstep(&travel, &csr, 1);
		if (csr.src_bot->bot_half || csr.src_bot->top_half)
			return (csr.min_travel);
		ft_bot_part(&csr, &price, &travel, lst_dest);
		ft_add_weight_cost(&csr, src_size, pivot, 2);
		ft_check_min_travel_bot(&csr);
		if (ft_is_min(&csr, &travel, 2))
			break ;
		ft_endstep(&travel, &csr, 2);
	}
	return (csr.min_travel);
}

void	ft_endstep(t_travel *travel, t_cursor *csr, int which)
{
	if (which == 1)
	{
		travel->top_half++;
		csr->src_top = csr->src_top->next;
	}
	else
	{
		travel->bot_half++;
		csr->src_bot = csr->src_bot->prev;
	}
}

void	ft_init_all(size_t *src_size, t_travel *travel, t_cursor *csr,
		t_list *lst_src)
{
	*src_size = ft_lstsize(lst_src);
	travel->top_half = 0;
	travel->bot_half = 1;
	csr->min_travel = NULL;
	ft_reinit_list(lst_src);
	csr->src_top = lst_src;
	csr->src_bot = lst_src->prev;
}

void	ft_top_part(t_cursor *csr, t_price *price, t_travel *travel,
		t_list *lst_dest)
{
	ft_init_price_csr_top(price, csr, lst_dest);
	price->dwn = ft_calc_down_pr(csr->src_top, csr->dst_top);
	ft_update_moves_top(csr, price, travel);
	csr->dst_top = lst_dest->prev;
	price->up = ft_calc_up_pr(csr->src_top, csr->dst_top);
	ft_update_cost_top(csr, price, travel);
}

void	ft_bot_part(t_cursor *csr, t_price *price, t_travel *travel,
		t_list *lst_dest)
{
	ft_init_price_csr_bot(price, csr, lst_dest);
	price->dwn = ft_calc_down_pr(csr->src_bot, csr->dst_bot);
	csr->dst_bot = lst_dest->prev;
	price->up = ft_calc_up_pr(csr->src_bot, csr->dst_bot);
	ft_update_moves_bot(csr, price, travel);
	ft_update_cost_bot(csr, price, travel);
}
