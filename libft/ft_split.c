/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:03 by *******           #+#    #+#             */
/*   Updated: 2025/01/14 17:06:39 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

static int		choobidoo(char **strr, const char *s, char c);
static size_t	ft_strcnt(const char *str, char c);
static size_t	ft_nextch(const char *str, char c);
static void		ft_free_lib(char **strr, size_t n);

char	**ft_split(char const *s, char c)
{
	char	**strr;
	int		j;

	strr = malloc(sizeof(char *) * (ft_strcnt(s, c) + 1));
	if (!strr)
		return (NULL);
	j = choobidoo(strr, s, c);
	if (j == -1)
		return (NULL);
	strr[j] = NULL;
	return (strr);
}

static int	choobidoo(char **strr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			strr[j] = malloc(sizeof(char) * (ft_nextch(&s[i], c) + 1));
			if (!strr[j])
				return (ft_free_lib(strr, j), -1);
			k = 0;
			while (s[i] && s[i] != c)
				strr[j][k++] = s[i++];
			strr[j++][k] = '\0';
		}
	}
	return ((int)j);
}

static size_t	ft_strcnt(const char *str, char c)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != c)
			sum++;
		if (str[i] == c && str[i + 1] && str[i + 1] != c)
			sum++;
		i++;
	}
	return (sum);
}

static size_t	ft_nextch(const char *str, char c)
{
	size_t	sum;

	sum = 0;
	while (str[sum] && str[sum] != c)
		sum++;
	return (sum);
}

static void	ft_free_lib(char **strr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (strr[i])
			free(strr[i]);
		i++;
	}
	if (strr)
		free(strr);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*str = "      ";
	char		c;
	char		**strr;

	c = ' ';
	strr = ft_split(str, c);
	//	for (size_t i = 0; strr[i] != NULL; i++)
	//	{
	//		printf("'%s'\n", strr[i]);
	//	}
	(void)strr;
	return (0);
}
*/
