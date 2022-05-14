/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:29:26 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/02/15 17:57:46 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	forbidden_char(char *str)
{
	int	i;
	int	a;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (1);
		a = i + 1;
		while (str[a])
		{
			if (str[i] == str[a] || str[i] == '+' || str[i] == '-')
				return (1);
			a++;
		}
		i++;
	}
	return (0);
}

static int	get_base_number(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

static int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (base[i] == c)
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		neg;
	long	nbr;
	long	baselen;

	i = 0;
	nbr = 0;
	neg = 1;
	baselen = ft_strlen(base);
	if (forbidden_char(base) || baselen < 2)
		return (0);
	while ((str[i] == '-' || str[i] == '+')
		|| (str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && is_in_base(str[i], base))
	{
		nbr = nbr * baselen + get_base_number(str[i], base);
		i++;
	}
	return (nbr * neg);
}
