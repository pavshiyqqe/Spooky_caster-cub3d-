/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_drawing_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:33:15 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:31:26 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function sets up the direction of the ray based on the x-coordinate
 * of the screen. It updates the relevant fields in the provided `store` 
 * structure to reflect the calculated ray direction.
 */
static void	init_ray_direction(t_data *store, int x)
{
	t_player	*p;

	p = store->player;
	store->ray->camera = 2 * x / (double)(WIDTH)-1;
	store->ray->raydir_x = p->dir_x + p->vector_x * store->ray->camera;
	store->ray->raydir_y = p->dir_y + p->vector_y * store->ray->camera;
}

/*
 * This function sets up the initial parameters for raycasting, which is used
 * in the rendering process of the 3D environment. It prepares the necessary
 * data in the provided `store` structure.
 */
static void	init_ray_position(t_data *store)
{
	store->ray->map_x = (int)(store->player->x);
	store->ray->map_y = (int)(store->player->y);
}

/*
 * This function sets up the initial distances for the rays used in the
 * rendering process. It is a static function, meaning it is only accessible
 * within the file it is defined in.
 */
static void	init_ray_distances(t_data *store)
{
	store->ray->deltadist_x = fabs(1 / store->ray->raydir_x);
	store->ray->deltadist_y = fabs(1 / store->ray->raydir_y);
}

/*
 * This function sets up the necessary parameters in the t_data structure
 * to prepare for drawing operations at the specified x coordinate.
 */
void	ft_init_drawing_params(t_data *store, int x)
{
	init_ray_direction(store, x);
	init_ray_position(store);
	init_ray_distances(store);
	store->ray->hit = false;
}
