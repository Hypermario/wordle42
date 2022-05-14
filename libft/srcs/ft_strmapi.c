/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:55:49 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/06 15:39:52 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	nextchar(unsigned int n, char c)
{
	return (c + 1);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (0);
	while (s[i] != '\0')
	{
		res[i] = f(i, (char)s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
int	main()
{
	char	(*f)(unsigned int, char);
	char	*s = "TEST";

	f = &nextchar;
	printf("%s", ft_strmapi(s, f));
}
*/
