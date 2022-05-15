/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:02:43 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/15 17:45:55 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "put_letter.h"
#include "wordle.h"

int	init_letters(t_data *data)
{
	void	*img;
	int		x;
	int		y;

	img = mlx_xpm_file_to_image(data->mlx, PATH_LETTER_EMPTY, &x, &y);
	if (!img)
		return (-1);
	data->iw = 0;
	while (data->iw < 6)
	{
		data->il = 0;
		while (data->il < 5)
		{
			x = PAD_WORDS_LEFT + data->il * (100 + PAD_BETWEEN_LETTERS);
			y = PAD_WORDS_TOP + data->iw * (100 + PAD_BETWEEN_WORDS);
			mlx_put_image_to_window(data->mlx, data->win, img, x, y);
			data->il++;
		}
		data->iw++;
	}
	mlx_destroy_image(data->mlx, img);
	data->il = 0;
	data->iw = 0;
	return (0);
}

int	init_background(t_data *data)
{
	void	*img;
	int		x;
	int		y;

	img = mlx_xpm_file_to_image(data->mlx, PATH_BACKGROUND, &x, &y);
	if (!img)
		return (-1);
	mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
	mlx_destroy_image(data->mlx, img);
	return (0);
}

int	init_console(t_data *data)
{
	void	*img;
	int		x;
	int		y;

	img = mlx_xpm_file_to_image(data->mlx, PATH_BACKGROUND_BLACK, &x, &y);
	if (!img)
		return (-1);
	mlx_put_image_to_window(data->mlx, data->win, img, WIDTH_WORDLE, 0);
	mlx_destroy_image(data->mlx, img);
	printf_console(data, "Welcome to Wordle!");
	printf_console(data, "");
	printf_console(data, "You have 6 tries to find the secret word");
	printf_console(data, "For each try, enter a word and press enter");
	printf_console(data, "");
	printf_console(data, "Green means the letter is correct");
	printf_console(data, "Yellow means the letter is not in the right place");
	printf_console(data, "Grey means the letter is not in the word");
	printf_console(data, "");
	printf_console(data, "Press SPACE to relaunch");
	printf_console(data, "");
	printf_console(data, "Good luck!");
	printf_console(data, "");
	printf_console(data, "");
	printf_console(data, "");
	return (0);
}

int	init_display(t_data *data)
{
	if (init_background(data) == -1)
		return (-1);
	if (init_letters(data) == -1)
		return (-1);
	if (init_console(data) == -1)
		return (-1);
	return (0);
}
