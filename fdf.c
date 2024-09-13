/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:54:00 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 15:27:46 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	img;
	int		x;
	int		y;
	t_point	**map;

	x = 0;
	y = 0;
	if (ac == 1 || ac > 2)
		errors(4);
	if (ac == 2)
	{
		map = map_converter(av[1], &x, &y);
		img.map_l = x;
		img.map_w = y;
		img.zoom = 3;
		img.map = &map;
		img.ang_z = 0.743534;
		img.ang_y = -0.0123;
		img.ang_x = 0.56789;
		img.mouse2 = 0;
		image_creator(&img, map);
		map_free(map, x, y);
	}
	return (1);
}
