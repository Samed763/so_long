/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sdinc763@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:32:54 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/21 16:55:40 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_problem(t_game *game)
{
	if (game->controls.any_empty_line)
		ft_putstr("Empty Line in Map ");
	else if (game->controls.any_other_char)
		ft_putstr("Wrong Character in Map ");
	else if (game->controls.fill_exit_count)
		ft_putstr("Can't Reach the Exit ");
	else if (game->controls.fill_collectible_count > 0)
		ft_putstr("Can't Reach the Collectibles ");
	else if (game->controls.is_closed)
		ft_putstr("Map Shape is Wrong ");
	else if (game->controls.is_rectangular)
		ft_putstr("Map Not Rectangular ");
	ft_putstr("\n");
}

static void	check_top_bottom(t_game *game)
{
	int	x;

	x = 0;
	while (x < ft_strlen_to_n(game->map[0]))
	{
		if (game->map[0][x] != '1')
		{
			game->controls.is_closed = 1;
		}
		x++;
	}
	x = 0;
	while (x < ft_strlen_to_n(game->map[game->map_height - 1]))
	{
		if (game->map[game->map_height - 1][x] != '1')
		{
			game->controls.is_closed = 1;
		}
		x++;
	}
}

static void	check_left_right(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1')
		{
			game->controls.is_closed = 1;
		}
		y++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][game->map_width - 1] != '1')
		{
			game->controls.is_closed = 1;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	check_left_right(game);
	check_top_bottom(game);
	if (game->controls.fill_collectible_count > 0 || game->player_count != 1
		|| game->exit_count != 1 || game->controls.is_rectangular == 1
		|| game->controls.is_closed == 1 || game->collectibles_count <= 0
		|| game->controls.fill_exit_count == 1
		|| game->controls.any_empty_line == 1)
	{
		error_free_all(game);
	}
}
