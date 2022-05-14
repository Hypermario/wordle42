/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:16:49 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/03/20 00:20:17 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove_gnl(void *dest, const void *src, size_t n)
{
	unsigned char		*destc;
	const unsigned char	*srcc;

	destc = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (destc > srcc)
	{
		while (n--)
			*(destc + n) = *(srcc + n);
		return (dest);
	}
	while (n--)
		*destc++ = *srcc++;
	*destc = '\0';
	return (dest);
}

char	*ft_strdup_gnl(const char *s, size_t n)
{
	char	*new;
	size_t	i;

	if (!s)
		return (0);
	new = malloc(n + 1);
	if (!new)
		return (0);
	i = 0;
	while (s[i] != '\0' && n > i)
	{
		new[i] = (char)s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin_gnl(char *s1, char const *s2, size_t n)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	n += ft_strlen(s1);
	res = malloc(n + 1);
	if (!res)
		return (0);
	while (s1[j] != '\0' && n > i)
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0' && n > i)
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}
