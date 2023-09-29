/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:54 by juan-anm          #+#    #+#             */
/*   Updated: 2023/09/29 14:08:03 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file(char *file, char *ext)
{
	int		i;
	int		j;
	int		g;

	i = 0;
	j = 0;
	g = 0;
	while (file[i])
		i++;
	i -= 4;
	while (file[i] == ext[j])
	{
		j++;
		i++;
		g++;
	}
	return (g);
}

void	check_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*str_map;

	str_map = NULL;
	if (check_file(file, ".ber") != 5)
		ft_error(1, "ERROR: File should be .ber type\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(1, "ERROR: File does not open\n");
	line = get_next_line(fd);
	if (!line)
		ft_error(1, "ERROR: Empty File\n");
	while (line)
	{
		str_map = ft_strjoin_free(str_map, line);
		valid_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(str_map, '\n');
	map_dimentions(game);
	free(str_map);
	check_items(game);
	close(fd);
}

void	valid_line(char *line, t_game *game)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'P')
			game->check.p++;
		else if (line[i] == 'E')
			game->check.e++;
		else if (line[i] == 'C')
			game->check.c++;
		else if (line[i] != '1' && line[i] != '0' && line[i] != '\n')
			ft_error(1, "ERROR: Unrecognized characters in map\n");
	}
	if (line[0] != '1' || (line[i - 1] == '\n' && line[i - 2] != '1'))
		ft_error(1, "ERROR: Map should be delimited by walls\n");
	else if (line[i - 1] != '\n' && line[i - 1] != '1')
		ft_error(1, "ERROR: Map should be delimited by walls\n");
}

void	check_items(t_game *game)
{
	int		i;
	int		j;
	size_t	len_line;

	i = 0;
	if (game->check.p != 1)
		ft_error(1, "ERROR: Map can only contain 1 starting point\n");
	if (game->check.c < 1)
		ft_error(1, "ERROR: Map should contain at least 1 collectible\n");
	if (game->check.e != 1)
		ft_error(1, "ERROR: Map can only contain 1 exit point\n");
	len_line = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len_line)
			ft_error(1, "ERROR: The walls of the map should not be of \
			equal size\n");
		i++;
	}
	j = -1;
	while (game->map[0][++j])
		if (game->map[0][j] != '1')
			ft_error(1, "ERROR: Map should be delimited by walls\n");
	while (--j >= 0)
		if (game->map[i - 1][j] != '1')
			ft_error(1, "ERROR: Map should be delimited by walls\n");
}

void	map_dimentions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
		i++;
	j = 0;
	while (game->map[0][j])
		j++;
	game->l = j;
	game->h = i;
}
