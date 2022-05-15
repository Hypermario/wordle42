/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:02:43 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/15 17:26:31 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "wordle.h"

int	init_letters(t_data *data)
{
	data->iw = 0;
	while (data->iw < 6)
	{
		data->il = 5;
		while (data->il > 0)
			if (erase_letter(data) == -1)
				return (-1);
		data->iw++;
	}
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
	img = mlx_xpm_file_to_image(data->mlx, PATH_BACKGROUND_BLACK, &x, &y);
	if (!img)
		return (-1);
	mlx_put_image_to_window(data->mlx, data->win, img, WIDTH_WORDLE, 0);
	mlx_destroy_image(data->mlx, img);
	return (0);
}

int	init_display(t_data *data)
{
	if (init_background(data) == -1)
		return (-1);
	if (init_letters(data) == -1)
		return (-1);
	return (0);
}
