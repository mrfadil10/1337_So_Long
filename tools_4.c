/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:02:14 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/21 19:52:37 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_master *game)
{
	if (game->map->prev->line[game->data->p_x] == 'E'
		&& game->data->active_exit == 0)
		return (1);
	if (game->map->prev->y_index == 1)
		return (1);
	if (game->map->prev->line[game->data->p_x] == '1')
		return (1);
	else
		return (0);
}

int	move_down(t_master *game)
{
	if (game->map->next->line[game->data->p_x] == 'E'
		&& game->data->active_exit == 0)
		return (1);
	if (game->map->next->y_index == game->map->y_index)
		return (1);
	if (game->map->next->line[game->data->p_x] == '1')
		return (1);
	else
		return (0);
}

int	move_right(t_master *game)
{
	if (game->map->line[game->data->p_x + 1] == 'E'
		&& game->data->active_exit == 0)
		return (1);
	if (game->map->line[game->data->p_x + 1] == '1')
		return (1);
	else
		return (0);
}

int	move_left(t_master *game)
{
	if (game->map->line[game->data->p_x - 1] == 'E'
		&& game->data->active_exit == 0)
		return (1);
	if (game->map->line[game->data->p_x - 1] == '1')
		return (1);
	else
		return (0);
}
