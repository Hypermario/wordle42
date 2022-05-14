/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:15:38 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/01/30 12:42:45 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	delone(void *pt)
{
	free(pt);
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst);
	free(lst);
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
	void	(*f)(void *);

	f = &delone;
	begin = &element1;
	
	element1.content = malloc(10);
	element1.next = &element2;

	element2.content = 412;
	element2.next = 0;

	element3.content = 2511;
	element3.next = 0;

	new = &element3;
	begin = &element1;
	
	lst = &begin;

	ft_lstdelone(begin, f);
	begin = &element1;
	printf("%d\n", begin->content);
	begin = begin->next;
	printf("%d", begin->content);
}
*/
