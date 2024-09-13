/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:05:39 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 15:36:11 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	splited_free(char **splited)
{
	int	j;

	j = 0;
	while (splited[j] != NULL)
	{
		free(splited[j]);
		j++;
	}
	free(splited);
	return (1);
}

int	map_free(t_point **map, int x, int y)
{
	int		i;

	(void) x;
	i = 0;
	while (i < y)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (1);
}
