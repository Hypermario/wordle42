/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:12:34 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/11/30 10:59:29 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	i2;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	i2 = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	if (size <= dstlen)
		return (size + srclen);
	if (size <= 0)
		return (srclen);
	while (src[i2] != '\0' && i2 < size - dstlen - 1)
	{
		dst[i] = src[i2];
		i2++;
		i++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
