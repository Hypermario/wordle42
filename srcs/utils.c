/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:14:22 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 17:24:30 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	reset_game(t_data *data)
{
	int	mp;

	free(data->in);
	data->in = NULL;
	free(data->fullword);
	data->fullword = NULL;
	data->iw = 0;
	data->il = 0;
	data->iconsole = 0;
	data->tries = 6;
	data->finished = false;
	mp = dict_random_word(data->file, data);
	if (mp == -1)
	{
		data->finished = true;
		return (perror("open"));
	}
	else if (mp == 2)
	{
		data->finished = true;
		return (ft_putstr_fd("wordle: dictionary error\n", 2));
	}
	init_display(data);
}

void	free_split(char	**split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_data(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_display(data->mlx);
	free(data->fullword);
	free(data->in);
	free(data->mlx);
}
