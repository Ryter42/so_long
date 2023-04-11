/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:34:05 by emoreau           #+#    #+#             */
/*   Updated: 2023/04/11 18:15:09 by emoreau          ###   ########.fr       */
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

int	chargeimage(t_data *data)
{
	int	a;

	data->image->perso = mlx_xpm_file_to_image(data->mlx_ptr,
			"./XPM/player.xpm", &a, &a);
	data->image->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./XPM/panier.xpm",
			&a, &a);
	data->image->item = mlx_xpm_file_to_image(data->mlx_ptr,
			"./XPM/ballon.xpm", &a, &a);
	data->image->mur = mlx_xpm_file_to_image(data->mlx_ptr, "./XPM/feu.xpm",
			&a, &a);
	data->image->sol = mlx_xpm_file_to_image(data->mlx_ptr, "./XPM/sol.xpm",
			&a, &a);
	return (1);
}

int	structinit(t_data **data, char *file)
{
	(*data) = malloc(sizeof(t_data));
	if (!data)
		return (0);
	(*data)->stmap = malloc(sizeof(t_map));
	if (!(*data)->stmap)
		return (0);
	(*data)->image = malloc(sizeof(t_image));
	if (!(*data)->image)
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
