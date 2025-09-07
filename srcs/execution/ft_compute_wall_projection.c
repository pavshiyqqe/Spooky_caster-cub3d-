/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_wall_projection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:34 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:32:31 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function calculates the projection of walls based on the data
 * provided in the t_data structure. It is used in the rendering process
 * to determine how walls should be displayed on the screen.
 */
void	ft_compute_wall_projection(t_data *store)
{
	double	line_height;

	if (store->ray->walldist <= 0)
	{
		store->ray->walldist = DEFAULT_DOUBLE;
	}
	line_height = (double)HEIGHT / store->ray->walldist;
	if (isinf(line_height))
		store->draw->lineh = HEIGHT;
	else
		store->draw->lineh = (int)line_height;
	store->ray->start = (HEIGHT / 2) - (store->draw->lineh / 2);
	if (store->ray->start < 0)
		store->ray->start = 0;
	store->ray->end = (HEIGHT / 2) + (store->draw->lineh / 2);
	if (store->ray->end >= HEIGHT)
		store->ray->end = HEIGHT - 1;
}
