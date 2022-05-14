/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbri_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:36:54 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/23 17:38:55 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	same_char(char *str)
{
	int	i;
	int	a;

	i = 0;
	while (str[i])
	{
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

void	ft_putnbri_base_fd(unsigned int nbr, char *base, int *len, int fd)
{
	unsigned int	baselen;

	baselen = ft_strlen(base);
	if (baselen < 2 || same_char(base))
		return ;
	if (nbr >= baselen)
	{
		ft_putnbri_base_fd(nbr / baselen, base, len, fd);
		ft_putnbri_base_fd(nbr % baselen, base, len, fd);
	}
	else
	{
		*len += 1;
		ft_putchar_fd(base[nbr], fd);
	}
}
