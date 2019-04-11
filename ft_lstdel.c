/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:45:51 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/11 18:48:25 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return ;
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}
static int ____diddel;
static void    del_test(void *data, size_t i)
{
    (void)data;
    (void)i;
    ____diddel++;
}

int main(void)
{
    t_list    *list;
    int        ft;
    
    ft = 42;
    ____diddel = 0;
    list = malloc(sizeof(t_list));
    bzero(list, sizeof(t_list));
    list->next = malloc(sizeof(t_list));
    bzero(list->next, sizeof(t_list));
    list->content = &ft;
    list->next->content = (&ft) + 1;
    ft_lstdel(&list, del_test);
    if (list == NULL)
    {
        if (____diddel == 2)
        {
            printf("OKAY! =D\n");
            return 0;
        }
    }
    printf("FAILED!\n");
}
