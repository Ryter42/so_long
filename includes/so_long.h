/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 00:54:22 by emoreau           #+#    #+#             */
/*   Updated: 2023/04/11 18:00:22 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
# include "../libft/includes/libft.h"
# include "../mlx/mlx_int.h"
# include "../mlx/mlx.h"
// # include "../printf/ft_printf.h"
// # include "../mlx_linux/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	char	**map2;
	int		l;
	int		c;
	int		x;
	int		y;
	int		items;
}			t_map;

typedef struct s_image
{
	void	*mur;
	void	*exit;
	void	*item;
	void	*perso;
	void	*sol;
	
}	t_image;

typedef struct s_data
{
	t_map	*stmap;
	t_image	*image;
	void	*mlx_ptr;
	void	*win_ptr;
	
}			t_data;

int			path(t_data *data);
int			lenmap(char **map);
int			linecheck(char *str, char *str2);
int			colonecheck(char **map, int len);
int			sizecheck(char **map, int len);
int			borchecker(char **map, int len);
int			mapchecker(t_data *data);
int			elemchecker(char **map);
int			startcheck(char **map);
int			exitcheck(char **map);
int			itemcheck(char **map);
char		**pathfinding(char **map, int x, int y);
int			verexit(char **map, int x, int y);
int			pathexit(char **map);
int			veripath(char **map);
int			path(t_data *data);
int			linechr(char **str);
int			colonechr(char *str);
int			around(char **map, int x, int y);
void		changemap(char *map);
int			charverif(char c);
int			xplace(char **map);
int			yplace(char **map);
int			structinit(t_data **data, char *file);
void		errormessage(int m);
void		printmap(t_data *data);
char		**get_map(char *file);
int			othercheck(char **map);
int	mlx(t_data *data);
int	chargeimage(t_data *data);
int	chargewindow(t_data *data);
int	putimg(t_data *data, char c, int x, int y);

#endif