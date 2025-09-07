/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:15:55 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/03 14:04:19 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	define_vector(char c, t_player *player)
{
	if (c == 'N')
	{
		player->vector_x = 0.66;
		player->vector_y = 0;
	}
	else if (c == 'S')
	{
		player->vector_x = -0.66;
		player->vector_y = 0;
	}
	else if (c == 'E')
	{
		player->vector_x = 0;
		player->vector_y = 0.66;
	}
	else if (c == 'W')
	{
		player->vector_x = 0;
		player->vector_y = -0.66;
	}
}

/*
	(0,0) → X (Est)
	|
	|
	↓ Y (South)
*/
static void	direction_player(char c, t_player *player)
{
	if (c == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
	}
	else if (c == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
	}
	else if (c == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
	}
	else if (c == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
	}
}

void	find_player(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_grid[y])
	{
		x = 0;
		while (map->map_grid[y][x])
		{
			if (is_player(map->map_grid[y][x]) == 1)
			{
				direction_player(map->map_grid[y][x], data->player);
				define_vector(map->map_grid[y][x], data->player);
				data->player->x = x + 0.01;
				data->player->y = y + 0.01;
				map->map_grid[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}
