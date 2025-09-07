/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:40:58 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/03 14:05:05 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	fill_copy_lines(t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return ;
	while (map->initial_map)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->initial_map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	close(fd);
}

/*
	The function makes the copy of .cub file and stores it in the map
	structure.
*/
bool	extract_info(t_map *map)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return (false);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\0')
			break ;
		i++;
		free(line);
	}
	close(fd);
	map->initial_map = malloc(sizeof(char *) * (i + 1));
	if (!map->initial_map)
		return (false);
	map->initial_map[i] = NULL;
	fill_copy_lines(map);
	return (true);
}

static bool	order_in_file(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\n')
			{
				if (ft_isalpha(map[i][j]))
					return (true);
				else if (ft_isdigit(map[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	map_is_valid(t_data *data, t_map *map)
{
	if (!extract_info(map))
		return (false);
	if (!order_in_file(map->initial_map))
		return (false);
	if (!check_textures_colors(data, map))
		return (false);
	if (!find_grid(map, map->initial_map))
		return (false);
	if (!check_grid_map(map))
		return (false);
	else
		return (true);
}
