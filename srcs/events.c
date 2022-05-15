/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:19:22 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 14:57:55 by jmolvaut         ###   ########.fr       */
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
		free_data(*data);
		exit(0);
	}
	else if (keysym == XK_Return && !data->finished)
	{
		if (prevlen == 5)
		{
			if (!dict_check(data, data->in))
			{
				data->lasterror = time(NULL);
				printf("%lu\n", data->lasterror);
				printf("Not in dictionary\n"); // put error image
				return (0);
			}
			data->tries--;
			word_check(data, data->in);
			validate_letters(data);
			if (data->correct)
			{
				printf("YOU WON IN %d TRIES!\n", -(data->tries - 6)); // put error image
				data->finished = true;
				return (0);
			}
			else
			{
				printf("Incorrect word, %d tries remaining\n", data->tries); // put error image
				data->lasterror = time(NULL);
			}
			data->iw++;
			free(data->in);
			data->in = NULL;
		}
		else if (prevlen < 5)
		{
			printf("Word is too short\n"); // put error image
		}
		if (data->tries <= 0)
		{
			printf("The word was %s\n", data->fullword); // put error image
			data->finished = true;
		}
	}
	else if (keysym == XK_BackSpace && !data->finished)
	{
		erase_letter(data);
		tmp = data->in;
		data->in = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
		printf("key=bs in=%s\n", data->in);
	}
	else if (!data->finished)
	{
		if (data->lasterror + 2000 <= time(NULL))
		{
			// delete error image
			printf("deleting error image\n");
		}
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
		printf("key=%c in=%s\n", keysym, data->in);
	}
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
