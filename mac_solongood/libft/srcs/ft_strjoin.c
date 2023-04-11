/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:14:21 by emoreau           #+#    #+#             */
/*   Updated: 2022/11/24 14:17:32 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;

	i = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(sizeof(char) * i + 1);
	if (!s)
		return (NULL);
	while (*s1)
	{
		*s = *s1;
		s++;
		s1++;
	}
	while (*s2)
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = 0;
	return (s - i);
}

/*
int main(void)
{
	char s[] = "salut ";
	char c[] = "les conp";
	printf("%s\n", ft_strjoin(s, c));
	return (0);
}*/