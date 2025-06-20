/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickselect_utils_leretour.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:49:31 by *******           #+#    #+#             */
/*   Updated: 2025/01/13 20:43:54 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	ft_median_ofthr(int *ar_member, size_t ar_len)
{
	int	value[3];

	value[0] = ar_member[0];
	value[1] = ar_member[(ar_len - 1) / 2];
	value[2] = ar_member[ar_len - 1];
	ft_swap_values(value);
	return (value[1]);
}

void	ft_swap_values(int *value)
{
	int	temp;

	if (value[0] > value[1])
	{
		temp = value[0];
		value[0] = value[1];
		value[1] = temp;
	}
	if (value[1] > value[2])
	{
		temp = value[1];
		value[1] = value[2];
		value[2] = temp;
	}
	if (value[0] > value[1])
	{
		temp = value[0];
		value[0] = value[1];
		value[1] = temp;
	}
}
