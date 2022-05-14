/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:53:52 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/05 17:14:03 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			res;
	unsigned char	*ptr;

	res = nmemb * size;
	ptr = malloc(res);
	if (!ptr)
		return (0);
	ft_bzero(ptr, res);
	return (ptr);
}
/*
#include <libc.h>

int	main(void)
{
//	char	*ptr;

//	ptr = ft_calloc(100, 4);
//	ptr[401] = 'q';
//	printf("%d", ptr[4000]);
	int size;
	int count = 42 * 3;

	ft_calloc(count, sizeof(char));
	size = get_last_malloc_size();
	if (size == count * sizeof(char))
		printf("OK");
	printf("KO");
}
*/
