/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstri_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:29:05 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/01/05 18:14:57 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstri_fd(char *str, int fd)
{
	size_t	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	write(fd, str, i);
	return (i - 1);
}
