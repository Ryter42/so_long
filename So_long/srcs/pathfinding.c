/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:27:43 by emoreau           #+#    #+#             */
/*   Updated: 2023/04/01 00:28:53 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**pathfinding(char **map, int x, int y)
{
	while (around(map, x, y) == 1)
	{
		changemap(&map[y + 1][x]);
		changemap(&map[y - 1][x]);
		changemap(&map[y][x + 1]);
		changemap(&map[y][x - 1]);
		if (map[y][x + 1] == 'x')
			pathfinding(map, x + 1, y);
		if (map[y][x - 1] == 'x')
			pathfinding(map, x - 1, y);
		if (map[y + 1][x] == 'x')
			pathfinding(map, x, y + 1);
		if (map[y - 1][x] == 'x')
			pathfinding(map, x, y - 1);
	}
	return (map);
}

int	verexit(char **map, int x, int y)
{
	if (map[y + 1][x] == 'x' || map[y][x + 1] == 'x' || map[y - 1][x] == 'x'
		|| map[y][x - 1] == 'x')
		return (1);
	else
		return (0);
}

int	pathexit(char **map)
{
	if (verexit(map, colonechr(map[linechr(map)]), linechr(map)) == 0)
		return (0);
	else
		return (1);
}

int	veripath(char **map)
{
	if (itemcheck(map) != 0 || pathexit(map) == 0)
		return (0);
	else
		return (1);
}

int	path(t_data *data)
{
	int		x;
	int		y;
	char	**pathmap;

	x = data->stmap->x;
	y = data->stmap->y;
	pathmap = pathfinding(data->stmap->map2, x, y);
	// ft_printf("---pathmap___\n\n");
	// while (*pathmap)
	// {
	// 	ft_printf("%s\n", *pathmap);
	// 	pathmap++;
	// }
	
	// ft_printf("\n\n---pathmap---");
	return (veripath(pathmap));
}
