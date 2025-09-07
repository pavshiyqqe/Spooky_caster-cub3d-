/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:20:44 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 09:23:16 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

t_map	*init_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->filename = filename;
	map->fd = 0;
	map->height = 0;
	map->length = 0;
	map->c_color = 0;
	map->f_color = 0;
	map->player = 0;
	map->initial_map = NULL;
	map->map_grid = NULL;
	map->rgb[0] = 0;
	map->rgb[1] = 0;
	map->rgb[2] = 0;
	return (map);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->vector_x = 0;
	player->vector_y = 0;
	player->mouse_x = 0;
	return (player);
}

t_draw	*ft_init_draw(void)
{
	t_draw	*draw;

	draw = malloc(sizeof(t_draw));
	if (!draw)
		return (NULL);
	draw->wallx = DEFAULT_DOUBLE;
	draw->texx = 0;
	draw->texy = 0;
	draw->texpos = DEFAULT_DOUBLE;
	draw->step = DEFAULT_DOUBLE;
	draw->lineh = 0;
	return (draw);
}

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->raydir_x = DEFAULT_DOUBLE;
	ray->raydir_y = DEFAULT_DOUBLE;
	ray->camera = DEFAULT_DOUBLE;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->sidedist_x = DEFAULT_DOUBLE;
	ray->sidedist_y = DEFAULT_DOUBLE;
	ray->deltadist_x = DEFAULT_DOUBLE;
	ray->deltadist_y = DEFAULT_DOUBLE;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = false;
	ray->side = NORTH;
	ray->walldist = DEFAULT_DOUBLE;
	ray->start = 0;
	ray->end = 0;
	return (ray);
}

bool	init_data(t_data *data, char *file)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->main = NULL;
	data->filename = file;
	data->map = init_map(data->filename);
	if (!data->map)
		return (false);
	data->ray = init_ray();
	data->east = ft_init_texture();
	data->north = ft_init_texture();
	data->west = ft_init_texture();
	data->south = ft_init_texture();
	data->player = init_player();
	data->draw = ft_init_draw();
	data->mouse_x = WIDTH / 2;
	ft_init_animation(data);
	data->keys.w = false;
	data->keys.a = false;
	data->keys.s = false;
	data->keys.d = false;
	data->keys.left = false;
	data->keys.right = false;
	return (true);
}
