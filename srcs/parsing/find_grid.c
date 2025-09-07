/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 04:59:12 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/03 14:02:56 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	find_start(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == '1')
			return (i);
		i++;
	}
	return (-1);
}

int	find_end(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	while (i-- >= 0)
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == '1')
			return (i);
	}
	return (-1);
}

char	**extract_map(char **dirty, int start, int end)
{
	char	**map;
	int		i;

	i = 0;
	if (start == -1 || end == -1 || start > end)
		return (NULL);
	map = malloc(sizeof(char *) * (end - start + 2));
	if (!map)
		return (NULL);
	while (start <= end)
	{
		map[i] = ft_remove_newline(dirty[start]);
		start++;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	find_longest_line(char **map)
{
	int	i;
	int	j;
	int	longest;

	i = 0;
	longest = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j > longest)
			longest = j;
		i++;
	}
	return (longest);
}



bool	find_grid(t_map *map, char **dirty_map)
{
	int	start;
	int	end;

	start = find_start(dirty_map);
	if (start == -1)
		return (false);
	end = find_end(dirty_map);
	map->height = end - start + 1;
	map->map_grid = extract_map(dirty_map, start, end);
	if (!map->map_grid)
		return (false);
	map->length = find_longest_line(map->map_grid);
	display_grid(map->map_grid);
	return (true);
}
	