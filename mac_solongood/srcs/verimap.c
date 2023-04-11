/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:20:42 by emoreau           #+#    #+#             */
/*   Updated: 2023/04/01 03:00:02 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	itemcheck(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	j = 0;
	c = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	return (c);
}

int	exitcheck(char **map)
{
	int	i;
	int	j;
	int	e;

	i = 1;
	j = 0;
	e = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		j = 0;
		i++;
	}
	return (e);
}

int	startcheck(char **map)
{
	int	i;
	int	j;
	int	p;

	i = 1;
	j = 0;
	p = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		j = 0;
		i++;
	}
	return (p);
}

int	elemchecker(char **map)
{
	if (itemcheck(map) == 0)
		return (-2);
	if (exitcheck(map) != 1)
		return (-3);
	if (startcheck(map) != 1)
		return (-4);
	else
		return (1);
}

int	othercheck(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
