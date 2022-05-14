/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:46:30 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/01/07 15:46:32 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(int c, int *index)
{
	write (1, &c, 1);
	*index += 1;
	return (-1);
}

int	ft_printf_str(char *str, int *index)
{
	*index += 1;
	if (!str)
	{
		write(1, "(null)", 6);
		return (4);
	}
	return (ft_putstri_fd(str, 1) - 1);
}

int	ft_printf_sint(int d, int *index)
{
	int		len;

	ft_putnbr_fd(d, 1);
	len = ft_numlen(d);
	if (d < 0)
		len++;
	*index += 1;
	return (len - 1);
}

int	ft_printf_hex(const char *s, unsigned long x, int *index)
{
	int	len;

	len = 0;
	if (s[*index] == 'x')
		ft_putnbri_base_fd(x, "0123456789abcdef", &len, 1);
	else
		ft_putnbri_base_fd(x, "0123456789ABCDEF", &len, 1);
	*index += 1;
	return (len - 2);
}

int	ft_printf_uint(unsigned int u, int *index)
{
	int		len;

	ft_putunbr_fd(u, 1);
	len = ft_unumlen(u);
	*index += 1;
	return (len - 1);
}
