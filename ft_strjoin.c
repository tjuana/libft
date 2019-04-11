/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:03:10 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/09 16:05:42 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*res;

	if (s1 && s2)
		size = (size_t)(ft_strlen((s1) + ft_strlen(s2)));
	else if (s1)
		size = (size_t)(ft_strlen(s1));
	else if (s2)
		size = (size_t)(ft_strlen(s2));
	else
		return (NULL);
	if (!(res = ft_memalloc(size)))
		return (NULL);
	if (s1)
		res = ft_strcpy(res, s1);
	else
		res = ft_strcpy(res, s2);
	if (s1 && s2)
		res = ft_strcat(res, s2);
	return (res);
}
