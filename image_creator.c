/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:14:54 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 15:07:49 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	image_creator(t_data *img, t_point **map)
{
	img->mlx = mlx_init();
	if (img->mlx == NULL)
		return (-1);
	img->mlx_win = mlx_new_window(img->mlx, WIN_L, WIN_H, "fdf");
	if (img->mlx_win == NULL)
	{
		free(img->mlx_win);
		return (-2);
	}
	img->trans_u = 0;
	img->trans_v = 0;
	img->z_changer = 1;
	img->ctrl_p = 0;
	img->shift_p = 0;
	render(img, map);
	mlx_hook(img->mlx_win, 4, 1L << 2, &controls, img);
	mlx_hook(img->mlx_win, 5, 1L << 3, &controls_release, img);
	mlx_hook(img->mlx_win, 6, 1L << 6, &control_angles, img);
	mlx_hook(img->mlx_win, 3, 1L << 1, &handle_release, img);
	mlx_hook(img->mlx_win, KeyPress, KeyPressMask, &handle_input, img);
	mlx_hook(img->mlx_win, DestroyNotify, 1L << 2, &handle_destroy, img);
	mlx_loop(img->mlx);
	return (1);
}
