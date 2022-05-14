/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:24:44 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/02/04 16:06:52 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *s, char c, int firstchar)
{
	int	len;

	len = 0;
	while (s[firstchar] && s[firstchar] != c)
	{
		firstchar++;
		len++;
	}
	return (len);
}

static void	free_tab(char **tab, int w)
{
	while (w)
	{
		free(tab[w]);
		w--;
	}
	free(tab[w]);
	free(tab);
}

static char	**ft_split_tab(char **res, char const *s, char c, int len)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i] && i < len)
	{
		if (s[i] != c)
		{
			res[w++] = ft_substr(s, i, ft_wordlen(s, c, i) + 1);
			if (!res[w - 1])
			{
				free_tab(res, w - 1);
				return (0);
			}
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	res[w] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**res;

	if (!s)
		return (0);
	res = (char **)malloc(ft_wordcount(s, c) * sizeof(char *));
	if (!res)
		return (0);
	len = ft_strlen(s) + 1;
	if (ft_split_tab(res, s, c, len))
		return (res);
	return (0);
}
