/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digital_differential_analyzer.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:54:14 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:32:14 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Refactoring sides, for use e_num fron Hannah's header file:
North 0 -> 0
East 1 -> 3
South 2 -> 1
West 3 -> 2
 */

#include "cub3D.h"

#define STEP_NEGATIVE -1
#define STEP_POSITIVE 1

/*
 * This function implements the DDA algorithm to perform line drawing or other
 * related operations. The DDA algorithm is a simple and efficient algorithm
 * used in computer graphics to interpolate values over an interval between
 */
void	ft_digital_differential_analyzer(t_data *store)
{
	while (!store->ray->hit)
	{
		if (store->ray->sidedist_x < store->ray->sidedist_y)
		{
			store->ray->sidedist_x += store->ray->deltadist_x;
			store->ray->map_x += store->ray->step_x;
			if (store->ray->step_x == STEP_NEGATIVE)
				store->ray->side = WEST;
			else if (store->ray->step_x == STEP_POSITIVE)
				store->ray->side = EAST;
		}
		else
		{
			store->ray->sidedist_y += store->ray->deltadist_y;
			store->ray->map_y += store->ray->step_y;
			if (store->ray->step_y == STEP_NEGATIVE)
				store->ray->side = NORTH;
			else if (store->ray->step_y == STEP_POSITIVE)
				store->ray->side = SOUTH;
		}
		if (store->map->map_grid[store->ray->map_y][store->ray->map_x] == WALL)
			store->ray->hit = true;
	}
	ft_calculate_distance_to_wall(store);
}
