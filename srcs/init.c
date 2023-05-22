/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:34:05 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/22 18:11:15 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_position(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (data->stmap->map[i])
	{
		j = 1;
		while (data->stmap->map[i][j])
		{
			if (data->stmap->map[i][j] == 'P')
			{
				data->stmap->x = j;
				data->stmap->y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	chargeimage(t_data *data)
{
	int	a;

	data->image->perso = mlx_xpm_file_to_image(data->mlx_ptr,
			"./XPM/basketeur.xpm", &a, &a);
	data->image->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./XPM/panier.xpm",
			&a, &a);
	data->image->item = mlx_xpm_file_to_image(data->mlx_ptr,
			"./XPM/ballon.xpm", &a, &a);
	data->image->mur = mlx_xpm_file_to_image(data->mlx_ptr, "./XPM/arbre.xpm",
			&a, &a);
	data->image->sol = mlx_xpm_file_to_image(data->mlx_ptr, "./XPM/sol.xpm",
			&a, &a);
	return (1);
}

void	nullinit(t_data **data)
{
	(*data)->mlx_ptr = NULL;
	(*data)->win_ptr = NULL;
	(*data)->image->perso = NULL;
	(*data)->image->exit = NULL;
	(*data)->image->item = NULL;
	(*data)->image->mur = NULL;
	(*data)->image->sol = NULL;
	(*data)->stmap->map2 = NULL;
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
	nullinit(data);
	(*data)->stmap->map = get_map(file);
	if (!(*data)->stmap->map)
		return (0);
	(*data)->stmap->map2 = get_map(file);
	(*data)->stmap->l = lenmap((*data)->stmap->map);
	(*data)->stmap->c = ft_strlen((*data)->stmap->map[0]);
	get_position(*data);
	(*data)->stmap->items = itemcheck((*data)->stmap->map);
	(*data)->nbr_move = 0;
	return (1);
}
