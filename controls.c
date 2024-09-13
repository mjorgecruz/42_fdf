/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:31:53 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 15:57:09 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	controls(int mousecode, int x, int y, t_data *img)
{
	if (mousecode == 4 || mousecode == 5)
		control_zoom(mousecode, x, y, img);
	if (mousecode == 2)
	{
		if (img->shift_p != 0)
		{
			img->mouse2 = 1;
			img->prev_x = x;
			img->prev_y = y;
			usleep(10);
		}
	}
	return (0);
}

int	control_zoom(int mousecode, int x, int y, t_data *img)
{
	(void) x;
	(void) y;
	if (mousecode == 4 && img->zoom < 40)
	{
		img->zoom += 1;
		mlx_destroy_image(img->mlx, img->img);
		render(img, *(img->map));
	}
	if (mousecode == 5 && img->zoom > 2)
	{
		img->zoom -= 1;
		mlx_destroy_image(img->mlx, img->img);
		render(img, *(img->map));
	}
	return (0);
}

int	control_angles(int x, int y, t_data *img)
{
	if (img->mouse2 == 1)
	{
		img->ang_z += (x - img->prev_x) * 0.01;
		img->ang_y += (y - img->prev_y) * 0.01;
		img->ang_x += (x - img->prev_x) * 0.002;
		img->prev_x = x;
		img->prev_y = y;
		mlx_destroy_image(img->mlx, img->img);
		render(img, *(img->map));
	}
	return (1);
}

int	controls_release(int mousecode, int x, int y, t_data *img)
{
	(void) x;
	(void) y;
	if (mousecode == 2)
		img->mouse2 = 0;
	return (0);
}

int	control_views(int view, t_data *img)
{
	if (view == 1)
	{
		img->ang_x = 0;
		img->ang_y = 0;
		img->ang_z = 0;
	}
	else if (view == 2)
	{
		img->ang_x = 1.6;
		img->ang_y = 0;
		img->ang_z = 0;
	}
	else if (view == 3)
	{
		img->ang_z = 0.743534;
		img->ang_y = -0.0123;
		img->ang_x = 0.56789;
	}
	mlx_destroy_image(img->mlx, img->img);
	render(img, *(img->map));
	return (0);
}
