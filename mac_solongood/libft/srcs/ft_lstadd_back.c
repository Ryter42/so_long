/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:04:18 by emoreau           #+#    #+#             */
/*   Updated: 2022/12/28 19:10:40 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

/*
int		main(void)
{
	t_list *lst;
	t_list *elm2;
	t_list *elm3;
	//t_list *last;
	t_list *new;

	
	lst=malloc(sizeof(t_list));
	elm2=malloc(sizeof(t_list));
	elm3=malloc(sizeof(t_list));
	new=malloc(sizeof(t_list));
	lst->next = elm2;

	elm2->next = elm3;
	elm3->next = NULL;

	lst->content=(int *)malloc(sizeof(int));
	elm2->content=(int *)malloc(sizeof(int));
	elm3->content=(int *)malloc(sizeof(int));
	new->content=(int *)malloc(sizeof(int));
	
	*((int *)(lst->content))=1;
	*((int *)(elm2->content))=2;
	*((int *)(elm3->content))=3;
	*((int *)(new->content))=40;
	//printf("%d\n", ft_lstsize(&lst));
	//last = ft_lstlast(lst);
	printf("%d\n", *(int *)(lst->content));
	//printf("LAST: %d\n", *(int *)(last->content));
	ft_lstadd_back(&lst, new);

	printf("MTN BEGIN: %d\n", *(int *)(lst->content));
	
	
}
*/