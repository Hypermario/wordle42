/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:16:19 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/14 15:08:05 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	return (new);
}
/*
int	main()
{
	int		i = 2511;
	void	*cont;
	t_list	elem1;
	t_list	*begin;

	cont = i;
	begin = ft_lstnew(cont);
	printf("%d", begin->content);
}
*/
