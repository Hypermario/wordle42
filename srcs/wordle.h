/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:59:47 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/15 16:17:18 by rgarrigo         ###   ########.fr       */
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


# define WIDTH_WORDLE	720
# define WIDTH_CONSOLE	320
# define WIDTH			(WIDTH_WORDLE + WIDTH_CONSOLE)
# define HEIGHT			960
# define MLX_ERROR		1

# define PAD_ERASE_LEFT 140
# define PAD_ERASE_TOP 140
# define PAD_WORDS_LEFT (WIDTH_WORDLE / 8)
# define PAD_WORDS_TOP (HEIGHT / 5)
# define PAD_BETWEEN_WORDS 20
# define PAD_BETWEEN_LETTERS 10
# define PAD_CONSOLE_LEFT (WIDTH_WORDLE + 20)
# define PAD_CONSOLE_TOP 20

# define CONSOLE_MAX_LINES 5
# define CONSOLE_SIZE_FONT 30
# define CONSOLE_LINE_CHARS_MAX 20

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

typedef struct s_data
{
	void*	mlx;
	void	*win;
	char	*fullword;
	int		iw;
	int		il;
	int		iconsole;
	int		tries;
	char	*file;
	char	*in;
	time_t	lasterror;
	bool	correct;
	bool	finished;
	t_img	img;
}	t_data;

/*
**	RENDER
*/
int		init_display(t_data *data);
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
bool	word_check(t_data *data);

/*
**  RENDER LETTER
*/
int	erase_letter(t_data *data);
int	put_letter(t_data *data, char c, int state);
int	write_letter(t_data *data, char c);
int	validate_letters(t_data *data);

/*
**  CONSOLE
*/
int	printf_console(t_data *data, char *format, ...);

/*
**	UTILS
*/
void	free_split(char	**split);
void	free_data(t_data *data);
char	*line_wrapper(char *line);

#endif
