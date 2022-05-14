/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:04:00 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/01/07 15:40:21 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_noargs(const char *s, int i)
{
	int	len;

	len = ft_strlen(s);
	while (s[i] && i < len)
	{
		if (s[i + 1] != '\0' && s[i] == '%')
			return (i + 1);
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_write_args(const char *s, int i, int len, va_list ap)
{
	while (s[i])
	{
		i = ft_printf_noargs(s, i);
		if (s[i] && s[i] == 'c')
			len += ft_printf_char(va_arg(ap, int), &i);
		else if (s[i] && s[i] == '%')
		{
			i++;
			len += ft_putstri_fd("%", 1) - 1;
		}
		else if (s[i] && s[i] == 's')
			len += ft_printf_str(va_arg(ap, char *), &i);
		else if (s[i] && (s[i] == 'd' || s[i] == 'i'))
			len += ft_printf_sint(va_arg(ap, int), &i);
		else if (s[i] && (s[i] == 'x' || s[i] == 'X'))
			len += ft_printf_hex(s, va_arg(ap, int), &i);
		else if (s[i] && s[i] == 'u')
			len += ft_printf_uint(va_arg(ap, unsigned int), &i);
		else if (s[i] && s[i] == 'p')
			len += ft_void_hex(va_arg(ap, void *), &i);
		else if (s[i])
			ft_putchar_fd(s[i], 1);
	}
	len += (i);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, s);
	len = ft_write_args(s, i, len, ap);
	va_end(ap);
	return (len);
}
