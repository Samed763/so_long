/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sadinc@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:47:11 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/24 17:33:49 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flag_f(t_game *game)
{
	if (game->map[game->th_y][game->th_x] == 'P')
	{
		game->player.x = game->th_x;
		game->player.y = game->th_y;
		game->player_count++;
	}
	else if (game->map[game->th_y][game->th_x] == 'E')
	{
		game->exit_x = game->th_x;
		game->exit_y = game->th_y;
		game->exit_count++;
	}
	else if (game->map[game->th_y][game->th_x] == 'C')
		game->collectibles_count++;
}

static void	flag_c(t_game *game)
{
	if (game->visited[game->th_y][game->th_x] == 'E')
	{
		game->controls.fill_exit_count++;
		return ;
	}
	else if (game->visited[game->th_y][game->th_x] == 'C')
		game->controls.fill_collectible_count++;
}

static void	thing_place(t_game *game, char thing, char flag)
{
	if (flag == 'f' && game->map[game->th_y][game->th_x] == thing)
	{
		flag_f(game);
	}
	else if (flag == 'c' && game->visited[game->th_y][game->th_x] == thing)
	{
		flag_c(game);
	}
}

void	find_thing(t_game *game, char thing, char flag)
{
	game->th_y = 0;
	while (game->map[game->th_y])
	{
		game->th_x = 0;
		while (game->map[game->th_y][game->th_x])
		{
			if (check_chars("01PEC", game->map[game->th_y][game->th_x]))
			{
				game->controls.any_other_char = 1;
				error_free_all(game);
			}
			thing_place(game, thing, flag);
			game->th_x++;
		}
		game->th_y++;
	}
}

void	find_thing_call(t_game *game)
{
	find_thing(game, 'P', 'f');
	find_thing(game, 'E', 'f');
	find_thing(game, 'C', 'f');
	game->visited = copy_map(game->map);
	if (!game->visited)
	{
		ft_putstr("Error ");
		ft_putstr("Memory allocation failed");
		free_all(game);
	}
	fill_flood_check(game->map, game->player.y, game->player.x, game->visited);
	find_thing(game, 'E', 'c');
	find_thing(game, 'C', 'c');
	free_map(game->visited);
	game->visited = NULL;
}
