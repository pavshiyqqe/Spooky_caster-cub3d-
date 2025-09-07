/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:07:55 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/03 14:07:04 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	ft_free_texture(t_texture *texture, void *mlx)
{
	if (texture->image)
		mlx_destroy_image(mlx, texture->image);
	texture->image = NULL;
	if (texture->path)
		free(texture->path);
	texture->path = NULL;
	free(texture);
}

void	ft_free_textures(t_data *data)
{
	if (data->north)
		ft_free_texture(data->north, data->mlx);
	if (data->south)
		ft_free_texture(data->south, data->mlx);
	if (data->west)
		ft_free_texture(data->west, data->mlx);
	if (data->east)
		ft_free_texture(data->east, data->mlx);
	if (data->main)
		ft_free_texture(data->main, data->mlx);
}

void	ft_free_sprite(t_animation *animation, void *mlx)
{
	if (animation->frames)
	{
		while (animation->frame_count--)
		{
			if (animation->frames[animation->frame_count].image)
				mlx_destroy_image(mlx,
					animation->frames[animation->frame_count].image);
			animation->frames[animation->frame_count].image = NULL;
			animation->frames[animation->frame_count].path = NULL;
		}
		free(animation->frames);
		animation->frames = NULL;
	}
	free(animation);
}

void	free_exit(t_data *data, char *error)
{
	if (!data)
		return ;
	ft_free_textures(data);
	ft_free_sprite(data->animation, data->mlx);
	if (data->player)
		free(data->player);
	if (data->ray)
		free(data->ray);
	if (data->draw)
		free(data->draw);
	if (data->map->initial_map)
		free_tab(data->map->initial_map);
	if (data->map->map_grid)
		free_tab(data->map->map_grid);
	if (data->map)
		free(data->map);
	if (error)
		ft_error_msg(error);
}

void	ft_error_msg(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}
