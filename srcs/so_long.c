/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:37:03 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/22 20:00:02 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv, char **envp)
{
	int		error;
	t_data	*data;

	if (!*envp)
		return (errormessage(1), 0);
	if (argc != 2)
		return (errormessage(2), 0);
	if (structinit(&data, argv[1]) == 0)
		return (ft_free(data), errormessage(3), 0);
	error = mapchecker(data);
	if (error < 0)
		return (ft_free(data), errormessage(error), 0);
	mlx(data);
	return (ft_free(data), 0);
}

void	errormessage(int m)
{
	if (m == 1)
		ft_printf("Error\nNo Environment\n");
	if (m == 2)
		ft_printf("Error\nTrop ou pas assez d'argument");
	if (m == 3)
		ft_printf("Error\nChargement de la map");
	if (m == -1)
		ft_printf("Error\nLa map n'est pas rectangulaire");
	if (m == -2)
		ft_printf("Error\nIl n'y a rien a recolter");
	if (m == -3)
		ft_printf("Error\nOu est la sortie ?");
	if (m == -4)
		ft_printf("Error\nOu suis - je ?");
	if (m == -5)
		ft_printf("Error\nPas de chemins possible");
	if (m == -6)
		ft_printf("Error\nIl y a un caractere bizare la non ?");
}
