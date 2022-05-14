/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:52:21 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/11/19 15:49:22 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = c;
		i++;
	}
	return (s);
}
/*
int main() 
{
    int array[] = {54, 85, 20, 63, 21};
    size_t size = sizeof(int) * 5;
    int length;

    for (length=0; length<5; length++)
        printf("%d ", array[length]);
    printf("\n");

    ft_memset(array, 0, size);
    
	for (length=0; length<5; length++)
        printf("%d ", array[length]);
    printf("\n");
    
    return 0;
}*/
