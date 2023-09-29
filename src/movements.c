/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:44:07 by juan-anm          #+#    #+#             */
/*   Updated: 2023/09/29 13:15:13 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_win *win, t_game *game, t_point new)
{
	int		x;
	int		y;

	x = game->pos.x;
	y = game->pos.y;
	if (!valid_cell(game, game->map, new.y, new.x))
		return ;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		game->sprts->tile, x * 64, y * 64);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			game->sprts->exit, x * 64, y * 64);
	game->pos.x = new.x;
	game->pos.y = new.y;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		game->sprts->hero, new.x * 64, new.y * 64);
	game->movements++;
	if (game->movements != 0)
		ft_printf("nbr movements = %i\n", game->movements);
	if (game->map[new.y][new.x] == 'C' || game->map[new.y][new.x] == 'E')
		collect_item(game, new.x, new.y, game->map[new.y][new.x]);
	if (game->check.collected == game->check.c)
		mlx_put_image_to_window(game->win->mlx_ptr, game->win->win_ptr, \
			game->sprts->opexit, game->sprts->expos.x * 64, \
			game->sprts->expos.y * 64);
}

void	collect_item(t_game *game, int x, int y, char item)
{
	if (item == 'C')
	{
		mlx_put_image_to_window(game->win->mlx_ptr, game->win->win_ptr, \
			game->sprts->tile, x * 64, y * 64);
		mlx_put_image_to_window(game->win->mlx_ptr, game->win->win_ptr, \
			game->sprts->hero, x * 64, y * 64);
		game->map[y][x] = '0';
	}
	else
	{
		if (game->check.collected == game->check.c)
			game->check.end = 1;
	}
}
