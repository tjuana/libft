/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:20:21 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/09 19:05:22 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, int i, char c)
{
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s == c)
			s++;
		i++;
	}
	return (i);
}

static int	ft_fwords(char const *s, int i, char c, char **res)
{
	int l;
	int j;

	l = 0;
	j = 0;
	while (*s == c)
	{
		s++;
		j++;
	}
	while (s[l] && s[l] != c)
		l++;
	if (l > 0)
	{
		res[i] = ft_strnew(l);
		ft_strncpy(res[i], s, l);
	}
	return (j + l);
}

char		**ft_strsplit(char const *s, char c)
{
	int		l;
	int		i;
	int		cw;
	char	**res;

	if (!s)
		return (NULL);
	l = 0;
	i = 0;
	cw = ft_count_words(s, 0, c);
	if (!(res = (char **)ft_memalloc((cw + 1) * sizeof(char *))))
		return (NULL);
	while (*s)
	{
		l = ft_fwords(s, i++, c, res);
		s += l;
	}
	res[cw] = 0;
	return (res);
}
