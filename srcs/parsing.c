/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:58:19 by *******           #+#    #+#             */
/*   Updated: 2025/01/19 13:42:02 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

t_list	*ft_convlist_ncheck(char **numbers)
{
	int			num_temp;
	t_shlist	list;
	t_shsizet	sizet;

	sizet.i = 0;
	ft_init_shlist(&list);
	while (numbers[sizet.i])
	{
		sizet.al_one = 0;
		num_temp = ft_atoi_sp(numbers[sizet.i], &sizet.al_one);
		if (num_temp == -1 && (ft_strlen(numbers[sizet.i]) >= 10
				|| sizet.al_one == 0))
			return (ft_free_list(list.ret, sizet.i), NULL);
		list.tmp = ft_lstnew_int(num_temp);
		if (!list.tmp)
			return (ft_free_list(list.ret, sizet.i), NULL);
		if (!numbers[sizet.i + 1])
			ft_lstadd_back(&list.ret, list.tmp, 1);
		else
			ft_lstadd_back(&list.ret, list.tmp, 0);
		sizet.i++;
	}
	if (!ft_check_doubles(list.ret))
		return (ft_free_list(list.ret, 0), NULL);
	return (list.ret);
}

void	ft_init_shlist(t_shlist *list)
{
	list->tmp = NULL;
	list->ret = NULL;
}

int	ft_check_doubles(t_list *list)
{
	int		num_temp;
	t_list	*cursor;

	if (!list)
		return (0);
	while (!list->last_el)
	{
		num_temp = list->value;
		cursor = list->next;
		while (!cursor->prev->last_el)
		{
			if (num_temp == cursor->value)
				return (0);
			cursor = cursor->next;
		}
		list = list->next;
	}
	return (1);
}

char	**ft_split_ncheck(char **av)
{
	char	**numbers;
	char	*buffer;
	char	*old_buffer;
	size_t	buffer_size;
	size_t	i;

	buffer_size = ft_strlen(av[1]) + 1;
	buffer = malloc(sizeof(char) * buffer_size);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, av[1], buffer_size);
	i = 1;
	while (av[++i])
	{
		old_buffer = buffer;
		buffer = ft_strjoin_sp(buffer, av[i]);
		ft_free_str(old_buffer);
		if (!buffer)
			return (NULL);
	}
	numbers = ft_split(buffer, ' ');
	if (!numbers || !ft_check_numbers(numbers))
		return (ft_free_strr(numbers), ft_free_str(buffer), NULL);
	return (ft_free_str(buffer), numbers);
}

int	ft_check_numbers(char **numbers)
{
	size_t	at_least_one;
	size_t	j;
	size_t	i;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		at_least_one = 0;
		while (numbers[i][j] == '-' || numbers[i][j] == '+')
			j++;
		while (numbers[i][j])
		{
			if (numbers[i][j] < '0' || numbers[i][j] > '9')
				return (0);
			if (at_least_one == 0 && numbers[i][j] >= '0'
				&& numbers[i][j] <= '9')
				at_least_one = 1;
			j++;
		}
		if (at_least_one == 0)
			return (0);
		i++;
	}
	return (1);
}
