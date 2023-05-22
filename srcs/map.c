/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:27:06 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/22 18:27:59 by emoreau          ###   ########.fr       */
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
		if (str[0] == '\n' || (str[i] == '\n' && str[i + 1] == '\n'))
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
	str = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		str = ft_gnl_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (backslashmap(str) == 0)
		return (free(str), NULL);
	map = ft_split(str, '\n');
	close(fd);
	free(str);
	return (map);
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
