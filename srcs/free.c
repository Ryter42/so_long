/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:47:27 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/22 18:10:06 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_data *data)
{
	if (data->stmap->map)
		free_map(data->stmap->map);
	if (data->stmap->map2)
		free_map(data->stmap->map2);
	if (data->stmap)
		free(data->stmap);
	if (data->image)
		free_image(data);
	if (data->win_ptr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_image(t_data *data)
{
	if (data->image->item)
		mlx_destroy_image(data->mlx_ptr, data->image->item);
	if (data->image->perso)
		mlx_destroy_image(data->mlx_ptr, data->image->perso);
	if (data->image->exit)
		mlx_destroy_image(data->mlx_ptr, data->image->exit);
	if (data->image->mur)
		mlx_destroy_image(data->mlx_ptr, data->image->mur);
	if (data->image->sol)
		mlx_destroy_image(data->mlx_ptr, data->image->sol);
	free(data->image);
}
