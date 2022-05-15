/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:21:35 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 15:17:40 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

/*
**	Check le status de chaque lettres entre data->fullword et input
**	renvois true ou false
*/
bool	word_check(t_data *data)
{
	const char	*word = data->fullword;
	int			i;
	int			correct;

	i = 0;
	correct = 0;
	while (word[i])
	{
		if (word[i] == data->in[i])
			correct++;
		i++;
	}
	if (correct == 5)
		return (true);
	return (false);
}
