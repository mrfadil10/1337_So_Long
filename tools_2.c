/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:59:12 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/11 22:52:13 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(int i, int row, t_master *game)
{
	game->player = mlx_xpm_file_to_image(game->mlx, "xpm/Player_3.0.xpm",
			&game->x, &game->y);
	if (game->player == NULL)
	{
		free_element(game->player);
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player,
		i * 64, (row * 64) - 64);
	game->data->p_x = i;
	game->data->p_y = row;
}

void	put_collects(int i, int row, t_master *game)
{
	game->collect = mlx_xpm_file_to_image(game->mlx, "xpm/collectible.xpm",
			&game->x, &game->y);
	if (game->collect == NULL)
	{
		free_element(game->collect);
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect,
		i * 64, (row * 64) - 64);
}

void	put_obstacles(int i, int row, t_master *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->o_wall,
		i * 64, (row * 64) - 64);
}

void	put_unlock(int i, int row, t_master *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->op_exit,
		i * 64, (row * 64) - 64);
}

void	put_exit(int i, int row, t_master *game)
{
	game->op_exit = mlx_xpm_file_to_image(game->mlx, "xpm/opened_door.xpm",
			&game->x, &game->y);
	if (game->op_exit == NULL)
	{
		free_element(game->op_exit);
		exit(1);
	}
	game->cl_exit = mlx_xpm_file_to_image(game->mlx, "xpm/closed_door.xpm",
			&game->x, &game->y);
	if (game->cl_exit == NULL)
	{
		free_element(game->cl_exit);
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->cl_exit, i * 64, (row * 64) - 64);
}
