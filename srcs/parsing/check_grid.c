/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:14:20 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/03 14:05:21 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

bool	check_size_map(t_map *map)
{
	if (map->height <= 2)
		return (false);
	return (true);
}

bool	check_walls(t_map *map)
{
	if (!check_top_bottom_walls(map->map_grid[0])
		|| !check_top_bottom_walls(map->map_grid[map->height - 1]))
		return (false);
	if (!check_no_output(map->map_grid))
		return (false);
	return (true);
}

bool	check_other_char(char *line)
{
	int	i;
	int	end;

	i = 0;
	while (line[i] == ' ')
		i++;
	end = ft_strlen(line) - 1;
	while (i <= end)
	{
		if (line[i] != '1' && line[i] != '0'
			&& !is_player(line[i]) && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	check_player_other_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_grid[i])
	{
		j = 0;
		if ((i != 0 && i != map->height - 1)
			&& !check_other_char(map->map_grid[i]))
			return (false);
		while (map->map_grid[i][j])
		{
			if (is_player(map->map_grid[i][j]) == 1)
				map->player++;
			j++;
		}
		i++;
	}
	if (map->player != 1)
		return (false);
	return (true);
}

void	display_grid(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '1')
				ft_putchar_fd(35, 1);
			else if (grid[i][j] == '0')
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd(grid[i][j], 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}
