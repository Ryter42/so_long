/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:07:19 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/22 16:57:26 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	putimg(t_data *data, char c, int x, int y)
{
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->image->perso, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image->exit,
				x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image->item,
				x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image->sol,
				x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image->mur,
				x * 64, y * 64);
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
int	verimove(char c, t_data *data)
{
	if (c == '0')
		return (1);
	else if (c == 'C')
		return (2);
	else if (c == 'E' && data->stmap->items == 0)
		return (0);
	else 
		return (-1);
}

// void ft_haut(t_data *data)
// {
// 	if (verimove(data->stmap->map[data->stmap->y + 1][data->stmap->x] data) == 1)
// 	{
// 		data->stmap->map[data->stmap->y - 1][data->stmap->x] = 'P';
// 		data->stmap->map[data->stmap->y][data->stmap->x] = 0;
// 		data->stmap->y--;
// 	}
// 	else if (verimove(data->stmap->map[data->stmap->y - 1][data->stmap->x] data) == 2)
// 	{
// 		data->stmap->map[data->stmap->y - 1][data->stmap->x] = 'P';
// 		data->stmap->map[data->stmap->y][data->stmap->x] = 0;
// 		data->stmap->y--;
// 		(*data)->stmap->items--;
// 	}
// }

int ft_haut(t_data *data)
{
	// if (verimove(data->stmap->map[data->stmap->y - 1][data->stmap->x] data) == 0)
	// 	return ;
	if (verimove(data->stmap->map[data->stmap->y - 1][data->stmap->x], data) == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	if (verimove(data->stmap->map[data->stmap->y - 1][data->stmap->x], data) == 2)
		data->stmap->items--;
	if (verimove(data->stmap->map[data->stmap->y - 1][data->stmap->x], data) > 0)
	{
		data->stmap->map[data->stmap->y - 1][data->stmap->x] = 'P';
		data->stmap->map[data->stmap->y][data->stmap->x] = '0';
		data->stmap->y--;
		data->nbr_move++;
		ft_printf("%d\n", data->nbr_move);
	}	
	chargewindow(data);
	return (1);
}

int ft_bas(t_data *data)
{
	if (verimove(data->stmap->map[data->stmap->y + 1][data->stmap->x], data) == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	if (verimove(data->stmap->map[data->stmap->y + 1][data->stmap->x], data) == 2)
		data->stmap->items--;
	if (verimove(data->stmap->map[data->stmap->y + 1][data->stmap->x], data)> 0)
	{
		data->stmap->map[data->stmap->y + 1][data->stmap->x] = 'P';
		data->stmap->map[data->stmap->y][data->stmap->x] = '0';
		data->stmap->y++;
		data->nbr_move++;
		ft_printf("%d\n", data->nbr_move);
	}
	chargewindow(data);
	return (1);
}

int ft_gauche(t_data *data)
{
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x - 1], data) == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x - 1], data) == 2)
		data->stmap->items--;
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x - 1], data) > 0)
	{
		data->stmap->map[data->stmap->y][data->stmap->x - 1] = 'P';
		data->stmap->map[data->stmap->y][data->stmap->x] = '0';
		data->stmap->x--;
		data->nbr_move++;
		ft_printf("%d\n", data->nbr_move);
	}
	chargewindow(data);
	return (1);
}

int ft_droite(t_data *data)
{
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x + 1], data) == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x + 1], data) == 2)
		data->stmap->items--;
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x + 1], data) > 0)
	{
		data->stmap->map[data->stmap->y][data->stmap->x + 1] = 'P';
		data->stmap->map[data->stmap->y][data->stmap->x] = '0';
		data->stmap->x++;
		data->nbr_move++;
		ft_printf("%d\n", data->nbr_move);
	}
	chargewindow(data);
	return (1);
}


int	touch(int keycode, t_data *data)
{
	if (keycode == 65307)
		mlx_loop_end(data->mlx_ptr);
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
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->stmap->c * 64,
			data->stmap->l * 64, "So_long");
		
	chargeimage(data);
	chargewindow(data);
	mlx_hook(data->win_ptr, 17, 0, mlx_loop_end, data->mlx_ptr);
	mlx_key_hook(data->win_ptr, &touch, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}


/*
haut = 119
bas = 115
gauche = 97
droit = 100
haut = 65362
bas = 65364
gauche = 65361
droit = 65363
*/