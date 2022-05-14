/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:35:54 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/11/29 15:56:52 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	new = malloc(ft_strlen(s) + 1);
	if (!new)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = (char)s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main(void)
{
	const char	*str = "tetst";
	char		*cpy;

	printf("%s", ft_strdup(str));
}*/
