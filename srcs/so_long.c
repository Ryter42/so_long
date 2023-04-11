/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:37:03 by emoreau           #+#    #+#             */
/*   Updated: 2023/04/11 18:06:36 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	namemap(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i - 3] != '.' || str[i - 2] != 'b' || str[i - 1] != 'e'
		|| str[i] != 'r')
		return (0);
	else
		return (1);
}

int	backslashmap(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	**get_map(char *file)
{
	char	**map;
	char	*tmp;
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1 || namemap(file) == 0)
		return (NULL);
	// if(namemap(file) == 0)
	// 	return (NULL);
	str = get_next_line(fd);
	tmp = get_next_line(fd);
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (backslashmap(str) == 0)
		return (NULL);
	map = ft_split(str, '\n');
	close(fd);
	return (map);
}

void	printmap(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->stmap->map[i])
	{
		while (data->stmap->map[i][j])
		{
			ft_printf("%c", data->stmap->map[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_printf("\n");
	}
}

int	mapchecker(t_data *data)
{
	int	len;

	len = lenmap(data->stmap->map);
	if (borchecker(data->stmap->map, len) == 0)
		return (-1);
	if (elemchecker(data->stmap->map) < 0)
		return (elemchecker(data->stmap->map));
	if (othercheck(data->stmap->map) == 0)
		return (-6);
	if (path(data) == 0)
		return (-5);
	else
		return (1);
}

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
		ft_printf("ily a un caractere bizare la non ?");
	// 	if (m == 1)
	// 		ft_printf("c'est good");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (errormessage(2), 0);
	if (structinit(&data, argv[1]) == 0)
		return (errormessage(1), 0);
	printmap(data);
	if (mapchecker(data) < 0)
		return (errormessage(mapchecker(data)), 0);
	mlx(data);
}

// while (data->stmap->map[i])
// {
// 	free(data->stmap->map[i]);
// 	i++;
// }
// free(data->stmap->map);
// free(data->stmap);
// free(data);

// t_img	*img;
// int		img_width;
// int		img_height;

// while (1)
// mlx_destroy_window(mlx_ptr, win_ptr);
// mlx_destroy_display(mlx_ptr);
// free(mlx_ptr);

// render
// 	x, y;

// 	while map[y]
// 		while map[y][x]
// 			afficher image position x * SIZE y * SIZE