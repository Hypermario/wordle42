/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_letter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:36:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/15 13:32:19 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_LETTER_H
# define PUT_LETTER_H

# define PATH_LETTER_TEMPLATE "ressources/letters_xpm/XX.xpm"
# define PATH_LETTER_I_LETTER 23
# define PATH_LETTER_I_STATE 24
# define PATH_LETTER_EMPTY "ressources/letters_xpm/empty.xpm"

enum states
{
	STATE_WRITTEN,
	STATE_VALID,
	STATE_IN_WRONG_PLACE,
	STATE_NOT_IN_WORD
};

#endif
