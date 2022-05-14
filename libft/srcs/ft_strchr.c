/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:16:16 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/02/15 22:15:16 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Find a char in a string.
// Returns a pointer to the first char in the string.
// Returns 0 if not found.
char	*ft_strchr(const char *s, int c)
{
	if (c > 256)
		c -= 256;
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}
