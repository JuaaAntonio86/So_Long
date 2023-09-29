/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:44:35 by juan-anm          #+#    #+#             */
/*   Updated: 2023/09/29 14:44:46 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_win *win, t_game *game)
{
	int	w;
	int	h;

	game->sprts->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/wizzard.xpm", &w, &h);
	game->sprts->floor = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/path.xpm", &w, &h);
	game->sprts->wall = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/lava.xpm", &w, &h);
	game->sprts->coll = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/potion.xpm", &w, &h);
	game->sprts->opexit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/opn_exit.xpm", &w, &h);
	game->sprts->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/exit.xpm", &w, &h);
	if (!game->sprts->player || !game->sprts->floor || \
		!game->sprts->wall || !game->sprts->coll || \
		!game->sprts->exit || !game->sprts->opexit)
		ft_error(2, "ERROR\nCould not open images");
}

void	plot_map(t_game *game, t_win *win)
{
	int			x;
	int			y;

	y = -1;
	while (++y < game->h)
	{
		x = -1;
		while (++x < game->l)
		{
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
				game->sprts->floor, x * 64, y * 64);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
						game->sprts->wall, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->coll, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->player, x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				exit_pos(game, win, x, y);
		}
	}
}

void	exit_pos(t_game *game, t_win *win, int x, int y)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		game->sprts->exit, x * 64, y * 64);
	game->sprts->expos.y = y;
	game->sprts->expos.x = x;
}
