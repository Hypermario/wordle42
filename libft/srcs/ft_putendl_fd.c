/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:40:07 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/06 15:41:13 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write (fd, &s[i], 1);
			i++;
		}
		write (fd, "\n", 1);
	}
}
/*
#include <fcntl.h>
int	main()
{
	int	fd;

	fd = open("test", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_putendl_fd("c'est le test", fd);
}
*/
