/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:34:05 by emoreau           #+#    #+#             */
/*   Updated: 2023/04/01 03:38:47 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	xplace(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (j);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	yplace(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	structinit(t_data **data, char *file)
{
	(*data) = malloc(sizeof(t_data));
	if (!data)
		return (0);
	(*data)->stmap = malloc(sizeof(t_map));
	if (!(*data)->stmap)
		return (0);
	(*data)->stmap->map = get_map(file);
	if (!(*data)->stmap->map)
		return (0);
	(*data)->stmap->map2 = get_map(file);
	(*data)->stmap->l = lenmap((*data)->stmap->map);
	(*data)->stmap->c = ft_strlen((*data)->stmap->map[0]);
	(*data)->stmap->x = xplace((*data)->stmap->map);
	(*data)->stmap->y = yplace((*data)->stmap->map);
	return (1);
}
