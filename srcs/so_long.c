/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:37:03 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/22 18:26:55 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	errormessage(int m)
{
	if (m == 1)
		ft_printf("erreur lors du chargement de la map");
	if (m == -1)
		ft_printf("la map n'est pas rectangulaire");
	if (m == -2)
		ft_printf("il n'y a rien a recolter");
	if (m == -3)
		ft_printf("ou est la sortie ?");
	if (m == -4)
		ft_printf("ou suis - je ?");
	if (m == -5)
		ft_printf("pas de chemins possible");
	if (m == 2)
		ft_printf("trop ou pas assez d'argument");
	if (m == -6)
		ft_printf("il y a un caractere bizare la non ?");
}

int	main(int argc, char **argv)
{
	int		error;
	t_data	*data;

	if (argc != 2)
		return (errormessage(2), 0);
	if (structinit(&data, argv[1]) == 0)
		return (free_all(data), errormessage(1), 0);
	error = mapchecker(data);
	if (error < 0)
		return (free_all(data), errormessage(error), 0);
	mlx(data);
	free_all(data);
}
