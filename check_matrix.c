/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:46:18 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/11 22:39:00 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	return (str - len);
}

char	**dup_map(t_master *game)
{
	int		i;
	char	**str;

	i = 0;
	while (game->map->prev != NULL)
		game->map = game->map->prev;
	str = ft_calloc(game->data->max_row + 1, sizeof(char *));
	while (i < game->data->max_row && game->map->next != NULL)
	{
		str[i] = ft_strdup(game->map->line);
		game->map = game->map->next;
		i++;
	}
	while (game->map->prev != NULL)
		game->map = game->map->prev;
	game->path = str;
	return (game->path);
}

int	check_flood(t_master *game, int x, int y)
{
	static char	**map = NULL;
	static int	pieces = -1;

	if (pieces == -1)
		pieces = game->data->to_collect + 1;
	if (!map)
		map = dup_map(game);
	if (x >= 0 && x < game->map->lnt & y >= 0 && y < game->data->max_row - 1)
	{
		if (map[y][x] == 'F')
			return (pieces);
		else
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				pieces--;
			else if (map[y][x] == '1')
				return (pieces);
			map[y][x] = 'F';
		}
		check_flood(game, x + 1, y);
		check_flood(game, x - 1, y);
		check_flood(game, x, y + 1);
		check_flood(game, x, y - 1);
	}
	return (pieces);
}
