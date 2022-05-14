/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:30:15 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/14 16:55:53 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

bool	dict_check(t_data *data, char *in)
{
	int		fd;
	char	*line;
	
	fd = open(data->file, O_RDONLY);
	if (fd < 0)
		return (false);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line = line_wrapper(line);
		if (!ft_strncmp(line, in, ft_strlen(in) + 1))
			return ((void)close(fd), true);
		free(line);
	}
	close(fd);
	return (false);
}
