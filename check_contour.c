/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:02:55 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/02 16:47:04 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*keep_data(int row_idx, char *line, t_map *last)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map->lnt = ft_strlen(line) - 1;
	map->y_index = row_idx;
	map->line = line;
	map->prev = last;
	return (map);
}

void	get_all_data(char *line, int fd, int i, t_map **map)
{
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		(*map)->next = keep_data(i, line, *map);
		*map = (*map)->next;
	}
	(*map)->lnt += 1;
}

void	check_dimension(int x, int y, t_master *game)
{
	if (x < 5 || y < 3)
		null_error("Error\n, Map is too small\n", game);
}

void	check_x_wall(t_master *game)
{
	int	i;

	i = 0;
	while (i != game->map->lnt)
	{
		if (game->map->line[i] != '1')
			null_error("Error\n Map isn't surrounded by wall\n", game);
		i++;
	}
	if (game->map->y_index == game->data->max_row)
	{
		check_data(game);
		return ;
	}
}

void	check_y_wall(t_master *game)
{
	int		lnt;

	lnt = game->map->lnt;
	if (game->map->line[0] != '1' || game->map->line[lnt - 1] != '1')
		null_error("Error\n Map isn't surrounded by wall\n", game);
	
}