/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:48:07 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/22 00:38:13 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line_bonus.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>

typedef struct s_map
{
	int				lnt;
	int				y_index;
	char			*line;
	struct s_map	*prev;
	struct s_map	*next;
}	t_map;

typedef struct s_piece
{
	int				x;
	int				y;
	int				num;
	int				taken;
	struct s_piece	*prev;
	struct s_piece	*next;
}	t_piece;

typedef struct s_infos
{
	int	row;
	int	column;
	int	quantity;
}	t_infos;

typedef struct s_data
{
	int				p_x;
	int				p_y;
	int				max_row;
	int				moves_count;
	int				active_exit;
	int				to_collect;
	int				collected;
	t_piece			*collectible;
	t_infos			player;
	t_infos			exit;
}	t_data;

typedef struct s_master
{
	t_map	*map;
	t_data	*data;
	void	*mlx;
	void	*mlx_win;
	int		win_x;
	int		win_y;
	int		x;
	int		y;
	char	**path;
	void	*player;
	void	*floor;
	void	*obs;
	void	*collect;
	void	*n_wall;
	void	*s_wall;
	void	*e_wall;
	void	*w_wall;
	void	*op_exit;
	void	*cl_exit;
}	t_master;

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);

void	delete_array(t_master **game);
void	delete_target(t_master *game);
void	delete_game(t_master *game);

t_map	*keep_data(int row_idx, char *line, t_map *last);
void	get_data(char *line, int fd, int i, t_map **map);
int		error(char *message);
int		free_element(t_data *element);
void	*null_error(char *message, t_master *game);
void	place_at_player_up(t_master *game);
void	place_at_player_down(t_master *game);
void	check_data(t_master *game);
void	collect_infos(t_master *game);
void	check_x_wall(t_master *game);
void	check_y_wall(t_master *game);
void	check_dimension(int x, int y, t_master *game);
int		check_flood(t_master *game, int x, int y);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *str, int c);
void	ft_putnbr_fd(int nb, int fd);

//putting active items

void	put_player(int i, int row, t_master *game);
void	put_collects(int i, int row, t_master *game);
void	put_obstacles(int i, int row, t_master *game);
void	put_unlock(int i, int row, t_master *game);
void	put_exit(int i, int row, t_master *game);
void	floors(int x, t_master *game);
void	put_row_walls(t_master *game);
void	put_col_walls(t_master *game);
void	put_floor(t_master *game, int i, int row);
void	catch_data(t_master *game);
void	graph_mlx(t_master *game);

// moves

int		move_up(t_master *game);
int		move_down(t_master *game);
int		move_right(t_master *game);
int		move_left(t_master *game);
void	player_up(t_master *game);
void	player_down(t_master *game);
void	player_right(t_master *game);
void	player_left(t_master *game);

int		key_hook(int key, t_master *game);
int		x_exit(int keycode, t_master *game);
void	ft_error(char *message, char *file, int line);
int		flood_tools(char **map, t_master *game, int x, int y);
#endif
