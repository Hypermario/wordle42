/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:36:16 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/06 15:38:03 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	result_size(char const *s1, char const *set)
{
	int	end;
	int	start;

	start = 0;
	if (!s1)
		return (0);
	end = ft_strlen(s1) - 1;
	while (is_in_set(s1[start], set) && s1[start])
		start++;
	while (is_in_set(s1[end], set) && end > start)
		end--;
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		end;
	char	*res;

	res = malloc(result_size(s1, set) + 1);
	if (!res || !s1)
		return (0);
	i = 0;
	j = 0;
	end = ft_strlen(s1) - 1;
	while (is_in_set(s1[i], set) && s1[i])
		i++;
	while (is_in_set(s1[end], set) && end > i)
		end--;
	while (i <= end)
	{
		res[j++] = ((char *)s1)[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}
