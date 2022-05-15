/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:21:27 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 13:03:29 by jmolvaut         ###   ########.fr       */
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
	data.tries = 6;
	data.file = file;
	return (data);
}

static int	mlx(t_data data)
{
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (free_data(data), MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "wordle");
	if (data.win == NULL)
	{
		mlx_destroy_display(data.mlx);
		return (free_data(data), MLX_ERROR);
	}
	if (create_image(&data))
		return (free_data(data), MLX_ERROR);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, 0, &handle_closing, &data);
	mlx_loop(data.mlx);
	return (free_data(data), 0);
}

// void	game(t_data *data)
// {
// 	char	*line;
// 	size_t	len;
	
// 	while (data->tries)
// 	{
// 		line = get_next_line(0);
// 		if (!line)
// 			return ;
// 		line = line_wrapper(line);
// 		len = ft_strlen(line);
// 		if (len == 5)
// 		{
// 			if (!dict_check(data, line))
// 			{
// 				printf("Not in dictionary\n");
// 				continue ;
// 			}
// 			data->tries--;
// 			word_check(line, data);
// 			word_print(data->word[data->iw]);
// 			if (data->correct)
// 				return ;
// 			else
// 				printf("Incorrect word, %d tries remaining\n", data->tries);
// 			data->iw++;
// 		}
// 		else if (len < 5)
// 			printf("Word is too short\n");
// 		else
// 			printf("Word is too long\n");
			
// 	}
// }

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
	printf("The word is %s\n", data.fullword);
	// game(&data);
	// if (!data.correct)
	// 	printf("The word was %s\n", data.fullword);
	// else
	// 	printf("YOU WON IN %d TRIES!\n", -(data.tries - 6));
	return (mlx(data));
}
