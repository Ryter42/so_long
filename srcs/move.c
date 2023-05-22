/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:58:59 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/22 18:16:34 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	ft_haut(t_data *data)
{
	if (verimove(data->stmap->map[data->stmap->y - 1][data->stmap->x],
		data) == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	if (verimove(data->stmap->map[data->stmap->y - 1][data->stmap->x],
		data) == 2)
		data->stmap->items--;
	if (verimove(data->stmap->map[data->stmap->y - 1][data->stmap->x],
		data) > 0)
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

int	ft_bas(t_data *data)
{
	if (verimove(data->stmap->map[data->stmap->y + 1][data->stmap->x],
		data) == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	if (verimove(data->stmap->map[data->stmap->y + 1][data->stmap->x],
		data) == 2)
		data->stmap->items--;
	if (verimove(data->stmap->map[data->stmap->y + 1][data->stmap->x],
		data) > 0)
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

int	ft_gauche(t_data *data)
{
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x - 1],
		data) == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x - 1],
		data) == 2)
		data->stmap->items--;
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x - 1],
		data) > 0)
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

int	ft_droite(t_data *data)
{
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x + 1],
		data) == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x + 1],
		data) == 2)
		data->stmap->items--;
	if (verimove(data->stmap->map[data->stmap->y][data->stmap->x + 1],
		data) > 0)
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
