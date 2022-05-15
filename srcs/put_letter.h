/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_letter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:36:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/15 11:46:33 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_LETTER_H
# define PUT_LETTER_H

# define PAD_WORDS_LEFT 200
# define PAD_WORDS_TOP 400
# define PAD_BETWEEN_WORDS 20
# define PAD_BETWEEN_LETTERS 10

# define PATH_LETTER_TEMPLATE
# define PATH_LETTER_I_LETTER
# define PATH_LETTER_I_STATE

enum states
{
	STATE_WRITTEN;
	STATE_VALID;
	STATE_IN_WRONG_PLACE;
	STATE_NOT_IN_WORD;
};

#endif
