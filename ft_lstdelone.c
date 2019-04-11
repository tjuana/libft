/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:26:01 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/11 19:24:21 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int ____diddel;
static void    del_test(void *data, size_t i)
{
    (void)data;
    (void)i;
    ____diddel++;
}
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return ;
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
int    main(void)
{
    t_list    *list;
    int        ft;
    
    ____diddel = 0;
    ft = 42;
    list = (t_list *)malloc(sizeof(t_list));
    list->content = &ft;
    list->content_size = sizeof(int);
    ft_lstdelone(&list, del_test);
    if (list == NULL)
    {
        if (____diddel == 1)
        {
            printf("OKAY! =D\n");
            return 0;
        }
    }
    printf("FAILED!\n");
}

