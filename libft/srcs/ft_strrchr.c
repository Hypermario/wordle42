/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:20:21 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/02 14:56:28 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		chr;
	char	*ptr;

	i = 0;
	chr = -1;
	if (c > 256)
		c -= 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			chr = i;
		i++;
	}
	if (c == '\0')
		chr = i;
	ptr = &((char *)s)[chr];
	if (chr != -1 && s[chr] == c)
		return (ptr);
	return (0);
}
