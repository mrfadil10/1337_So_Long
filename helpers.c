/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:03:00 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/01 17:32:49 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message)
{
	if (1)
		write(2, message, ft_strlen(message));
	return (1);
}

int	free_element(t_data *element)
{
	free(element);
	return (0);
}

void	*null_error(char *message, t_master *game)
{
	error(message);
	delete_game(game);
	exit (1);
}

void	place_at_player_up(t_master *game)
{
	while (game->map->y_index != game->data->p_y)
		game->map = game->map->prev;
}

void	place_at_player_down(t_master *game)
{
	while (game->map->y_index != game->data->p_y)
		game->map = game->map->next;
}
