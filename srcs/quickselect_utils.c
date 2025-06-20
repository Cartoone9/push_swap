/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickselect_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:36:33 by *******           #+#    #+#             */
/*   Updated: 2025/01/12 21:50:29 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	ft_init_array(t_array *ar, size_t len)
{
	size_t	i;

	ar->orig = malloc(sizeof(int) * len);
	if (!ar->orig)
		return (-1);
	i = -1;
	while (++i < len)
		ar->orig[i] = 0;
	ar->more = malloc(sizeof(int) * len);
	if (!ar->more)
		return (free(ar->orig), -1);
	i = -1;
	while (++i < len)
		ar->more[i] = 0;
	ar->less = malloc(sizeof(int) * len);
	if (!ar->less)
		return (free(ar->orig), free(ar->more), -1);
	i = -1;
	while (++i < len)
		ar->less[i] = 0;
	return (0);
}

void	ft_reinit_array(int *ar_member, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ar_member[i] = 0;
		i++;
	}
}

void	ft_cpyar_nreinit(t_array *ar, size_t len, size_t which)
{
	size_t	i;

	i = 0;
	if (which == 1)
	{
		while (i < len)
		{
			ar->orig[i] = ar->more[i];
			ar->more[i] = 0;
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			ar->orig[i] = ar->less[i];
			ar->less[i] = 0;
			i++;
		}
	}
}

void	ft_init_counter(t_counter *cnt)
{
	cnt->i = 0;
	cnt->j = 0;
	cnt->k = 0;
}

int	ft_find_smallest_two(t_array *ar)
{
	int	ret;

	ret = ar->orig[0];
	if (ar->orig[0] > ar->orig[1])
		ret = ar->orig[1];
	ft_free_array(ar);
	return (ret);
}
