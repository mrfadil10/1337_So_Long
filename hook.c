/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:28:19 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/11 17:40:48 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	escape_botton(t_master *game)
{
	if (game)
		delete_game(game);
	exit (0);
	return (0);
}

void	play(int key, t_master *game)
{
	if (key == 13 || key == 126)
	{
		player_up(game);
		game->data->moves_count += 1;
		printf("Moves counter: %d\n", game->data->moves_count);
	}
	if (key == 1 || key == 125)
	{
		player_down(game);
		game->data->moves_count += 1;
		printf("Moves counter: %d\n", game->data->moves_count);
	}
	if (key == 0 || key == 123)
	{
		player_left(game);
		game->data->moves_count += 1;
		printf("Moves counter: %d\n", game->data->moves_count);
	}
	if (key == 2 || key == 124)
	{
		player_right(game);
		game->data->moves_count += 1;
		printf("Moves counter: %d\n", game->data->moves_count);
	}
}

int	key_hook(int key, t_master *game)
{
	if (key == 53 || key == 65037)
		escape_botton(game);
	else
		play(key, game);
	return (0);
}

int	x_exit(int keycode, t_master *game)
{
	if (keycode == 17)
		delete_game(game);
	exit (0);
	return (0);
}
