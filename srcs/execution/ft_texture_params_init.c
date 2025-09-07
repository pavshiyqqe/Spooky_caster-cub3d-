/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_params_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:39:51 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:28:29 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function computes the x-coordinate on the wall where a ray intersects,
 * which is used for texture mapping in the rendering process.
 */
static void	calculate_wallx(t_data *store)
{
	t_ray	*ray;

	ray = store->ray;
	if (store->ray->side == WEST || store->ray->side == EAST)
		store->draw->wallx = store->player->y + ray->walldist * ray->raydir_y;
	else
		store->draw->wallx = store->player->x + ray->walldist * ray->raydir_x;
	store->draw->wallx -= floor(store->draw->wallx);
}

/*
 * This function computes the texture X coordinate (texX) based on the 
 * provided data store. The calculation is typically used in rendering 
 * textures on walls in a raycasting engine.
 */
static void	calculate_texx(t_data *store)
{
	int	side;
	int	width;

	width = store->north->width;
	side = store->ray->side;
	store->draw->texx = (int)(store->draw->wallx * (double)(width));
	if ((side == WEST || side == EAST) && store->ray->raydir_x < 0)
		store->draw->texx = width - store->draw->texx - 1;
	if ((side == NORTH || side == SOUTH) && store->ray->raydir_y > 0)
		store->draw->texx = width - store->draw->texx - 1;
}

/*
 * This function initializes the step and texture position parameters used
 * for texture mapping in the rendering process. It updates the relevant
 * fields in the provided `t_data` structure.
 */
static void	calculate_step_and_texpos(t_data *store)
{
	t_draw	*draw;
	int		start;
	int		height;

	height = store->north->height;
	start = store->ray->start;
	draw = store->draw;
	draw->step = 1.0 * height / draw->lineh;
	draw->texpos = (start - HEIGHT / 2 + draw->lineh / 2) * draw->step;
	store->draw = draw;
}

/*
 * This function sets up the necessary parameters for texture handling
 * within the provided data store structure. It ensures that all texture
 * related settings are properly configured before use.
 */
void	ft_texture_params_init(t_data *store)
{
	calculate_wallx(store);
	calculate_texx(store);
	calculate_step_and_texpos(store);
}
