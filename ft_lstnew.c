/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:59:03 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/11 18:45:14 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if ((list->content = ft_memalloc(content_size)) == NULL)
		{
			free(list);
			return (NULL);
		}
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
int	main(void)
{
	t_list	*list;
	int 	ft;

	ft = 42;
	list = ft_lstnew(&ft, sizeof(int));
	if (!!list)
	{
		if ((*(int*)(list->content)) == 42)
		{
			list = ft_lstnew(NULL, 386);
			if ((list->content_size) == 0)
			{
				printf("OKAY! =D\n");
				return (0);;
			}
		}
	}
	printf("FAILED!\n");
	return (0);
}
