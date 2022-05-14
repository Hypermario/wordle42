/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:17:45 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/27 18:30:08 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoalen(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (n < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	if (n < 0)
		nb++;
	return (i);
}

static char	*ft_itoa_str(int n, char *res, int max, int numlen)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		res[0] = '-';
		nb = n * -1;
		max = 1;
	}
	res[numlen + 1] = '\0';
	while (numlen >= max)
	{
		res[numlen] = ((nb % 10) + '0');
		numlen--;
		nb /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int				numlen;
	int				max;
	char			*res;

	numlen = ft_itoalen(n);
	if (n < 0)
		res = malloc(numlen + 2);
	else
		res = malloc(numlen + 1);
	if (!res)
		return (0);
	if (n >= 0)
		numlen--;
	max = 0;
	ft_itoa_str(n, res, max, numlen);
	return (res);
}
/*
int	main()
{
	printf("%s\n", ft_itoa(125));
	printf("%s\n", ft_itoa(-0));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(-42222));
	printf("%s\n", ft_itoa(-43332));
	printf("%s\n", ft_itoa(-445552));
	printf("%s\n", ft_itoa(-466782));
	printf("%s\n", ft_itoa(-4552));
	printf("%s\n", ft_itoa(-412));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
}
*/
