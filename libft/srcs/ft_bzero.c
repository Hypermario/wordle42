/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:03:43 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/11/30 12:11:32 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (n == 0)
		return ;
	i = 0;
	ptr = (unsigned char *)s;
	while (n > i)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	int		tab[] = {1, 1, 2, 2, 1};
	int		*ptr = tab;
	size_t	n = 4 * sizeof(int);
	int i = 0;

	while (i < 5)
	{
		printf("%d,", tab[i]);
		i++;
	}

	printf("\n");
//	ft_bzero(ptr, n);
	bzero(ptr, n);
	printf("\n");

	i = 0;
	while (i < 5)
	{
		printf("%d,", tab[i]);
		i++;
	}
}
*/
