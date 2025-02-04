/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:09:17 by juanantonio       #+#    #+#             */
/*   Updated: 2023/09/29 14:48:33 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "Libs/MyLibft/libft.h"
# include "Libs/mlx/mlx.h"

//events
# define DESTROY_WIN 17

//keycodes
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define SPACE 49
# define ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

//structs
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_check
{
	int		start;
	int		p;
	int		e;
	int		c;
	int		collected;
	int		exit;
	int		end;
}	t_check;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			w;
	int			h;
}	t_win;

typedef struct s_sprites
{
	void	*player;
	void	*floor;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*opexit;
	t_point	expos;
}	t_sprites;

typedef struct s_game
{
	int			movements;
	char		**map;
	int			l;
	int			h;
	t_check		check;
	t_point		pos;
	t_sprites	*sprts;
	t_win		*win;
}	t_game;

//main
void	ft_error(int err, char *msg);
void	init_game(char *ar, t_game *game, t_sprites *s);
void	start_mlx(t_win *win, t_game *game);
void	intro(t_win *win, t_game *game);

//map_checker
int		check_file(char *file, char *ext);
void	check_map(char *file, t_game *game);
void	valid_line(char *line, t_game *game);
void	check_items(t_game *game);
void	map_dimentions(t_game *game);

//path finder
void	path_checker(t_game *game);
char	**temp_map(t_game *game);
int		flood_fill(t_game *game, char **map, int row, int col);
int		valid_cell(t_game *game, char **map, int row, int col);

//events
int		close_window(t_game	*game);
void	end(t_win *win, t_game *game);
int		manage_keys(int keycode, t_game	*game);

//movements
void	move(t_win *win, t_game *game, t_point new);
void	collect_item(t_game *game, int x, int y, char item);

//images
void	plot_map(t_game *game, t_win *win);
void	init_sprites(t_win *win, t_game *game);
void	exit_pos(t_game *game, t_win *win, int x, int y);

#endif