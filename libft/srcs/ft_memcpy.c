/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:37:31 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/11/30 12:26:52 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src && n)
		return (0);
	while (n > i)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	size_t	i = 0;
	size_t	n = 8;
	int		tab1[] = {1, 1, 2, 3, 5};
	int		*tab2 = malloc(n);

	ft_memcpy(tab2, tab1, n);
	
	while (i < n)
	{
		printf("%d", tab2[i]);
		i++;
	}

}*/
