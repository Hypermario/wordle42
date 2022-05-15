/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:25:25 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/15 13:38:50 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include "mlx.h"
# include "libft.h"


# define HEIGHT			1080
# define WIDTH			1080
# define MLX_ERROR		1

# define PAD_WORDS_LEFT WIDTH / 4
# define PAD_WORDS_TOP HEIGHT / 8
# define PAD_BETWEEN_WORDS 20
# define PAD_BETWEEN_LETTERS 10

// COLORS
enum colors
{
	BLACK	= 0x000000,
	WHITE	= 0xFFFFFF,
	RED		= 0xFF0000,
	GREEN	= 0x00FF00,
	BLUE	= 0x0000FF,
	ABSENT	= 0x3A3A3C,
	PRESENT	= 0xB59F3B,
	CORRECT	= 0x538D4E
};

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_word
{
	char			c;
	int				status;
	struct s_word	*next;
}	t_word;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*fullword;
	int		iw;
	int		il;
	int		tries;
	char	*file;
	char	*in;
	bool	correct;
	bool	finished;
	t_word	*word[6];
	t_img	img;
}	t_data;

/*
**	RENDER
*/
void	img_pixel_put(t_img *img, int x, int y, int color);
int		create_image(t_data *data);
int		render_next_frame(t_data *data);

/*
**	DICTIONARY
*/
int		dict_random_word(char *file, t_data *data);
bool	dict_check(t_data *data, char *in);

/*
**	EVENTS
*/
int		handle_keypress(int keysym, t_data *data);
int		handle_closing(t_data *data);

/*
**	WORD
*/
void	word_check(t_data *data, char *input);
t_word	*word_newletter(char c, int status);
void	word_add_back(t_word **alst, t_word *new);
void	word_print(t_word *word);

/*
**  RENDER LETTER
*/
int	erase_letter(t_data *data);
int	put_letter(t_data *data, char c, int state);
int	write_letter(t_data *data, char c);
int	validate_letters(t_data *data);

/*
**	UTILS
*/
void	free_split(char	**split);
void	free_data(t_data data);
char	*line_wrapper(char *line);

#endif
