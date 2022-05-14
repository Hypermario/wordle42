/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argp_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:46:20 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/01/07 15:46:23 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_void_hex(void *x, int *index)
{
	int		len;

	len = 0;
	len += ft_putstri_fd("0x", 1);
	ft_putuli_base_fd((unsigned long)x, "0123456789abcdef", &len, 1);
	*index += 1;
	return (len - 1);
}
