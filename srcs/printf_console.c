/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_console.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:03:05 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/15 17:23:16 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "wordle.h"

static void	get_until_format(char **format, char **str)
{
	char	*new_str;
	int		len_until_format;

	len_until_format = 0;
	while ((*format)[len_until_format] && (*format)[len_until_format] != '%')
		len_until_format++;
	new_str = calloc(ft_strlen(*str) + len_until_format + 1, sizeof(char));
	if (!new_str)
	{
		*format = NULL;
		return ;
	}
	ft_memcpy(new_str, *str, ft_strlen(*str));
	ft_memcpy(new_str + ft_strlen(*str), *format, len_until_format);
	new_str[ft_strlen(*str) + len_until_format] = 0;
	if (*str)
		free(*str);
	*str = new_str;
	*format += len_until_format;
	if (**format)
		*format += 1;
}

static void	get_format(va_list vars_printf, char **format, char **str)
{
	char	*new_str;
	char	*nbr;

	if (!*format || !**format)
		return ;
	new_str = 0;
	if (**format == 'd' || **format == 'i')
	{
		nbr = ft_itoa(va_arg(vars_printf, int));
		if (nbr)
		{
			new_str = ft_strjoin(*str, nbr);
			free(nbr);
		}
	}
	if (**format == 'c')
	{
		new_str = calloc(ft_strlen(*str) + 1, sizeof(char));
		if (new_str)
		{
			ft_memcpy(new_str, *str, ft_strlen(*str));
			new_str[ft_strlen(*str)] = (char) va_arg(vars_printf, int);
			new_str[ft_strlen(*str) + 1] = 0;
		}
	}
	if (**format == 's')
		new_str = ft_strjoin(*str, va_arg(vars_printf, char *));
	if (!new_str)
	{
		*format = 0;
		return ;
	}
	if (*str)
		free(*str);
	*str = new_str;
	*format += 1;
}

static int	putlines_mlx(t_data *data, char *str)
{
	char	buff[CONSOLE_LINE_CHARS_MAX + 1];
	int		i;
	int		x;
	int		y;

	ft_memset(buff, 0, CONSOLE_LINE_CHARS_MAX + 1);
	x = PAD_CONSOLE_LEFT;
	i = 0;
	while (data->iconsole < CONSOLE_MAX_LINES && ft_strlen(str + i * CONSOLE_LINE_CHARS_MAX) > CONSOLE_LINE_CHARS_MAX)
	{
		ft_memcpy(buff, str + i * CONSOLE_LINE_CHARS_MAX, CONSOLE_LINE_CHARS_MAX);
		y = PAD_CONSOLE_TOP + data->iconsole * CONSOLE_SIZE_FONT;
		if (mlx_string_put(data->mlx, data->win, x, y, 0xFFFFFF, buff) == -1)
			return (-1);
		data->iconsole++;
		i++;
	}
	ft_memcpy(buff, str + i * CONSOLE_LINE_CHARS_MAX, ft_strlen(str + i * CONSOLE_LINE_CHARS_MAX));
	y = PAD_CONSOLE_TOP + data->iconsole * CONSOLE_SIZE_FONT;
	if (data->iconsole < CONSOLE_MAX_LINES && mlx_string_put(data->mlx, data->win, x, y, 0xFFFFFF, str + i * CONSOLE_LINE_CHARS_MAX) == -1)
		return (-1);
	data->iconsole++;
	return (0);
}

int	printf_console(t_data *data, char *format, ...)
{
	char	*str;
	va_list	vars_printf;

	if (!data || !format)
		return (-1);
	str = ft_strdup("");
	if (!str)
		return (-1);
	va_start(vars_printf, format);
	while (format && *format)
	{
		get_until_format(&format, &str);
		get_format(vars_printf, &format, &str);
	}
	va_end(vars_printf);
	if (!format)
	{
		if (str)
			free(str);
		return (-1);
	}
	if (str)
	{
		if (putlines_mlx(data, str) == -1)
			return (-1);
		free(str);
	}
	return (0);
}
