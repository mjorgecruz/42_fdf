/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:07:01 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 16:53:12 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
this file turns the received .fdf file in a formatted array of structs where
the first number (z) is the height of the specific point and the second argument
(color) states the color already converted from the file to an int. If no color
is provided, the value is set to a value dependant on the height 
*/

#include "fdf.h"

t_point	**map_converter(char *filename, int *x, int *y)
{
	t_point		**map;

	if (find_dimension(x, y, filename) == -1)
		errors(3);
	create_array(*x, *y, filename, &map);
	return (map);
}

int	find_dimension(int *x, int *y, char *filename)
{
	char	*line;
	int		fd;
	int		x1;

	*y = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		errors(1);
	x1 = 0;
	line = get_next_line(fd);
	if (!line)
		errors(2);
	*x = count_words(line, ' ');
	while (line)
	{
		*y = *y + 1;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

int	create_array(int x, int y, char *filename, t_point ***map)
{
	int		fd;
	char	*line;
	char	**splited;
	int		i;

	i = 0;
	splited = NULL;
	*map = (t_point **) malloc (sizeof(t_point *) * y);
	if (*map == NULL)
		return (-1);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		(*map)[i] = (t_point *) malloc (sizeof(t_point) * x);
		if ((*map)[i] == NULL)
			return (-1);
		splited = ft_split(line, ' ');
		add_to_map(*map, x, i, splited);
		splited_free(splited);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (close(fd), 1);
}

int	add_to_map(t_point **map, int x, int y, char **splited)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (splited[i] != NULL && i < x)
	{
		map[y][i].z = ft_atoi(splited[i]);
		j = 0;
		while (splited[i][j] != 0)
		{
			map[y][i].color = 0;
			if (splited[i][j] == ',' && splited[i][j + 1] == '0'
				&& splited[i][j + 2] == 'x')
			{
				map[y][i].color = ft_atoi_base(&splited[i][j + 3], 16);
				break ;
			}
			j++;
		}
		if (map[y][i].color == 0)
			map[y][i].color = color_z_based(map[y][i].z, x);
		i++;
	}
	return (1);
}
