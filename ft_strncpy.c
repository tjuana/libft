/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:01:54 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/05 15:52:32 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t ind;

	ind = 0;
	while (src[ind] != '\0' && ind < len)
	{
		dst[ind] = src[ind];
		ind++;
	}
	while (ind < len)
	{
		dst[ind] = '\0';
		ind++;
	}
	return (dst);
}
