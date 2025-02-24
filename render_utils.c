/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sdinc763@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 02:22:06 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/23 16:53:59 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x * 64, y
		* 64);
}

void	put_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * 64,
		y * 64);
}

void	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x * 64,
		y * 64);
}

void	put_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x * 64, y
		* 64);
}

void	put_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible, x
		* 64, y * 64);
}
