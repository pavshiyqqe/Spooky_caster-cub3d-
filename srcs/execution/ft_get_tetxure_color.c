/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetxure_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:38:15 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:31:40 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function retrieves the color value from the texture `t` at the
 * coordinates (`texy`, `texx`) and returns it as an unsigned integer.
 */
static unsigned int	ft_write_color(t_texture *t, int texy, int texx)
{
	return (((unsigned int *)(t->address))[t->height * texy + texx]);
}

/*
 * This function extracts the color value from the texture data stored in the
 * provided `t_data` structure. The exact mechanism of how the color is
 * retrieved depends on the implementation details of the `t_data` structure.
 */
unsigned int	ft_get_tetxure_color(t_data *store)
{
	unsigned int	bin_color;
	int				side;
	t_draw			*draw;

	bin_color = 0;
	side = store->ray->side;
	draw = store->draw;
	if (side == WEST)
		bin_color = ft_write_color(store->west, draw->texy, draw->texx);
	else if (side == EAST)
		bin_color = ft_write_color(store->east, draw->texy, draw->texx);
	else if (side == NORTH)
		bin_color = ft_write_color(store->north, draw->texy, draw->texx);
	else if (side == SOUTH)
		bin_color = ft_write_color(store->south, draw->texy, draw->texx);
	return (bin_color);
}
