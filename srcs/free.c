/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:01:42 by *******           #+#    #+#             */
/*   Updated: 2025/01/13 22:06:07 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	ft_free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	ft_free_strr(char **strr)
{
	size_t	i;

	i = 0;
	while (strr[i])
	{
		free(strr[i]);
		strr[i] = NULL;
		i++;
	}
	if (strr)
	{
		free(strr);
		strr = NULL;
	}
}

void	ft_free_array(t_array *ar)
{
	if (ar->orig)
	{
		free(ar->orig);
		ar->orig = NULL;
	}
	if (ar->less)
	{
		free(ar->less);
		ar->less = NULL;
	}
	if (ar->more)
	{
		free(ar->more);
		ar->more = NULL;
	}
}

void	ft_free_list(t_list *list, size_t num)
{
	t_list	*temp;
	size_t	i;

	if (!list)
		return ;
	i = 0;
	while (i < num)
	{
		temp = list->next;
		free(list);
		list = temp;
		i++;
	}
	if (i)
		return ;
	while (!(list->last_el) && !(list->next == list))
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	free(list);
	list = NULL;
}
