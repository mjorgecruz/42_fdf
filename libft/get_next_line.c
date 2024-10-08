/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:49:23 by masoares          #+#    #+#             */
/*   Updated: 2023/12/05 16:42:18 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bread;
	char		*line;
	static char	*temp;

	bread = 1;
	if (fd < 0 || BUFFER_SIZE < 0) 
		return (NULL);
	buffer = ft_calloc2(1, BUFFER_SIZE + 1);
	while (search_temp(temp) == 0 && bread > 0)
	{
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread < 0)
			return (ft_freeing(&buffer, &temp));
		buffer[bread] = '\0';
		add_to_temp(&temp, &buffer);
	}
	line = add_to_line(temp);
	temp = clean_temp(temp);
	free(buffer);
	return (line);
}

void	add_to_temp(char **temp, char **src)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*src == NULL)
		return ;
	if (!*temp)
		*temp = ft_calloc2(1, 1);
	str = ft_calloc2(1, (ft_strlen2(*temp) + ft_strlen2(*src) + 1));
	while ((*temp)[i] != '\0')
	{
		str[i] = (*temp)[i];
		i++;
	}
	while ((*src)[j] != '\0')
	{
		str[i + j] = (*src)[j];
		j++;
	}
	free(*temp);
	*temp = str;
}

char	*clean_temp(char *temp)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	str = NULL;
	if (!*temp || temp[0] == 0)
	{
		free(temp);
		return (NULL);
	}
	while (temp[len] != '\n' && temp[len] != '\0')
		len++;
	str = ft_calloc2(1, (ft_strlen2(temp) - len + 1));
	while (temp[len] != '\0')
	{
		str[i] = temp[++len];
		i++;
	}
	str[i] = '\0';
	free(temp);
	return (str);
}
/*
int main (void)
{
	int		fd;
	char	*str;

	fd = open("empty.txt", O_RDONLY |O_CREAT);
	//int open (const char* Path, int flags);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
	//fd = open("multiple_nl.txt", O_RDONLY | O_CREAT);
	//printf("%s", get_next_line(fd));
	//close(fd);
}
*/