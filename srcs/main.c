/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:21:27 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 16:17:31 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

static t_data	init_data(char *file)
{
	t_data	data;

	data.mlx = NULL;
	data.win = NULL;
	data.img.mlx_img = NULL;
	data.img.addr = NULL;
	data.iw = 0;
	data.il = 0;
	data.iconsole = 0;
	data.tries = 6;
	data.lasterror = 0;
	data.file = file;
	data.in = NULL;
	data.finished = false;
	return (data);
}

static int	mlx(t_data data)
{
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (free_data(&data), MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "wordle");
	if (data.win == NULL)
	{
		mlx_destroy_display(data.mlx);
		return (free_data(&data), MLX_ERROR);
	}
	if (create_image(&data))
		return (free_data(&data), MLX_ERROR);
	init_display(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, 0, &handle_closing, &data);
	mlx_loop(data.mlx);
	return (free_data(&data), 0);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*file;
	int		mp;

	if (ac >= 2)
		file = av[1];
	else
		file = "words.txt";
	data = init_data(file);
	mp = dict_random_word(file, &data);
	if (mp == -1)
		return (perror("open"), -1);
	else if (mp == 2)
		return (ft_putstr_fd("wordle: dictionary error\n", 2), 2);
	printf("Hint : the word is %s\n", data.fullword);
	return (mlx(data));
}
