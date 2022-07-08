/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:19:22 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/16 11:32:13 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	handle_keypress(int keysym, t_data *data)
{
	const size_t	prevlen = ft_strlen(data->in);
	char			*tmp;

	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		free_data(data);
		exit(0);
	}
	else if (keysym == XK_F1)
		printf_console(data, data->fullword);
	else if (keysym == XK_Return && !data->finished)
	{
		if (prevlen == 5)
		{
			if (!dict_check(data, data->in))
			{
				printf_console(data, "Not in dictionary");
				return (0);
			}
			data->tries--;
			data->correct = word_check(data);
			if (validate_letters(data))
				return (1);
			if (data->correct)
			{
				printf_console(data, "YOU WON IN %d TRIES!", -(data->tries - 6));
				data->finished = true;
				return (0);
			}
			else
				printf_console(data, "Incorrect word, %d tries remaining", data->tries);
			data->iw++;
			free(data->in);
			data->in = NULL;
		}
		else if (prevlen < 5)
		{
			printf_console(data, "Word is too short");
		}
		if (data->tries <= 0)
		{
			printf_console(data, "The word was %s", data->fullword);
			data->finished = true;
		}
	}
	else if (keysym == XK_BackSpace && !data->finished)
	{
		erase_letter(data);
		tmp = data->in;
		data->in = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
	}
	else if (!data->finished)
	{
		if (((keysym == 'A' && keysym <= 'Z') || (keysym >= 'a' && keysym <= 'z'))
			&& prevlen < 5)
		{
			write_letter(data, ft_tolower((char)keysym));
			tmp = data->in;
			if (!data->in)
				data->in = ft_strdup((char *)&keysym);
			else
				data->in = ft_strjoin(tmp, (char *)&keysym);
			free(tmp);
		}
	}
	if (keysym == XK_F12)
		reset_game(data);
	return (0);
}

int	handle_closing(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	free_data(data);
	exit(0);
	return (0);
}
