/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:59:11 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/04/12 14:02:50 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_limit_int(const char *nptr, int neg)
{
	if ((neg == 1 && ft_strncmp(nptr, "2147483647", 11) > 0)
		|| (neg == -1 && ft_strncmp(nptr, "-2147483648", 12) > 0))
		return (1);
	return (0);
}

int	ft_strtoi(const char *nptr, char **endptr, int *status)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	result = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			neg = -1;
	if (!(nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '\0')
		*status = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = (10 * result) + (nptr[i++] - 48);
	if ((nptr[i] != ' ' && nptr[i] != '\0')
		|| (i >= 10 && is_limit_int(nptr, neg)))
		*status = 1;
	else
		*status = 0;
	if (endptr)
		*endptr += i;
	return (result * neg);
}
