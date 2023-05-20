/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:17:50 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/19 10:21:38 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floors(int x, t_master *game)
{
	int	i;
	int	y;

	i = 2;
	y = 64;
	game->floor = mlx_xpm_file_to_image(game->mlx, "xpm/floor_2.0.xpm",
			&game->x, &game->y);
	if (!(game->floor))
	{
		free_element(game->floor);
		ft_error("\033[1;31mError: can't load xpm/floor_2.0.xpm!",
			__FILE__, __LINE__);
	}
	while (y <= game->win_y - 64 && i <= (game->data->max_row - 1))
	{
		while (x < game->win_x - 64)
		{
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->floor, x, y);
			x += 64;
		}
		x = 64;
		y += 64;
		i++;
	}
}

void	put_floor(t_master *game, int i, int row)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
		i * 64, (row * 64) - 64);
}

void	set_active_items(t_master *game)
{
	int	i;

	while (game->map->prev != NULL)
		game->map = game->map->prev;
	game->map = game->map->next;
	while (game->map->y_index != game->data->max_row)
	{
		i = 1;
		while (i <= game->map->lnt - 2)
		{
			if (game->map->line[i] == 'P')
				put_player(i, game->map->y_index, game);
			if (game->map->line[i] == '1')
				put_obstacles(i, game->map->y_index, game);
			if (game->map->line[i] == 'C')
				put_collects(i, game->map->y_index, game);
			if (game->map->line[i] == 'E')
				put_exit(i, game->map->y_index, game);
			i++;
		}
		game->map = game->map->next;
	}
	place_at_player_up(game);
}

void	graph_mlx(t_master *game)
{
	int	position;

	position = 64;
	put_row_walls(game);
	put_col_walls(game);
	floors(position, game);
	set_active_items(game);
}
