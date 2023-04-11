/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:31:22 by emoreau           #+#    #+#             */
/*   Updated: 2023/04/01 02:55:19 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	charverif(char c)
{
	if (c == '0' || c == 'C')
		return (0);
	else
		return (1);
}

void	changemap(char *map)
{
	if (charverif(*map) == 0)
		*map = 'x';
}

int	around(char **map, int x, int y)
{
	if (charverif(map[y + 1][x]) == 1 && charverif(map[y][x + 1]) == 1
		&& charverif(map[y - 1][x]) == 1 && charverif(map[y][x - 1]) == 1)
		return (0);
	else
		return (1);
}

int	colonechr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 'E')
		i++;
	return (i);
}

int	linechr(char **str)
{
	int		i;

	i = 0;
	while (ft_strchr(str[i], 'E') == NULL)
		i++;
	return (i);
}
