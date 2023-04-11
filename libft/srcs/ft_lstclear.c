/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:38:39 by emoreau           #+#    #+#             */
/*   Updated: 2022/12/02 20:02:39 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
}

/*
int		main(void)
{
	t_list *lst;
	t_list *elm2;
	t_list *elm3;
	t_list *last;
//	t_list *new;

	
	lst = malloc(sizeof(t_list));
	elm2 = malloc(sizeof(t_list));
	elm3 = malloc(sizeof(t_list));
	last = malloc(sizeof(t_list));
	
//	new=malloc(sizeof(t_list));
	lst->next = elm2;
	elm2->next = elm3;
	elm3->next = last;
	last->next = NULL;
	

	lst->content=(int *)malloc(sizeof(int));
	elm2->content=(int *)malloc(sizeof(int));
	elm3->content=(int *)malloc(sizeof(int));
	last->content=(int *)malloc(sizeof(int));
	
	*((int *)(lst->content)) = 1;
	*((int *)(elm2->content)) = 2;
	*((int *)(elm3->content)) = 3;
	*((int *)(last->content)) = 4;

	ft_lstclear(elm3, (*del));
	printf("il y a %d element\n", ft_lstsize(&lst));
//	last = ft_lstlast(lst);
	printf("BEGIN : %d\n", *(int *)(lst->content));
	printf("LAST : %d\n", *(int *)(last->content));
//	ft_lstadd_back(&lst, new);

//	printf("MTN BEGIN: %d\n", *(int *)(lst->content));
	

}
*/