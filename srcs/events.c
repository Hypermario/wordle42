/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:19:22 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 11:48:41 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		free_data(*data);
		exit(0);
	}
	if (keysym == 'A' || keysym == 'a')
		write_letter(data, 'a');
	if (keysym == 'B' || keysym == 'b')
		write_letter(data, 'b');
	if (keysym == 'C' || keysym == 'c')
		write_letter(data, 'c');
	if (keysym == 'D' || keysym == 'd')
		write_letter(data, 'd');
	if (keysym == 'E' || keysym == 'e')
		write_letter(data, 'e');
	if (keysym == 'F' || keysym == 'f')
		write_letter(data, 'f');
	if (keysym == 'G' || keysym == 'g')
		write_letter(data, 'g');
	if (keysym == 'H' || keysym == 'h')
		write_letter(data, 'h');
	if (keysym == 'I' || keysym == 'i')
		write_letter(data, 'i');
	if (keysym == 'J' || keysym == 'j')
		write_letter(data, 'j');
	if (keysym == 'K' || keysym == 'k')
		write_letter(data, 'k');
	if (keysym == 'L' || keysym == 'l')
		write_letter(data, 'l');
	if (keysym == 'M' || keysym == 'm')
		write_letter(data, 'm');
	if (keysym == 'N' || keysym == 'n')
		write_letter(data, 'n');
	if (keysym == 'O' || keysym == 'o')
		write_letter(data, 'o');
	if (keysym == 'P' || keysym == 'p')
		write_letter(data, 'p');
	if (keysym == 'Q' || keysym == 'q')
		write_letter(data, 'q');
	if (keysym == 'R' || keysym == 'r')
		write_letter(data, 'r');
	if (keysym == 'S' || keysym == 's')
		write_letter(data, 's');
	if (keysym == 'T' || keysym == 't')
		write_letter(data, 't');
	if (keysym == 'U' || keysym == 'u')
		write_letter(data, 'u');
	if (keysym == 'V' || keysym == 'v')
		write_letter(data, 'v');
	if (keysym == 'W' || keysym == 'w')
		write_letter(data, 'w');
	if (keysym == 'X' || keysym == 'x')
		write_letter(data, 'x');
	if (keysym == 'Y' || keysym == 'y')
		write_letter(data, 'y');
	if (keysym == 'Z' || keysym == 'z')
		write_letter(data, 'z');
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
