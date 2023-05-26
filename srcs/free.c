/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:47:27 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/22 19:44:25 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_data *data)
{
	if (!data)
		return ;
	if (data->stmap)
	{
		if (data->stmap->map)
			free_map(data->stmap->map);
		if (data->stmap->map2)
			free_map(data->stmap->map2);
		free(data->stmap);
	}
	if (data->mlx)
		free_mlx(data);
	free(data);
}

void	free_mlx(t_data *data)
{
	if (data->mlx->image)
		free_image(data);
	if (data->mlx->win_ptr)
	{
		mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	}
	if (data->mlx->mlx_ptr)
	{
		mlx_destroy_display(data->mlx->mlx_ptr);
		free(data->mlx->mlx_ptr);
	}
	free(data->mlx);
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
	if (data->mlx->image->item)
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->image->item);
	if (data->mlx->image->perso)
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->image->perso);
	if (data->mlx->image->exit)
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->image->exit);
	if (data->mlx->image->mur)
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->image->mur);
	if (data->mlx->image->sol)
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->image->sol);
	free(data->mlx->image);
}
