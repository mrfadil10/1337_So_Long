/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:48:07 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/02 15:56:19 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line_bonus.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_map
{
	int				lnt;
	int				y_index;
	char			*line;
	struct s_map	*prev;
	struct s_map	*next;
}	t_map;

typedef struct s_target
{
	int				x;
	int				y;
	int				num;
	int				taken;
	struct s_target	*prev;
	struct s_target	*next;
}	t_target;

typedef struct s_infos
{
	int	row;
	int	column;
	int	quantity;
}	t_infos;

typedef struct s_data
{
	int				max_row;
	int				p_x;
	int				p_y;
	int				moves_count;
	int				trig_exit;
	int				to_collect;
	int				collected;
	t_target		*collectible;
	t_infos			player;
	t_infos			exit;
}	t_data;

typedef struct s_master
{
	t_map	*map;
	t_data	*data;
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	int		x;
	int		y;
	char	**path;
	void	*player;
	void	*floor;
	void	*collect;
	void	*n_wall;
	void	*s_wall;
	void	*e_wall;
	void	*w_wall;
	void	*o_wall;
	void	*a_exit;
	void	*u_exit;
}	t_master;

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);

void	delete_array(t_master **game);
void	delete_target(t_master *game);
void	delete_game(t_master *game);

int		error(char *message);
int		free_element(t_data *element);
void	*null_error(char *message, t_master *game);
void	place_at_player_up(t_master *game);
void	place_at_player_down(t_master *game);
void	check_data(t_master *game);

#endif
