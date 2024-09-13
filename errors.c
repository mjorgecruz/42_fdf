/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:00:03 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 17:07:22 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	errors(int i)
{
	if (i == 1)
		write(STDERR_FILENO,
			"Error: Map name not found or lacks permissions", 46);
	else if (i == 2)
		perror("Error: Please input \"./fdf <FILENAME>\" Path chosen");
	else if (i == 3)
		write(STDERR_FILENO, "Error: Map incorrectly formated", 32);
	else if (i == 4)
		write(STDERR_FILENO,
			"Error: Please input \"./fdf <FILENAME>\"", 38);
	exit(EXIT_FAILURE);
}
