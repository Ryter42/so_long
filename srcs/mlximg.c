/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:07:19 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/22 19:47:59 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	putimg(t_data *data, char c, int x, int y)
{
	if (c == 'P')
		mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
			data->mlx->image->perso, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
			data->mlx->image->exit, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
			data->mlx->image->item, x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
			data->mlx->image->sol, x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
			data->mlx->image->mur, x * 64, y * 64);
	return (0);
}

int	chargewindow(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

int	touch(int keycode, t_data *data)
{
	if (keycode == 65307)
		mlx_loop_end(data->mlx->mlx_ptr);
	if (keycode == 119 || keycode == 65362)
		ft_haut(data);
	if (keycode == 115 || keycode == 65364)
		ft_bas(data);
	if (keycode == 97 || keycode == 65361)
		ft_gauche(data);
	if (keycode == 100 || keycode == 65363)
		ft_droite(data);
	return (0);
}

int	mlx(t_data *data)
{
	data->mlx->mlx_ptr = mlx_init();
	if (!data->mlx->mlx_ptr)
		exit(EXIT_FAILURE);
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, data->stmap->c * 64,
			data->stmap->l * 64, "So_long");
	chargeimage(data);
	chargewindow(data);
	mlx_hook(data->mlx->win_ptr, 17, 0, mlx_loop_end, data->mlx->mlx_ptr);
	mlx_key_hook(data->mlx->win_ptr, &touch, data);
	mlx_loop(data->mlx->mlx_ptr);
	return (0);
}
