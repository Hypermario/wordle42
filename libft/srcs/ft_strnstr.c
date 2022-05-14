/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:48:30 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/06 17:18:43 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	char	*str;
	size_t	size;
	size_t	size2;

	if (!ft_strncmp(s2, "", 1))
		return ((char *)s1);
	size = 0;
	str = (char *)s1;
	while (*str && n >= size)
	{
		i = 0;
		size2 = size;
		while (str[i] == s2[i] && str[i] && s2[i] && n >= ++size2)
			i++;
		if (i == (int)ft_strlen(s2))
			return (str);
		str++;
		size++;
	}
	return (0);
}
/*
#include <libc.h>

int	main(void)
{
	char *s1 = "A";
	char *i1 = strnstr(s1, s1, 2);
	char *i2 = ft_strnstr(s1, s1, 2);

	printf("%s ?= %s\n", i1, i2);
	if (i1 == i2)
		printf("OK");
}
*/
