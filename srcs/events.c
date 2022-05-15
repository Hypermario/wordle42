/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:19:22 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 13:05:23 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	handle_keypress(int keysym, t_data *data)
{
	const size_t	prevlen = ft_strlen(data->in);

	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		free_data(*data);
		exit(0);
	}
	else if (keysym == XK_Return && !data->finished)
	{
		if (data->key_typed == 5)
		{
			if (!dict_check(data, data->in))
			{
				printf("Not in dictionary\n");
				return (0);
			}
			data->tries--;
			word_check(data, data->in);
			word_print(data->word[data->iw]);
			if (data->correct)
			{
				printf("YOU WON IN %d TRIES!\n", -(data->tries - 6));
				return (0);
			}
			else
				printf("Incorrect word, %d tries remaining\n", data->tries);
			data->iw++;
		}
		else if (data->key_typed < 5)
			printf("Word is too short\n");
		if (data->tries <= 0)
		{
			printf("The word was %s\n", data->fullword);
			data->finished = true;
		}
	}
	else if (keysym == XK_BackSpace && !data->finished)
	{
		erase_letter(data);
		data->in = ft_substr(data->in, 0, ft_strlen(data->in) - 1, true);
		data->key_typed--;
	}
	else if (!data->finished)
	{
		if ((keysym == 'A' && keysym <= 'Z') || (keysym >= 'a' && keysym <= 'z'))
		{
			write_letter(data, ft_to_lower(keysym));
			if (!data->in)
				data->in = ft_strdup((char *)&keysym);
			else
				data->in = ft_strjoin(data->in, "a", true, false);
		}
		if (ft_strlen(data->in) > prevlen)
			data->key_typed++;
		printf("key=%c in=%s\n", keysym, data->in);
	}
	return (0);
	return (0);
}

int	handle_closing(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	free_data(*data);
	exit(0);
	return (0);
}
