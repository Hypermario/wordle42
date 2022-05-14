/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:52:31 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/14 17:19:32 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	color(int status)
{
	if (status == PRESENT)
		printf("\033[0;33m");
	else if (status == CORRECT)
		printf("\033[0;32m");
	else
		printf("\033[0;31m");
	// printf("TEST\n");
}

void	nocolor(void)
{
	printf("\033[0m");
}

void	word_print(t_word *word)
{
	while(word)
	{
		color(word->status);
		printf("%c", word->c);
		nocolor();
		word = word->next;
	}
	printf("\n");
}

t_word	*word_newletter(char c, int status)
{
	t_word	*letter;

	letter = calloc(1, sizeof(t_word));
	letter->c = c;
	letter->status = status;
	return (letter);
}

void	word_add_back(t_word **alst, t_word *new)
{
	t_word	*last;

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
