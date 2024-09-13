/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:45:46 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 15:15:35 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	bresenham(t_point map, double u1, double v1, t_data *img)
{
	double	varu;
	double	varv;
	int		max;

	rot_calculator(img, &map, &u1, &v1);
	map.u *= img->zoom;
	map.v *= img->zoom;
	u1 *= img->zoom;
	v1 *= img->zoom;
	map.u += ((1980 / 2) - (img->map_w / 2)) + img->trans_u * sqrt(img->zoom);
	map.v += ((1080 / 2) - (img->map_l / 2)) + img->trans_v * sqrt(img->zoom);
	u1 += ((1980 / 2) - (img->map_w / 2)) + img->trans_u * sqrt(img->zoom);
	v1 += ((1080 / 2) - (img->map_l / 2)) + img->trans_v * sqrt(img->zoom);
	varu = u1 - map.u;
	varv = v1 - map.v;
	max = max_finder(varu, varv);
	varu /= max;
	varv /= max;
	while ((int)(map.u - u1) || (int)(map.v - v1))
	{
		pixel_put(img, map.u, map.v, map.color);
		map.u += varu;
		map.v += varv;
	}
	return (1);
}

int	max_finder(double varu, double varv)
{
	if (varu < 0)
		varu *= (-1);
	if (varv < 0)
		varv *= (-1);
	if (varu < varv) 
		return (varv);
	else
		return (varu);
}
