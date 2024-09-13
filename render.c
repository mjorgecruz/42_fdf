/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:13:24 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 15:44:39 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render(t_data *img, t_point **map)
{
	img->img = mlx_new_image(img->mlx, WIN_L, WIN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bitspp,
			&img->line_length, &img->endian);
	render_view(img, map);
	render_rect(img);
	render_rect2(img);
	render_rect3(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_string_put(img->mlx, img->mlx_win, 1980 / 2, 25, 0xFFFFAA,
		"F D F");
	mlx_string_put(img->mlx, img->mlx_win, 10, 75, 0xFFFFAA,
		"Press 1 2 3 to change view");
	mlx_string_put(img->mlx, img->mlx_win, 10, 100, 0xFFFFAA,
		"Use Q E to rotate in zz");
	mlx_string_put(img->mlx, img->mlx_win, 10, 125, 0xFFFFAA,
		"Use A D to rotate in xx");
	mlx_string_put(img->mlx, img->mlx_win, 10, 150, 0xFFFFAA,
		"Use W S to rotate in yy");
	mlx_string_put(img->mlx, img->mlx_win, 10, 175, 0xFFFFAA,
		"Use arrows to translate");
	mlx_string_put(img->mlx, img->mlx_win, 10, 200, 0xFFFFAA,
		"Mouse 3 to zoom");
	mlx_string_put(img->mlx, img->mlx_win, 10, 225, 0xFFFFAA,
		"Press + or - to increase/descrease height, 4 to reset");
	return (0);
}

void	render_view(t_data *img, t_point **map)
{
	coordinate_converter(img, map);
}

void	render_rect(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 1980)
	{
		j = 0;
		while (j < 50)
		{
			img->color = 0x305060;
			pixel_put(img, i, j, img->color);
			j++;
		}
		i++;
	}
}

void	render_rect2(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 350)
	{
		j = 50;
		while (j < 250)
		{
			img->color = 0x303030;
			pixel_put(img, i, j, img->color);
			j++;
		}
		i++;
	}
}

void	render_rect3(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 1980)
	{
		j = 48;
		while (j < 52)
		{
			img->color = 0xFFFFAA;
			pixel_put(img, i, j, img->color);
			j++;
		}
		i++;
	}
}
