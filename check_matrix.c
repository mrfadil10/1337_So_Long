/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:46:18 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/22 10:45:40 by mfadil           ###   ########.fr       */
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

void	recursion(char **map, t_master *game, int x, int y)
{
	flood_tools(map, game, x + 1, y);
	flood_tools(map, game, x - 1, y);
	flood_tools(map, game, x, y + 1);
	flood_tools(map, game, x, y - 1);
}

int	flood_tools(char **map, t_master *game, int x, int y)
{
	static int	pieces = -1;

	if (pieces == -1)
		pieces = game->data->to_collect + 1;
	if (x >= 0 && x < game->map->lnt & y >= 0 && y < game->data->max_row - 1)
	{
		if (map[y][x] == 'F')
			return (pieces);
		else
		{
			if (map[y][x] == 'C')
				pieces--;
			else if (map[y][x] == 'E')
			{
				pieces--;
				return (map[y][x] = 'F', pieces);
			}
			else if (map[y][x] == '1')
				return (pieces);
			map[y][x] = 'F';
		}
		recursion(map, game, x, y);
	}
	return (pieces);
}

int	check_flood(t_master *game, int x, int y)
{
	char	**map;
	int		pieces;

	map = dup_map(game);
	pieces = flood_tools(map, game, x, y);
	return (pieces);
}
