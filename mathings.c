/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:10:35 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 19:45:09 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coordinate_converter(t_data *img, t_point **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->map_w)
	{
		x = 0;
		while (x < img->map_l)
		{
			map[y][x].u = x;
			map[y][x].v = y;
			if (y < img->map_w - 1)
			{
				map[y][x].zz = map[y + 1][x].z;
				bresenham(map[y][x], x, y + 1, img);
			}
			if (x < img->map_l - 1)
			{
				map[y][x].zz = map[y][x + 1].z;
				bresenham(map[y][x], x + 1, y, img);
			}
			x++;
		}
		y++;
	}
}

int	rot_calculator(t_data *img, t_point *map, double *u1, double *v1)
{
	float	changed_z;
	float	changed_zz;

	changed_z = map->z - img->z_changer;
	changed_zz = map->zz - img->z_changer;
	mat_multiplier_z(img, &map->u, &map->v);
	mat_multiplier_z(img, u1, v1);
	mat_multiplier_y(img, &map->u, &(map->z));
	mat_multiplier_y(img, u1, &(map->zz));
	mat_multiplier_x(img, &map->v, &(map->z));
	mat_multiplier_x(img, v1, &(map->zz));
	return (0);
}

void	mat_multiplier_z(t_data *img, double *u, double *v)
{
	double		x;
	double		y;

	x = *u;
	y = *v;
	*u = cos(img->ang_z) * x - sin(img->ang_z) * y;
	*v = sin(img->ang_z) * x + cos(img->ang_z) * y;
}

void	mat_multiplier_y(t_data *img, double *u, float *z)
{
	double	x;

	x = *u;
	*u = cos(img->ang_y) * x + sin(img->ang_y) * (*z);
	*z = -sin(img->ang_y) * x + cos(img->ang_y) * (*z);
}

void	mat_multiplier_x(t_data *img, double *v, float *z)
{
	double	y;

	y = *v;
	if (*z != 0)
	{
		*v = cos(img->ang_x) * y - sin(img->ang_x) * (*z * img->z_changer);
		*z = sin(img->ang_x) * y + cos(img->ang_x) * (*z * img->z_changer);
	}
	else
	{
		*v = cos(img->ang_x) * y - sin(img->ang_x) * (*z);
		*z = sin(img->ang_x) * y + cos(img->ang_x) * (*z);
	}
}
