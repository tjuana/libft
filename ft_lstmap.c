/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:13:38 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/11 18:52:24 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list    *lstmap_test_fn(t_list *list)
{
    t_list    *l2;
    
    l2 = malloc(sizeof(t_list));
    bzero(l2, sizeof(t_list));
    l2->content = malloc(list->content_size * 2);
    l2->content_size = list->content_size * 2;
    return (l2);
}
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst1;

	if (lst)
	{
		lst1 = f(lst);
		lst1->next = ft_lstmap(lst->next, f);
		return (lst1);
	}
	return (NULL);
}
int    main(void)
{
    t_list    *list;
    t_list    *map;
    
    bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
    bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
    list->content_size = 21;
    list->content = strdup("abc");
    list->next->content_size = 100;
    list->next->content = strdup("abc");
    map = ft_lstmap(list, lstmap_test_fn);
    if (list->content_size == 21)
    {
        if (list->next->content_size == 100)
        {
            if (!!map && map->content_size == 42)
            {
                if (!!map && map->next->content_size == 200)
                {
                    printf("OKAY! =D\n");
                    return 0;
                }
            }
        }
    }
    printf("FAILED!\n");
}
