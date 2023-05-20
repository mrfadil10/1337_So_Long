/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:23:17 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/15 17:24:41 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_up(t_master *game)
{
	if (move_up(game) == 0)
	{
		if (game->map->line[game->data->p_x] != 'E')
			put_floor(game, game->data->p_x, game->data->p_y);
		else
			put_exit(game->data->exit.column, game->data->exit.row, game);
		put_player(game->data->p_x, game->map->prev->y_index, game);
		place_at_player_up(game);
		catch_data(game);
		game->data->moves_count += 1;
		ft_printf("\033[1;32mMoves counter: %d\n", game->data->moves_count);
	}
}

void	player_down(t_master *game)
{
	if (move_down(game) == 0)
	{
		if (game->map->line[game->data->p_x] != 'E')
			put_floor(game, game->data->p_x, game->data->p_y);
		else
			put_exit(game->data->exit.column, game->data->exit.row, game);
		put_player(game->data->p_x, game->map->next->y_index, game);
		place_at_player_down(game);
		catch_data(game);
		game->data->moves_count += 1;
		ft_printf("\033[1;32mMoves counter: %d\n", game->data->moves_count);
	}
}

void	player_right(t_master *game)
{
	if (move_right(game) == 0)
	{
		if (game->map->line[game->data->p_x] != 'E')
			put_floor(game, game->data->p_x, game->data->p_y);
		else
			put_exit(game->data->exit.column, game->data->exit.row, game);
		put_player(game->data->p_x + 1, game->data->p_y, game);
		catch_data(game);
		game->data->moves_count += 1;
		ft_printf("\033[1;32mMoves counter: %d\n", game->data->moves_count);
	}
}

void	player_left(t_master *game)
{
	if (move_left(game) == 0)
	{
		if (game->map->line[game->data->p_x] != 'E')
			put_floor(game, game->data->p_x, game->data->p_y);
		else
			put_exit(game->data->exit.column, game->data->exit.row, game);
		put_player(game->data->p_x - 1, game->data->p_y, game);
		catch_data(game);
		game->data->moves_count += 1;
		ft_printf("\033[1;32mMoves counter: %d\n", game->data->moves_count);
	}
}
