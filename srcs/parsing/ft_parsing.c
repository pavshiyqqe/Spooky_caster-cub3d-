/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:29:48 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/03 14:03:48 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

bool	check_grid_map(t_map *map)
{
	if (!check_size_map(map) || !check_walls(map)
		|| !check_player_other_char(map))
	{
		return (false);
	}
	return (true);
}

bool	parsing(t_data *data)
{
	if (!map_is_valid(data, data->map))
	{
		return (false);
	}
	if (data->map->player == 1)
		find_player(data, data->map);
	return (true);
}

void	affiche_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map_grid)
	{
		while (map->map_grid[i])
		{
			printf("%s", map->map_grid[i]);
			i++;
		}
	}
	i = 0;
	if (map->initial_map)
	{
		while (map->initial_map[i])
		{
			printf("%s", map->initial_map[i]);
			i++;
		}
	}
	printf("%#x\n", map->f_color);
	printf("%#x\n", map->c_color);
}
