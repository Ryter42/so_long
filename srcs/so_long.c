/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:37:03 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/21 19:27:33 by emoreau          ###   ########.fr       */
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
		if (str [0] == '\n' || (str[i] == '\n' && str[i + 1] == '\n'))
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
		return (free (str), NULL);
	map = ft_split(str, '\n');
	close(fd);
	free(str);
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
	// printmap(data);
	if (mapchecker(data) < 0)
		return (errormessage(mapchecker(data)), 0);
	mlx(data);
	free_all(data);
}


void free_all(t_data *data)
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