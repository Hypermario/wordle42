/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_console.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:03:05 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/15 16:00:08 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "wordle.h"

void	get_until_format(char **format, char **str)
{
	char	*new_str;
	int		len_until_format;

	len_until_format = 0;
	while (*format[len_until_format] && *format[len_until_format] != '%')
		len_until_format++;
	new_str = malloc(ft_strlen(*str) + len_until_format + 1);
	if (!new_str)
	{
		free(*format);
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

void	get_format(va_list vars_printf, char **format, char **str)
{
	char	*new_str;

	if (!*format || !**format)
		return ;
	if (**format == 'd' || **format == 'i')
		new_str = ft_strjoin(*str, ft_atoi(va_arg(vars_printf, int)));
	if (**format == 'c')
	{
		new_str = malloc(ft_strlen(*str) + 1);
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

int	putlines_mlx(t_data *data, char *str)
{
	char	buff[LEN_BUFF_STRING_PUT];
	int		i;
	int		x;
	int		y;

	ft_memset(buff, 0, LEN_BUFF_STRING_PUT);
	x = PAD_CONSOLE_LEFT;
	i = 0;
	while (ft_strlen(str + i * (LEN_BUFF_STRING_PUT - 1)) > LEN_BUFF_STRING_PUT - 1)
	{
		ft_memcpy(buff, str + i * (LEN_BUFF_STRING_PUT - 1), LEN_BUFF_STRING_PUT - 1);
		y = PAD_CONSOLE_TOP + data->iconsole * SIZE_CONSOLE_FONT;
		if (mlx_string_put(data->mlx, data->win, x, y, 0xFFFFFF, buff) == -1)
			return (-1);
		data->iconsole++;
		i++;
	}
	y = PAD_CONSOLE_TOP + data->iconsole * SIZE_CONSOLE_FONT;
	if (mlx_string_put(data->mlx, data->win, x, y, 0xFFFFFF, str + i * (LEN_BUFF_STRING_PUT - 1)) == -1)
		return (-1);
	data->iconsole++;
	return (0);
}

int	printf_console(t_data *data, char *format, ...)
{
	char	*str;
	va_list vars_printf;

	if (!data || !format)
		return (-1);
	str = ft_strdup("");
	if (!str)
		return (-1);
	va_start(vars_printf, format);
	while (format && *format)
	{
		get_until_format(&format, &str);
		get_format(&format, &str);
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
