/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:30:15 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 17:24:48 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

static int	check_file(char *file)
{
	int		fd;
	char	*ext;

	if (!file)
		return (-2);
	ext = ft_strnstr(file, ".txt", ft_strlen(file));
	if (!ext)
		return (-2);
	if (ext && ft_strncmp(ext, ".txt", 5))
		return (-2);
	fd = open(file, O_RDONLY);
	return (fd);
}

static long	count_lines(int fd)
{
	int		len;
	char	buf[1];

	len = 1;
	while (1)
	{
		if (read(fd, buf, 1) != 1 || (len < 0 || len >= INT_MAX))
			return (len);
		if (buf[0] == '\n')
			len++;
	}
	return (close(fd));
}

/*
**	returns the line without \n
*/
char	*line_wrapper(char *line)
{
	char	*ret;

	ret = ft_substr(line, 0, ft_strlen(line) - 1);
	free(line);
	return (ft_strtolower(ret));
}

/*
**	Checks if in is in dictionary
**	returns true or false
*/
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
			return ((void)close(fd), free(line), true);
		free(line);
	}
	close(fd);
	return (false);
}

/*
**	Selects a random word in the file
**	from the word 0 to end of file.
**	Returns 0 if no errors with the file
**	else returns 2 or close() return value.
*/
int	dict_random_word(char *file, t_data *data)
{
	int		fd;
	int		len;
	int		randword;
	char	*line;

	fd = check_file(file);
	if (fd < 0)
		return (2);
	srand(time(NULL));
	len = count_lines(fd);
	if (len < 1)
		return (2);
	randword = rand() % len;
	fd = check_file(file);
	if (fd < 0)
		return (2);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || randword-- <= 0)
			break ;
		free(line);
	}
	data->fullword = line_wrapper(line);
	return (close(fd));
}
