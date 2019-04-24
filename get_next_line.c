/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:09:41 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/24 16:25:16 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*c[2147483647];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		b;
	int			endl;

	if (fd < 0 || (!*(c + fd) && !(*(c + fd) = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(*(c + fd), '\n') && (b = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		*(buffer + b) = '\0';
		tmp = *(c + fd);
		*(c + fd) = ft_strjoin(*(c + fd), buffer);
		ft_strdel(&tmp);
	}
	if (b == -1 || !*(tmp = *(c + fd)))
		return (b == -1 ? -1 : 0);
	if ((endl = (ft_strchr(*(c + fd), '\n') > 0)))
		*line = ft_strsub(*(c + fd), 0, ft_strchr(*(c + fd), '\n') - *(c + fd));
	else
		*line = ft_strdup(*(c + fd));
	*(c + fd) = ft_strsub(*(c + fd), (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(*(c + fd)) - (ft_strlen(*line) + endl)));
	ft_strdel(&tmp);
	return (!(!*(c + fd) && !ft_strlen(*line)));
}
