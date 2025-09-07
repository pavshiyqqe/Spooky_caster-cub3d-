/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:20:12 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/03 14:04:51 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

char	*ft_remove_newline(char *str)
{
	char	*str2;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str2 = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			str2[j++] = str[i];
		i++;
	}
	str2[j] = '\0';
	return (str2);
}

static char	*check_acces(char *line_path, char *where)
{
	int		fd;
	char	*path;

	path = ft_remove_newline(line_path);
	if (!check_extension(path, ".xpm"))
	{
		free(path);
		return (NULL);
	}
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
	{
		ft_putstr_fd("Invalid path of texture ", 2);
		ft_putendl_fd(where, 2);
		return (NULL);
	}
	close(fd);
	return (ft_strdup(line_path));
}

bool	valide_texture(t_data *data, char *line)
{
	char	**separated;
	int		i;

	separated = ft_split(line, ' ');
	i = check_number(separated);
	if (separated && i != 2)
		return (free_tab(separated), true);
	if (!ft_strncmp(separated[0], "NO", 3) && !data->north->path)
		data->north->path = check_acces(separated[1], "north");
	else if (!ft_strncmp(separated[0], "SO", 3) && !data->south->path)
		data->south->path = check_acces(separated[1], "south");
	else if (!ft_strncmp(separated[0], "WE", 3) && !data->west->path)
		data->west->path = check_acces(separated[1], "west");
	else if (!ft_strncmp(separated[0], "EA", 3) && !data->east->path)
		data->east->path = check_acces(separated[1], "east");
	else
		return (ft_putendl_fd("Unknown key", 2),
			free_tab(separated), false);
	return (free_tab(separated), true);
}

bool	find_textures(t_data *data, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->initial_map[i])
	{
		j = 0;
		while (ft_isspace(map->initial_map[i][j]))
			j++;
		if (map->initial_map[i][j] == '1')
			break ;
		if ((map->initial_map[i][j] != 'F' && map->initial_map[i][j] != 'C')
			&& !valide_texture(data, map->initial_map[i]))
			return (false);
		i++;
	}
	if (!data->north->path || !data->south->path || !data->west->path
		|| !data->east->path)
		return (false);
	return (true);
}

bool	check_textures_colors(t_data *data, t_map *map)
{
	if (!find_textures(data, map))
	{
		ft_putstr_fd("Invalid textures\n", 2);
		return (false);
	}
	if (!find_colors(map))
	{
		ft_putstr_fd("Invalid colors\n", 2);
		return (false);
	}
	return (true);
}
