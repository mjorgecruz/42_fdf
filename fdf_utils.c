/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:02:45 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 15:26:40 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < WIN_L && y < WIN_H && x > 0 && y > 0) 
	{
		dst = data->addr + (y * data->line_length + x * (data->bitspp / 8));
		*(unsigned int *) dst = color;
	}
}

int	color_make(int i, int j)
{
	int		red;
	int		green;
	int		blue;
	int		transparence;
	int		color;

	red = 0x00000000 + ((i * (255 / 200)) << 16);
	blue = 0x00000000 + ((i + j) * (255 / 100));
	green = 0x00000000 + ((j *(255 / 100)) << 8);
	transparence = 0xFF000000 + (((i - j) * 255 / 200) << 24);
	color = red + blue + green + transparence;
	return (color);
}

int	color_z_based(int z, int x)
{
	int		red;
	int		green;
	int		blue;
	int		transparence;
	int		color;

	if (z >= 0)
	{
		red = 0x00000000 + (((5 * z)) << 16);
		blue = 0x00000000 + (0);
		green = 0x00000000 + ((5 * x - z * (255 / x)) << 8);
		transparence = 0x00000000 + ((0) << 24);
	}
	else 
	{
		red = 0x00000000 + (0 << 16);
		blue = 0x00000000 + (255 + z * (255 / x));
		green = 0x00000000 + ((255) << 8);
		transparence = 0x00000000 + ((0) << 24);
	}
	color = red + blue + green + transparence;
	return (color);
}
