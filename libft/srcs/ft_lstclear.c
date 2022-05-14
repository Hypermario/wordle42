/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:15:25 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/14 15:03:19 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Free a list
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*old;

	if (!lst)
		return ;
	while (*lst)
	{
		old = *lst;
		if (del)
			del(*lst);
		*lst = old->next;
		free(old);
	}
	*lst = 0;
}
