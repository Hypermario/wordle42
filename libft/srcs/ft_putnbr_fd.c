/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:43:01 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/11/25 16:36:34 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == INT_MIN)
		{
			write(fd, "2147483648", 10);
			return ;
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}
/*
#include <fcntl.h>
int	main()
{
	int	fd;

	fd = open("test", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_putnbr_fd(INT_MAX, fd);
}
*/
