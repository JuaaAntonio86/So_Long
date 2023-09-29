/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:44:35 by juan-anm          #+#    #+#             */
/*   Updated: 2023/09/29 12:12:37 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_win *win, t_game *game)
{
	int	w;
	int	h;

	game->sprts->hero = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/hero.xpm", &w, &h);
	game->sprts->tile = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/grass.xpm", &w, &h);
	game->sprts->wall = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/bush.xpm", &w, &h);
	game->sprts->coll = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/chest.xpm", &w, &h);
	game->sprts->opexit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/opn_exit.xpm", &w, &h);
	game->sprts->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/exit.xpm", &w, &h);
	if (!game->sprts->hero || !game->sprts->tile || \
		!game->sprts->wall || !game->sprts->coll || \
		!game->sprts->exit || !game->sprts->opexit)
		ft_error(2, "ERROR\nCould not open images");
}

void	render_map(t_game *game, t_win *win)
{
	int			x;
	int			y;

	y = -1;
	while (++y < game->heig)
	{
		x = -1;
		while (++x < game->len)
		{
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
				game->sprts->tile, x * 64, y * 64);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
						game->sprts->wall, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->coll, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->hero, x * 64, y * 64);
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
