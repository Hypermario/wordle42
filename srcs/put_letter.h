/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_letter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:36:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/15 12:53:46 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_LETTER_H
# define PUT_LETTER_H

# define PAD_WORDS_LEFT 200
# define PAD_WORDS_TOP 400
# define PAD_BETWEEN_WORDS 20
# define PAD_BETWEEN_LETTERS 10

# define PATH_LETTER_TEMPLATE "ressources/letters_xpm/XX.xpm"
# define PATH_LETTER_I_LETTER 23
# define PATH_LETTER_I_STATE 24
# define PATH_LETTER_EMPTY "ressources/letters_xpm/empty.xpm"

enum states
{
	STATE_WRITTEN;
	STATE_VALID;
	STATE_IN_WRONG_PLACE;
	STATE_NOT_IN_WORD;
};

#endif
