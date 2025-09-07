/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_of_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:39 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:32:01 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_random_wall_sprite(t_data *s)
{
	int	is_wall;
	int	every_ten;

	is_wall = s->map->map_grid[s->ray->map_y][s->ray->map_x] != WALL;
	every_ten = (s->ray->map_x + s->ray->map_y) % 10 != 0;
	return (is_wall || !LOAD_SPRITES || every_ten);
}

static void	ft_draw_line(t_data *s, t_sprite *frame, int height_tex, int x)
{
	int				y;
	unsigned int	color;

	y = s->ray->start - 1;
	while (++y <= s->ray->end)
	{
		if (y < 0 || y >= HEIGHT)
			continue ;
		if (isnan(s->draw->texpos) || isinf(s->draw->texpos))
			s->draw->texpos = 0.0;
		s->draw->texy = ((int)s->draw->texpos) & (height_tex - 1);
		s->draw->texpos += s->draw->step;
		if (ft_random_wall_sprite(s))
		{
			color = ft_get_tetxure_color(s);
		}
		else
		{
			color = *(unsigned int *)(frame->address + (s->draw->texy
						* frame->line_length + s->draw->texx
						* (frame->bits_per_pixel / 8)));
		}
		ft_mlx_pixel_put(x, y, s->main, color);
	}
}

/*
 * This function is responsible for drawing a vertical line of texture
 * on the screen at the specified x-coordinate. It uses the data stored
 * in the t_data structure to determine the texture and other parameters
 * required for drawing.
 */
void	ft_draw_line_of_texture(t_data *store, int x)
{
	int			height_tex;
	t_sprite	*frame;

	frame = NULL;
	ft_texture_params_init(store);
	if (!ft_random_wall_sprite(store))
	{
		ft_update_sprite_animation(store->animation);
		frame = &store->animation->frames[store->animation->current_frame];
		height_tex = frame->height;
	}
	else
	{
		height_tex = store->north->height;
	}
	ft_draw_line(store, frame, height_tex, x);
}
