/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_start_step.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:57:53 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:32:49 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function determines the step size in the x direction for the ray
 * based on the player's position and the ray's direction. It updates the
 * ray structure with the calculated step size.
 */
static void	ft_calculate_step_x(t_ray *ray, t_player *p)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (p->x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - p->x) * ray->deltadist_x;
	}
}

static void	ft_calculate_step_y(t_ray *ray, t_player *p)
{
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (p->y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - p->y) * ray->deltadist_y;
	}
}

void	ft_calculate_start_step(t_data *store)
{
	ft_calculate_step_x(store->ray, store->player);
	ft_calculate_step_y(store->ray, store->player);
}
