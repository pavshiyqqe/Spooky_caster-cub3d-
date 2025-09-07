/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_main_texture.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:30:48 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:31:05 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function is responsible for initializing the MLX library, which is
 * used for creating windows, handling events, and rendering graphics. It
 * sets up the necessary resources and configurations required for the
 * application to function correctly.
 */
static int	init_mlx(t_data *store)
{
	store->mlx = mlx_init();
	if (!store->mlx)
		return (0);
	store->mlx_win = mlx_new_window(store->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!store->mlx_win)
		return (0);
	return (1);
}

/*
 * This function sets up the main texture required for the application.
 * It ensures that the texture is properly loaded and ready for use.
 */
static int	init_main_texture(t_data *store)
{
	store->main = ft_init_texture();
	if (!store->main)
		return (0);
	store->main->image = mlx_new_image(store->mlx, WIDTH, HEIGHT);
	if (!store->main->image)
		return (0);
	store->main->address = mlx_get_data_addr(store->main->image,
			&(store->main->bits_per_pixel), &(store->main->line_length),
			&(store->main->endian));
	if (!store->main->address)
		return (0);
	return (1);
}

/*
 * This function sets up the main texture required for the application
 * by initializing necessary resources and configurations.
 */
int	ft_initialisation_main_texture(t_data *store)
{
	if (!init_mlx(store))
		return (0);
	if (!init_main_texture(store))
		return (0);
	return (1);
}
