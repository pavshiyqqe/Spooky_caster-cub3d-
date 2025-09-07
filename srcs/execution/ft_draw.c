/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:43:54 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:31:49 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_floor_and_ceiling(t_data *store, int f_color, int c_color)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				ft_mlx_pixel_put(x, y, store->main, c_color);
			else
				ft_mlx_pixel_put(x, y, store->main, f_color);
		}
	}
}

void	ft_raycasting(t_data *store)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		ft_init_drawing_params(store, x);
		ft_calculate_start_step(store);
		ft_digital_differential_analyzer(store);
		ft_compute_wall_projection(store);
		ft_draw_line_of_texture(store, x);
	}
}

void	ft_keypress_event(t_data *store)
{
	if (store->keys.w)
		ft_move_forward(store);
	if (store->keys.a)
		ft_move_left(store);
	if (store->keys.s)
		ft_move_back(store);
	if (store->keys.d)
		ft_move_right(store);
	if (store->keys.left)
		ft_look_left(store);
	if (store->keys.right)
		ft_look_right(store);
}

int	ft_draw(t_data *store)
{
	t_data	*s;

	s = store;
	ft_keypress_event(s);
	ft_floor_and_ceiling(s, s->map->f_color, s->map->c_color);
	ft_raycasting(s);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->main->image, 0, 0);
	ft_mini_map(s);
	return (1);
}
