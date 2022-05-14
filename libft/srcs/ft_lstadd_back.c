/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:14:55 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/01/05 12:48:35 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the new element to the back of alst (address of begin)
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	last = *alst;
	if (!alst)
		return ;
	if (*alst == 0)
		*alst = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
