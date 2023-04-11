/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:23:24 by emoreau           #+#    #+#             */
/*   Updated: 2023/04/01 03:09:41 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	lenmap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	linecheck(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' || str2[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	colonecheck(char **map, int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return (0);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	sizecheck(char **map, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (ft_strlen(map[i - 1]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (ft_strlen(map[i - 1]));
}

int	borchecker(char **map, int len)
{
	if (linecheck(*map, map[len - 1]) == 0)
		return (0);
	// if (sizecheck(**map, len) == 0)
	// 	return (0);
	if (colonecheck(map, sizecheck(map, len)) == 0)
		return (0);
	else
		return (1);
}
