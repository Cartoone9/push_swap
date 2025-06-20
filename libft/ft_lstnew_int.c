/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:15:52 by *******           #+#    #+#             */
/*   Updated: 2025/01/10 17:11:54 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

t_list	*ft_lstnew_int(int value)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->value = value;
	ret->last_el = 0;
	ret->rr = 0;
	ret->rrr = 0;
	ret->cost = 0;
	ret->go_down = 0;
	ret->go_up = 0;
	ret->top_half = 0;
	ret->bot_half = 0;
	ret->next = ret;
	ret->prev = ret;
	return (ret);
}
