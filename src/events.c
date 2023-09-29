/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:37 by juan-anm          #+#    #+#             */
/*   Updated: 2023/09/29 13:47:44 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game	*game)
{
	ft_freesp(game->map);
	mlx_destroy_window(game->win->mlx_ptr, game->win->win_ptr);
	exit(0);
}

void	outro(t_win *win, t_game *game)
{
	char	*str;
	int		x;
	int		y;
	void	*png;

	ft_printf("Game Over!\n");
	y = -1;
	while (++y < win->h)
	{
		x = -1;
		while (++x < win->w)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0x00000FF);
	}
	png = mlx_xpm_file_to_image(win->mlx_ptr, "sprites/GameOver.xpm", &x, &y);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, png, 0, 64);
	str = "Press ESC to exit";
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1, 15, 0x00FFFFFF, str);
	game->check.start = 0;
}

int	manage_keys(int key, t_game	*game)
{
	t_point	new;

	new.x = game->pos.x;
	new.y = game->pos.y;
	if (key == ESC)
		close_window(game);
	else if (key == SPACE && game->check.start == 0)
	{
		game->check.start = 1;
		render_map(game, game->win);
	}
	else if ((key == KEY_W || key == KEY_UP) && game->check.start == 1)
		new.y--;
	else if ((key == KEY_S || key == KEY_DOWN) && game->check.start == 1)
		new.y++;
	else if ((key == KEY_D || key == KEY_RIGHT) && game->check.start == 1)
		new.x++;
	else if ((key == KEY_A || key == KEY_LEFT) && game->check.start == 1)
		new.x--;
	else
		return (1);
	move(game->win, game, new);
	if (game->check.end == 1)
		outro(game->win, game);
	return (0);
}
