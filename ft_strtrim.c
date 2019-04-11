/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:10:29 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/09 16:11:34 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wsp(char const c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*r;
	int		i;
	int		k;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = -1;
	while (ft_wsp(s[++j]))
		i++;
	while (s[j++])
		k = ft_wsp(s[j - 1]) ? k + 1 : 0;
	r = ft_strnew(ft_strlen(s) - i - k);
	if (!r)
		return (NULL);
	return (ft_strncpy(r, s + i, ft_strlen(s) - k - i));
}
