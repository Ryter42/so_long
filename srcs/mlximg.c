/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:07:19 by emoreau           #+#    #+#             */
/*   Updated: 2023/04/11 18:07:52 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	putimg(t_data *data, char c, int x, int y)
{
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->image->perso, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->image->exit, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->image->item, x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->image->sol, x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->image->mur, x * 64, y * 64);
	return (0);
}

int	chargewindow(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	chargeimage(data);
	while (data->stmap->map[i])
	{
		while (data->stmap->map[i][j])
		{
			putimg(data, data->stmap->map[i][j], j, i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void touch(int i)
{
	printf("key = %d\n", i);
}

int	mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->stmap->c * 64, data->stmap->l * 64, "so_long");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		return (0);
	}
	chargewindow(data);
	mlx_hook(data->win_ptr, 17, 0, mlx_loop_end, data->mlx_ptr);
	mlx_key_hook(data->win_ptr, touch, 0);
	mlx_loop(data->mlx_ptr);
	return (0);
}

void	clearmlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}