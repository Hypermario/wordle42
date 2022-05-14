/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:06:20 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/06 15:39:16 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*res;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (len > size)
		res = malloc(size + 1);
	else
		res = malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (start <= size && s[start] && len > i)
	{
		res[i] = (char)s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
