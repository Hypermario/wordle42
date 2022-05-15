/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_letter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:13:56 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/15 12:48:04 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_letter.h"
#include "wordle.h"

static void	set_path_letter(char *path, char c)
{
	path[PATH_LETTER_I_LETTER] = c;
}

static void	set_path_state(char *path, int state)
{
	path[PATH_LETTER_I_STATE] = '0' + state;
}

int	put_letter(t_data *data, char c, int state)
{
	void	*img;
	char	path[] = PATH_LETTER_TEMPLATE;
	int		x;
	int		y;

	set_path_letter(path, c);
	set_path_state(path, data->state);
	img = mlx_xpm_file_to_image(data->mlx, path, &x, &y);
	if (!img)
		return (-1);
	x = PAD_WORDS_LEFT + data->il * (100 + PAD_BETWEEN_LETTERS);
	y = PAD_WORDS_TOP + data->iw * (100 + PAD_BETWEEN_WORDS);
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	mlx_destroy_image(data->mlx, img);
	return (0);
}

int	write_letter(t_data *data, char c)
{
	if (data->il > 5)
		return (0);
	if (put_letter(data, c, STATE_WRITTEN) == -1)
		return (-1);
	data->il++;
	return (1);
}

int	erase_letter(t_data *data, char c)
{
	void	*img;
	char	path[] = PATH_LETTER_EMPTY;

	if (data->il <= 0)
		return (0);
	img = mlx_xpm_file_to_image(data->mlx, path, &x, &y);
	if (!img)
		return (-1);
	data->il--;
	x = PAD_WORDS_LEFT + data->il * (100 + PAD_BETWEEN_LETTERS);
	y = PAD_WORDS_TOP + data->iw * (100 + PAD_BETWEEN_WORDS);
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	mlx_destroy_image(data->mlx, img);
	return (1);
}
