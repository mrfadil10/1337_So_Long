/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:34:30 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/02 22:50:23 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_data(t_master *game)
{
	if (game->data->exit.quantity != 1)
		null_error("Error\n There's more than one exit\n", game);
	if (game->data->player.quantity != 1)
		null_error("Error\n There's more than one player\n", game);
	if (game->data->to_collect < 1)
		null_error("Error\n Need at least one collectible", game);
	while (game->map->prev != NULL)
		game->map = game->map->prev;
}

void	take_player_nd_exit(t_master *game, int i)
{
	if (game->map->line[i] == 'P')
	{
		game->data->player.quantity += 1;
		game->data->player.column = i;
		game->data->player.row = game->map->y_index;
		game->data->p_x = i;
		game->data->p_y = game->map->y_index;
	}
	else if (game->map->line[i] == 'E')
	{
		game->data->exit.quantity += 1;
		game->data->exit.column = i;
		game->data->exit.row = game->map->y_index;
	}
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (0);
}

t_target	*collect(int n, int x_idx, int y_idx, t_target *last)
{
	t_target	*data;

	data = ft_calloc(1, sizeof(t_target));
	data->num = n;
	data->x = x_idx;
	data->y = y_idx;
	data->prev = last;
	return (data);
}

void	collect_infos(t_master *game)
{
	int	i;

	i = 1;
	while (game->map->line[i] && i < game->map->lnt)
	{
		if (game->map->line[i] == 'C')
		{
			game->data->to_collect += 1;
			if (game->data->to_collect != 1)
			{
				game->data->collectible->next = collect(game->data->to_collect,
						i, game->map->y_index, game->data->collectible);
				game->data->collectible = game->data->collectible->next;
			}
			if (game->data->to_collect == 1)
				game->data->collectible = collect(game->data->to_collect,
						i, game->map->y_index, NULL);
		}
		if (ft_strchr("PE", game->map->line[i] == 0))
			take_player_nd_exit(game, i);
		if (ft_strchr("PEC10", game->map->line[i]) == 1)
			null_error("Error\n The player is not allowed in the map\n", game);
		i++;
	}
}
