/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:01:05 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/07 17:57:51 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int is;
	int itf;

	is = 0;
	itf = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[is] != '\0')
	{
		itf = 0;
		while (haystack[is + itf] != '\0' && haystack[is + itf] == needle[itf])
		{
			if (needle[itf + 1] == '\0')
				return ((char*)&haystack[is]);
			itf++;
		}
		is++;
	}
	return (0);
}
