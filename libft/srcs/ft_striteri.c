/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolvaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:31:14 by jmolvaut          #+#    #+#             */
/*   Updated: 2021/12/06 17:33:48 by jmolvaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
void	nextchar(unsigned int i, char *s)
{
	s = i + '0';
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, (s + i));
		i++;
	}
}
/*
int	main()
{
	void	(*f)(unsigned int, char*);
	char	*s = "TEST";

	f = &nextchar;
	ft_striteri(s, f);
	printf("%s", s);
}
*/
