/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:58:22 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/05 14:50:08 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*str1 != *str2)
			return ((int)(*str1 - *str2));
		str1++;
		str2++;
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*a = "z";
	char	*b = "";
	void	*ptr1 = &a;
	void	*ptr2 = &b;
	size_t	n = 7;

	printf("%d\n", ft_memcmp(ptr1, ptr2, n));
	printf("%d", memcmp(ptr1, ptr2, n));
}
*/
