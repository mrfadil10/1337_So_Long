/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:34:41 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/19 12:16:47 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_array(t_master **game)
{
	int	i;

	i = 0;
	if (!((*game)->path))
		return ;
	while ((*game)->path[i] != NULL)
	{
		free((*game)->path[i]);
		i++;
	}
	free((*game)->path);
	(*game)->path = NULL;
	return ;
}

void	delete_target(t_master *game)
{
	t_piece	*next;

	while (game->data->collectible->prev)
		game->data->collectible = game->data->collectible->prev;
	while (game->data->collectible)
	{
		next = game->data->collectible->next;
		free(game->data->collectible);
		game->data->collectible = next;
	}
	free(game->data->collectible);
	game->data->collectible = NULL;
}

void	delete_game(t_master *game)
{
	if (game->data->collectible != NULL)
		delete_target(game);
	if (game->path != NULL)
		delete_array(&game);
}
