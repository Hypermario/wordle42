/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:08:19 by jmolvaut          #+#    #+#             */
/*   Updated: 2022/05/14 16:38:10 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// FT_PRINTF
int		ft_printf(const char *s, ...);
int		ft_printf_char(int c, int *index);
int		ft_printf_str(char *str, int *index);
int		ft_printf_sint(int d, int *index);
int		ft_printf_hex(const char *s, unsigned long x, int *index);
int		ft_printf_uint(unsigned int u, int *index);
int		ft_void_hex(void *x, int *index);
// --------------

// CONVERTIONS
int		ft_atoi(const char *nptr);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa(int n);
int		ft_strtoi(const char *nptr, char **endptr, int *status);
// --------------

// LINKED LISTS
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
// t_list	*ft_lstdup(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstn(t_list *lst, int n);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
// --------------

// MEMORY
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
// --------------

// WRITE
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbri_base_fd(unsigned int nbr, char *base, int *len, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstri_fd(char *str, int fd);
void	ft_putuli_base_fd(unsigned long nbr, char *base, int *len, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
// --------------

// STR MANIPULATION
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// --------------

// CHECKS
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
// --------------

// LENGTH
size_t	ft_strlen(const char *s);
int		ft_numlen(int n);
int		ft_unumlen(unsigned int n);
int		ft_wordcount(const char *s, char c);
// --------------

// GNL
char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *s, size_t n);
char	*ft_strjoin_gnl(char *s1, char const *s2, size_t n);
void	*ft_memmove_gnl(void *dest, const void *src, size_t n);
// --------------

#endif
