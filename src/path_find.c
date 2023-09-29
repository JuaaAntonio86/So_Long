/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:44:19 by juan-anm          #+#    #+#             */
/*   Updated: 2023/09/29 14:27:27 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	path_checker(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = temp_map(game);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				game->pos.x = j;
				game->pos.y = i;
				if (flood_fill(game, map, i, j) == 0)
					ft_error(0, "ERROR: Map has no solution");
			}
		}
	}
	game->check.collected = 0;
	game->check.exit = 0;
	ft_freesp(map);
}

char	**temp_map(t_game *game)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (game->h + 1));
	if (!map)
		ft_error(1, "ERROR: MALLOC returned (NULL)");
	i = -1;
	while (game->map[++i])
	{
		map[i] = ft_substr(game->map[i], 0, game->l);
		if (!map[i])
		{
			ft_freesp(map);
			ft_error(1, "ERROR: MALLOC returned (NULL)");
		}
	}
	map[i] = NULL;
	return (map);
}

int	flood_fill(t_game *game, char **map, int row, int col)
{
	if (game->check.collected == game->check.c && game->check.exit == 1)
		return (1);
	map[row][col] = '1';
	if (valid_cell(game, map, row, col + 1))
		if (flood_fill(game, map, row, col + 1))
			return (1);
	if (valid_cell(game, map, row + 1, col))
		if (flood_fill(game, map, row + 1, col))
			return (1);
	if (valid_cell(game, map, row, col - 1))
		if (flood_fill(game, map, row, col - 1))
			return (1);
	if (valid_cell(game, map, row - 1, col))
		if (flood_fill(game, map, row - 1, col))
			return (1);
	return (0);
}

int	valid_cell(t_game *game, char **map, int row, int col)
{
	if (row >= 0 && row < game->h && col >= 0 && col < game->l)
	{
		if (map[row][col] == '1')
			return (0);
		if (map[row][col] == 'C')
			game->check.collected++;
		if (map[row][col] == 'E')
			game->check.exit = 1;
		return (1);
	}
	return (0);
}
