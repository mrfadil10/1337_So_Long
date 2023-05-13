/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:09:14 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/12 14:45:07 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_collectible(t_master *game)
{
	while (game->data->collectible->num != 1)
		game->data->collectible = game->data->collectible->prev;
}

int	catched_collectible(t_master *game)
{
	reset_collectible(game);
	while (game->data->collectible->num <= game->data->to_collect)
	{
		if (game->data->collectible->y != game->data->p_y)
			game->data->collectible = game->data->collectible->next;
		if (game->data->collectible->y == game->data->p_y)
		{
			if (game->data->collectible->x == game->data->p_x)
			{
				if (game->data->collectible->taken != 1)
				{
					game->data->collectible->taken = 1;
					return (0);
				}
				else
					return (1);
			}
			else if (game->data->collectible->num < game->data->to_collect)
				game->data->collectible = game->data->collectible->next;
		}
	}
	return (0);
}

void	unlock_door(t_master *game)
{
	game->data->trig_exit = 1;
	put_unlock(game->data->exit.column, game->data->exit.row, game);
}

// missing something here

void	catch_data(t_master *game)
{
	if (game->map->line[game->data->p_x] == 'C')
	{
		if (catched_collectible(game) == 0)
		{
			game->data->collected += 1;
			if (game->data->collected == game->data->to_collect)
				unlock_door(game);
		}
	}
	if (game->map->line[game->data->p_x] == 'E')
	{
		if (game->data->trig_exit == 1)
		{
			delete_game(game);
			exit (0);
		}
	}
}
