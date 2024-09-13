/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:31:53 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 15:16:24 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	control_trans(int key, t_data *img)
{
	if (key == 1)
		img->trans_v += -10;
	else if (key == 2)
		img->trans_v += +10;
	else if (key == 3)
		img->trans_u += -10;
	else if (key == 4)
		img->trans_u += +10;
	else if (key == 5)
	{
		img->trans_u = 0;
		img->trans_v = 0;
	}
	mlx_destroy_image(img->mlx, img->img);
	render(img, *(img->map));
	return (0);
}
