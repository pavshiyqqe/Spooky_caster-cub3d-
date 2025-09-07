/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_textures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:34:04 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:30:55 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function sets up the north texture for the game by loading the texture
 * data and storing it in the provided data structure.
 */
static int	ft_initialisation_north_texture(t_data *store, int h, int w)
{
	char	*path;

	path = ft_remove_newline(store->north->path);
	store->north->image = mlx_xpm_file_to_image(store->mlx, path, &w, &h);
	if (!store->north->image)
		return (1);
	store->north->address = mlx_get_data_addr(store->north->image,
			&store->north->bits_per_pixel, &store->north->line_length,
			&store->north->endian);
	store->north->width = w;
	store->north->height = h;
	free(path);
	return (0);
}

static int	ft_initialisation_east_texture(t_data *store, int h, int w)
{
	char	*path;

	path = ft_remove_newline(store->east->path);
	store->east->image = mlx_xpm_file_to_image(store->mlx, path, &w, &h);
	if (!store->east->image)
		return (1);
	store->east->address = mlx_get_data_addr(store->east->image,
			&store->east->bits_per_pixel, &store->east->line_length,
			&store->east->endian);
	store->east->width = w;
	store->east->height = h;
	free(path);
	return (0);
}

static int	ft_initialisation_south_texture(t_data *store, int h, int w)
{
	char	*path;

	path = ft_remove_newline(store->south->path);
	store->south->image = mlx_xpm_file_to_image(store->mlx, path, &w, &h);
	if (!store->south->image)
		return (1);
	store->south->address = mlx_get_data_addr(store->south->image,
			&store->south->bits_per_pixel, &store->south->line_length,
			&store->south->endian);
	store->south->width = w;
	store->south->height = h;
	free(path);
	return (0);
}

static int	ft_initialisation_west_texture(t_data *store, int h, int w)
{
	char	*path;

	path = ft_remove_newline(store->west->path);
	store->west->image = mlx_xpm_file_to_image(store->mlx, path, &w, &h);
	if (!store->west->image)
		return (0);
	store->west->address = mlx_get_data_addr(store->west->image,
			&store->west->bits_per_pixel, &store->west->line_length,
			&store->west->endian);
	store->west->width = w;
	store->west->height = h;
	free(path);
	return (0);
}

int	ft_initialisation_textures(t_data *store)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	if (store->north)
		if (ft_initialisation_north_texture(store, h, w))
			return (ft_error_msg("north texture can't loaded"), 0);
	if (store->east)
		if (ft_initialisation_east_texture(store, h, w))
			return (ft_error_msg("east texture can't loaded"), 0);
	if (store->south)
		if (ft_initialisation_south_texture(store, h, w))
			return (ft_error_msg("south texture can't loaded"), 0);
	if (store->west)
		if (ft_initialisation_west_texture(store, h, w))
			return (ft_error_msg("west texture can't loaded"), 0);
	ft_initialisation_sprites(store, h, w);
	return (1);
}
