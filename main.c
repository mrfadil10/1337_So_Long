/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:19:18 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/21 16:15:55 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_master *game)
{
	int	i;
	int	lnt;

	i = 1;
	lnt = game->map->lnt;
	while (i <= game->data->max_row)
	{
		if (game->map->lnt != lnt)
			null_error("\033[1;33mError\nThe map isn't rectangular.\n", game);
		if (game->map->y_index == 1
			|| game->map->y_index == game->data->max_row)
			check_x_wall(game);
		else if (game->map->y_index > 1
			|| game->map->y_index < game->data->max_row)
			check_y_wall(game);
		game->map = game->map->next;
		i++;
	}
	check_dimension(lnt, game->data->max_row, game);
	while (game->map->y_index != 1)
		game->map = game->map->prev;
	game->win_x = lnt * 64;
	game->win_y = game->data->max_row * 64;
}

void	check_file(int fd, t_master *game)
{
	int		count_rows;
	char	*line;

	line = get_next_line(fd);
	count_rows = 1;
	if (!line)
	{
		close(fd);
		null_error("\033[1;33mError\nNo Map\n", game);
	}
	game->map = NULL;
	game->map = keep_data(count_rows, line, game->map);
	get_data(line, fd, count_rows, &game->map);
	game->data->max_row = game->map->y_index;
	if (game->data->max_row <= 2)
	{
		close(fd);
		null_error("\033[1;33mError\nMap is too small.\n", game);
	}
	close(fd);
	while (game->map->prev != NULL)
		game->map = game->map->prev;
	check_map(game);
}

int	hidden_file(char **argv)
{
	int	i;

	i = 0;
	while (argv[0][i])
	{
		if (argv[0][i++] == '/')
		{
			if (argv[0][i] == '.')
				return (0);
		}
	}
	return (1);
}

void	check_all(int argc, char **argv, t_master *game)
{
	char	*str;
	int		fd;

	if (argc != 2)
		null_error("\033[1;33mError\n", game);
	if (!hidden_file(argv))
		null_error("\033[1;33mError\nBad format.\n", game);
	str = ft_strrchr(argv[0], '.');
	if (!str)
		null_error("\033[1;33mError\nBad format.\n", game);
	if (ft_strcmp(str, ".ber") != 0)
		null_error("\033[1;33mError\nBad format.\n", game);
	while (ft_strlen(str) != 4)
		str = ft_strrchr(str, '.');
	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		null_error("\033[1;33mError\nNo File\n", game);
	}
	check_file(fd, game);
	if (check_flood(game, game->data->p_x, game->data->p_y - 1) != 0)
		null_error("\033[1;33mError\nImpossible to play this game.\n", game);
}

int	main(int argc, char **argv)
{
	t_master	*game;

	game = ft_calloc(1, sizeof(t_master));
	game->data = ft_calloc(1, sizeof(t_data));
	check_all(argc, argv + 1, game);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->win_x, game->win_y, "so_long");
	graph_mlx(game);
	mlx_hook(game->mlx_win, 17, 0, x_exit, game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
