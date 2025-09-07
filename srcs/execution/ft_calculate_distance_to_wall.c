/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_distance_to_wall.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:55:33 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:32:59 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function computes the distance from the player's position to the wall
 * based on the ray's direction and the player's position.
 */
static double	ft_calculate_wall_distance(t_ray *ray, t_player *p)
{
	double	dist;

	if (ray->side == WEST || ray->side == EAST)
		dist = (ray->map_x - p->x + (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		dist = (ray->map_y - p->y + (1 - ray->step_y) / 2) / ray->raydir_y;
	return (dist);
}

/*
 * This function computes the distance from the player's current position
 * to the nearest wall in the game environment. The calculated distance
 * is stored in the provided data structure.
 */
void	ft_calculate_distance_to_wall(t_data *store)
{
	double	wall_dist;

	wall_dist = ft_calculate_wall_distance(store->ray, store->player);
	if (wall_dist < DEFAULT_DOUBLE)
		store->ray->walldist = DEFAULT_DOUBLE;
	else
		store->ray->walldist = wall_dist;
}
