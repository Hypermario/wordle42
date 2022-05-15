/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:04:27 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 16:51:22 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_moved(char *buf)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!buf || !(*buf))
		return (0);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	len = i;
	if (buf[i] == '\n')
		len++;
	str = ft_strdup_gnl(buf, len);
	if (!str)
		return (0);
	if (buf[i] && buf[i + 1])
		ft_memmove_gnl(buf, buf + len, ft_strlen(buf + len));
	else
		ft_bzero(buf, BUFFER_SIZE);
	return (str);
}

static int	buf_to_str(char *buf, char **str)
{
	int		i;
	int		len;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	len = i;
	if (buf[i] == '\n')
		len++;
	if (!(*str))
		*str = ft_strdup_gnl(buf, len);
	else if (*str)
		*str = ft_strjoin_gnl(*str, buf, len);
	if (buf[i] && buf[i] == '\n' && buf[i + 1])
	{
		ft_memmove_gnl(buf, buf + len, ft_strlen(buf + len));
		return (-1);
	}
	else
		ft_bzero(buf, BUFFER_SIZE);
	return (i);
}

static char	*get_line(char *str, char *buf, int fd)
{
	int	red;
	int	i;

	red = BUFFER_SIZE;
	while (red > 0)
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red == 0 || *buf == '\0')
			return (str);
		if (red == -1)
		{
			if (str)
				free(str);
			return (0);
		}
		i = buf_to_str(buf, &str);
		if (i == -1 || i < red || buf[i] == '\n')
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (0);
	str = get_moved(buf[fd]);
	if (*buf[fd] == '\0' && (!str || (str && str[ft_strlen(str) - 1] != '\n')))
		str = get_line(str, buf[fd], fd);
	return (str);
}
