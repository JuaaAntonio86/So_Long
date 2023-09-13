/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:37:10 by juan-anm          #+#    #+#             */
/*   Updated: 2023/08/06 09:39:09 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	if (buffer[fd] == NULL)
	{
		buffer[fd] = malloc(1 * sizeof(char));
		if (buffer[fd] == NULL)
			return (NULL);
		buffer[fd][0] = '\0';
	}
	buffer[fd] = ft_read_return_line(buffer[fd], fd);
	if (buffer[fd] == NULL || buffer[fd][0] == 0)
		return (ft_freegnl(&buffer[fd]));
	line = ft_newline(buffer[fd]);
	if (line == NULL)
		return (ft_freegnl(&buffer[fd]));
	buffer[fd] = ft_cleanbuffer(buffer[fd], line);
	if (buffer[fd] == NULL || line[0] == 0)
		return (ft_freegnl(&buffer[fd]));
	return (line);
}

char	*ft_read_return_line(char *buffer, int fd)
{
	int		read_check;
	char	*read_str;

	read_check = 1;
	read_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_str == NULL)
		return (ft_freegnl(&buffer));
	while (read_check > 0 && ft_strchr(buffer, '\n') == 0)
	{
		read_check = read(fd, read_str, BUFFER_SIZE);
		if (read_check < 0)
		{
			free(buffer);
			return (ft_freegnl(&read_str));
		}
		read_str[read_check] = '\0';
		buffer = ft_strjoingnl(buffer, read_str);
		if (buffer == NULL)
			return (ft_freegnl(&read_str));
	}
	free(read_str);
	return (buffer);
}

char	*ft_newline(char *buffer)
{
	int		i;
	char	*newline;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	newline = malloc((i + 1) * sizeof(char));
	if (newline == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		newline[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		newline[i++] = '\n';
	newline[i] = 0;
	return (newline);
}

void	*ft_freegnl(char	**str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_cleanbuffer(char *buffer, char *newline)
{
	char	*nbuffer;
	int		i;
	int		j;

	j = 0;
	if (ft_strlengnl(newline) > ft_strlengnl(buffer))
		i = ft_strlengnl(newline) - ft_strlengnl(buffer);
	else
		i = ft_strlengnl(buffer) - ft_strlengnl(newline);
	nbuffer = malloc((i + 1) * sizeof(char));
	if (nbuffer == NULL)
	{
		free(buffer);
		return (ft_freegnl(&newline));
	}
	i = ft_strlen(newline);
	while (buffer[i] != 0)
	{
		nbuffer[j++] = buffer[i++];
	}
	nbuffer[j] = 0;
	free(buffer);
	return (nbuffer);
}
