/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:34:59 by emoreau           #+#    #+#             */
/*   Updated: 2022/11/26 18:14:04 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
			lst = lst->next;
			i++;
	}
	return (i);
}

/*
int		main(void)
{
	t_list elm1;
	t_list elm2;
	t_list elm3;
	
	elm1 = malloc(sizeof(t_list));
	elm2 = malloc(sizeof(t_list));
	elm3 = malloc(sizeof(t_list));

	
	elm1.next = &elm2;
	elm2.next = &elm3;
	elm3.next = NULL;
	printf("%d", ft_lstsize(&elm1));
}
*/
