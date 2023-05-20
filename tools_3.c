/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:12:16 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/19 10:20:28 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *message, char *file, int line)
{
	write(2, message, ft_strlen(message));
	write(2, "\nFILE: ", 8);
	write(2, file, ft_strlen(file));
	write(2, "\nLINE: ", 8);
	ft_putnbr_fd(line, 2);
	write(2, "\n", 1);
	exit(1);
}

void	r_walls(t_master *game)
{
	game->n_wall = mlx_xpm_file_to_image(game->mlx, "xpm/Walls.xpm",
			&game->x, &game->y);
	if (!(game->n_wall))
	{
		free_element(game->n_wall);
		ft_error("\033[1;31mError: can't load xpm/Walls.xpm!",
			__FILE__, __LINE__);
	}
	game->s_wall = mlx_xpm_file_to_image(game->mlx, "xpm/Walls.xpm",
			&game->x, &game->y);
	if (!(game->s_wall))
	{
		free_element(game->s_wall);
		ft_error("\033[1;31mError: can't load xpm/Walls.xpm!",
			__FILE__, __LINE__);
	}
}

void	c_walls(t_master *game)
{
	game->e_wall = mlx_xpm_file_to_image(game->mlx, "xpm/Walls.xpm",
			&game->x, &game->y);
	if (!(game->e_wall))
	{
		free_element(game->e_wall);
		ft_error("\033[1;31mError: can't load xpm/Walls.xpm!",
			__FILE__, __LINE__);
	}
	game->w_wall = mlx_xpm_file_to_image(game->mlx, "xpm/Walls.xpm",
			&game->x, &game->y);
	if (!(game->w_wall))
	{
		free_element(game->w_wall);
		ft_error("\033[1;31mError: can't load xpm/Walls.xpm!",
			__FILE__, __LINE__);
	}
}

void	put_row_walls(t_master *game)
{
	int	position;

	position = 0;
	r_walls(game);
	while (position != game->win_x)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->n_wall, position, 0);
		position += 64;
	}
	position = 0;
	while (position != game->win_x)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->s_wall, position, game->win_y - 64);
		position += 64;
	}
}

void	put_col_walls(t_master *game)
{
	int	position;

	position = 64;
	c_walls(game);
	while (position != game->win_y)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->n_wall, 0, position);
		position += 64;
	}
	position = 0;
	while (position != game->win_y)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->s_wall, game->win_x - 64, position);
		position += 64;
	}
}
