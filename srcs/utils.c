/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:14:22 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 15:28:40 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

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
