/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:44:01 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 14:53:36 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_destroy(t_data *img)
{
	close_all(img);
	return (0);
}

int	handle_input(int keysym, t_data *img)
{
	if (keysym == XK_Escape)
		close_all(img);
	else if (keysym == XK_Shift_L)
		img->shift_p = 1;
	else if (keysym == XK_Control_L)
		img->ctrl_p = 1;
	else if (keysym == XK_1)
		control_views(1, img);
	else if (keysym == XK_2)
		control_views(2, img);
	else if (keysym == XK_3)
		control_views(3, img);
	else if (keysym == XK_Up)
		control_trans(1, img);
	else if (keysym == XK_Down)
		control_trans(2, img);
	else if (keysym == XK_Left)
		control_trans(3, img);
	else if (keysym == XK_Right)
		control_trans(4, img);
	else if (keysym == XK_c)
		control_trans(5, img);
	else
		handle_input_2(keysym, img);
	return (0);
}

int	handle_input_2(int keysym, t_data *img)
{
	if (keysym == XK_a)
		img->ang_y += 0.05;
	else if (keysym == XK_d)
		img->ang_y -= 0.05;
	else if (keysym == XK_w)
		img->ang_x += 0.05;
	else if (keysym == XK_s)
		img->ang_x -= 0.05;
	else if (keysym == XK_q)
		img->ang_z += 0.05;
	else if (keysym == XK_e)
		img->ang_z -= 0.05;
	else if (keysym == XK_KP_Subtract && img->z_changer > -11)
		img->z_changer -= 1;
	else if (keysym == XK_KP_Add && img->z_changer < 11)
		img->z_changer += 1;
	else if (keysym == XK_4)
		img->z_changer = 1;
	mlx_destroy_image(img->mlx, img->img);
	render(img, *(img->map));
	return (0);
}

int	handle_release(int keysym, t_data *img)
{
	if (keysym == XK_Shift_L)
		img->shift_p = 0;
	else if (keysym == XK_Control_L)
		img->ctrl_p = 0;
	return (0);
}

int	close_all(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	map_free(*(img->map), img->map_l, img->map_w);
	exit(EXIT_SUCCESS);
	return (0);
}
