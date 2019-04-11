/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:59:23 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/11 18:47:57 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return ;
	if (*alst)
		new->next = *alst;
	*alst = new;
}
int	main(void)
{
	t_list	*list;
	t_list	*list2;

	list = malloc(sizeof(t_list));
	list2 = malloc(sizeof(t_list));
	bzero(list, sizeof(t_list));
	bzero(list2, sizeof(t_list));
	ft_lstadd(&list2, list);
	if (list == list2)
	{
		if (list->next != NULL)
		{
			printf("OKAY! =D\n");
			return 0;
		}
	}
	printf("FAILED!\n");
}
