/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:04 by *******           #+#    #+#             */
/*   Updated: 2024/12/28 23:19:02 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (n - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	int		n;
	char	*str;
	char	str2[100];

	n = 8;
	str = "Ceci est un test.";
	printf("my version : %zu, original : %zu\n",
		ft_strlcpy(str2, str, n), strlcpy(str2, str, n));
	ft_strlcpy(str2, str, n);
	printf("MY_FT : '%s'\n", str2);
	strlcpy(str2, str, n);
	printf("FT_ORIGINAL : '%s'\n", str2);
	return (0);
}
*/
