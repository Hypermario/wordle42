/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:21:35 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 13:26:57 by jmolvaut         ###   ########.fr       */
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
	return (0);
}

char	*line_wrapper(char *line)
{
	char	*ret;
	
	ret = ft_substr(line, 0, ft_strlen(line) - 1);
	free(line);
	return (ret);
}

/*
**	check le status de chaque lettres
**	et modifie dans data une structure t_word
*/
void	word_check(t_data *data, char *input)
{
	const char	*word = data->fullword;
	int			i;
	int			correct;
	int			status;
	t_word		*ret;

	i = 0;
	correct = 0;
	ret = NULL;
	while (word[i])
	{
		status = ABSENT;
		if (word[i] == input[i])
		{
			correct++;
			status = CORRECT;
		}
		else if (ft_strchr(word, input[i]))
			status = PRESENT;
		word_add_back(&ret, word_newletter(input[i], status));
		i++;
	}
	if (correct == 5)
		data->correct = true;
	data->word[data->iw] = ret;
	return ;
}

// Parse the map and calculate coordonates for the first time
int	dict_random_word(char *file, t_data *data)
{
	int		fd = check_file(file);
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
	close(fd);
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
