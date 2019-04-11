/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:55:56 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/11 17:12:55 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
static void    lstiter_test(t_list *ppp)
{
    ppp->content_size = 42;
}
int    main(void)
{
    t_list    *list;
    
    bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
    bzero(((list->next) = malloc(sizeof(t_list))), sizeof(t_list));
    ft_lstiter(list, lstiter_test);
    
    if (list->content_size == 42)
    {
        if (list->next->content_size == 42)
        {
            printf("OKAY! =D\n");
            return 0;
        }
    }
    printf("FAILED!\n");
}
