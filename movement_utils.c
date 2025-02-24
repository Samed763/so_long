/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sdinc763@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:02:15 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/23 16:28:22 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_floor(t_game *game)
{
	if (game->collectibles_count == 0
		&& game->map[game->player.new_y][game->player.new_x] == 'E')
	{
		ft_putstr("You won!\n");
		free_all(game);
	}
	if (game->map[game->player.new_y][game->player.new_x] == 'E')
	{
		game->map[game->player.y][game->player.x] = '0';
		put_floor(game, game->player.x, game->player.y);
		put_player(game, game->player.new_x, game->player.new_y);
		game->map[game->exit_y][game->exit_x] = 'E';
		game->player.x = game->player.new_x;
		game->player.y = game->player.new_y;
		return ;
	}
}

void	to_others(t_game *game)
{
	if (game->map[game->player.new_y][game->player.new_x] == '1')
	{
		game->map[game->player.y][game->player.x] = 'P';
		render_map(game);
		game->map[game->exit_y][game->exit_x] = 'E';
		return ;
	}
	else if (game->map[game->player.new_y][game->player.new_x] == 'C')
	{
		game->collectibles_count--;
		game->map[game->player.new_y][game->player.new_x] = 'P';
	}
	if (game->map[game->player.new_y][game->player.new_x] != 'E')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->map[game->player.new_y][game->player.new_x] = 'P';
		game->player.x = game->player.new_x;
		game->player.y = game->player.new_y;
	}
	game->map[game->exit_y][game->exit_x] = 'E';
	render_map(game);
}
