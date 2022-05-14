/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:15:06 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/06 11:20:38 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main()
{
	t_list	**lst;
	t_list	*new;
	t_list	*begin;
	t_list	element1;
	t_list	element2;
	t_list	element3;

	begin = &element1;
	
	element1.content = 42;
	element1.next = &element2;

	element2.content = 412;
	element2.next = 0;

	element3.content = 2511;
	element3.next = 0;

	new = &element3;
	begin = &element1;
	
	lst = &begin;

	ft_lstadd_front(lst, new);
	begin = &element3;
	printf("%d\n", begin->content);
	begin = begin->next;
	printf("%d", begin->content);
}
*/
