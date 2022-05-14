/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:49:21 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/06 17:31:22 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destc;
	const unsigned char	*srcc;

	destc = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (destc > srcc)
	{
		while (n--)
			*(destc + n) = *(srcc + n);
		return (dest);
	}
	while (n--)
		*destc++ = *srcc++;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	size_t	i;
	size_t	n;
	int		count = 0;
	int		total = count;
	int		tests = 0;
	int		tab[] = {1, 2, 3, 5, 4};
	int		*tab_ft;
	int		*tab_lib;

	n = 4;
	printf("memmove :\n");
	while (tests++ < 10)
	{
		printf("-----%d-----\n", tests);
		tab_ft = malloc(n);
		ft_memmove(tab_ft, tab, n);

		tab_lib = malloc(n);
		memmove(tab_lib, tab, n);

		i = 0;
		while (i < n)
		{
			if (tab_lib[i] == tab_ft[i])
			{
				count++;
				printf("OK");
			}
			else
			{
				printf("KO");
			}	
			printf(" -> %d ?= %d\n", tab_lib[i], tab_ft[i]);
			i++;
		}
		printf("-----%d/%zu-----\n", count, n);
		total += count;
		count = 0;
	}
	tests--;
	printf("\nResult: %d/%d", total, (int)(n*tests));
	if (total/(n*tests) == 1)
		printf("\nGG");
}
*/
