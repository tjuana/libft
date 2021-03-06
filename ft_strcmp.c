/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:33:27 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/24 15:47:43 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((t_byte)s1[i] - (t_byte)s2[i]);
	/*t_byte *s0;
	t_byte *s3;

	s0 = (t_byte*)s1;
	s3 = (t_byte*)s2;

	while (*s0 == *s3)
	{
		if (*s0 == '\0')
			return (0);
		s0++;
		s3++;
	}
	return ((unsigned int)(*s0 - *s3));*/
}
