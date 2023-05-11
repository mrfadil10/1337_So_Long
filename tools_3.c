/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:12:16 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/09 15:07:19 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//void	ft_error(char *str)
//{
//	write(2, "ERROR ", 6);
//	write(2, &str, ft_strlen(str));
//	exit(1);
//}

void	r_walls(t_master *game)
{
	game->n_wall = mlx_xpm_file_to_image(game->mlx, "xpm/Walls.xpm",
			&game->x, &game->y);
	if (game->n_wall == NULL)
	{
		free_element(game->n_wall);
		exit (1);
	}
	game->s_wall = mlx_xpm_file_to_image(game->mlx, "xpm/Walls.xpm",
			&game->x, &game->y);
	if (game->s_wall == NULL)
	{
		free_element(game->s_wall);
		exit (1);
	}
}

void	c_walls(t_master *game)
{
	game->e_wall = mlx_xpm_file_to_image(game->mlx, "xpm/Walls.xpm",
			&game->x, &game->y);
	if (game->e_wall == NULL)
	{
		free_element(game->e_wall);
		exit (1);
	}
	game->w_wall = mlx_xpm_file_to_image(game->mlx, "xpm/Walls.xpm",
			&game->x, &game->y);
	if (game->w_wall == NULL)
	{
		free_element(game->w_wall);
		exit (1);
	}
}

//void	put_corners(t_master *game)
//{
//	game->o_wall = mlx_xpm_file_to_image(game->mlx, "xpm/Obs.xpm",
//			&game->x, &game->y);
//	if (game->o_wall == NULL)
//	{
//		free_element(game->o_wall);
//		exit(1);
//	}
//	mlx_put_image_to_window(game->mlx, game->mlx_win, game->o_wall, 0, 0);
//	mlx_put_image_to_window(game->mlx, game->mlx_win, game->o_wall,
//		game->win_x - 64, 0);
//	mlx_put_image_to_window(game->mlx, game->mlx_win, game->o_wall,
//		0, game->win_y - 64);
//	mlx_put_image_to_window(game->mlx, game->mlx_win, game->o_wall,
//		game->win_x - 64, game->win_y - 64);
//}

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
//void init_pics()
//{
//	walls = dysafg?;
//	groud = jcgcgcj;
//	player = ffdshg;
//	hsdfhfhag = dfagffh;
//	if(!jgajfghg||!hfgdhsfg||!hg||!dfh)
//		ft_error("no image");
//}