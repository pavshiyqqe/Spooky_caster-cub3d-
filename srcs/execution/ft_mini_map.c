/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:15:27 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:30:29 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_draw_square(int x, int y, t_data *s, int color)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;
	int	size;

	size = (HEIGHT / s->map->height) / 5;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel_x = x * size + i + 17;
			pixel_y = y * size + j - 17;
			pixel_y += (HEIGHT - (s->map->height * size));
			ft_mlx_pixel_put(pixel_x, pixel_y, s->main, color);
			j++;
		}
		i++;
	}
}

static void	ft_draw_map_element(char element, int x, int y, t_data *store)
{
	if (element == WALL)
		ft_draw_square(x, y, store, store->map->c_color);
	else if (element == FLOOR)
		ft_draw_square(x, y, store, store->map->f_color);
}

static void ft_draw_triangle(int x, int y, double dir_x, double dir_y, t_data *s, int color)
{
	double triangle_size;
	int p1_x;
	int p1_y;
	int p2_x;
	int p2_y;
	int p3_x;
	int p3_y;
   
	triangle_size = 10;
	p1_x = x + dir_x * triangle_size;
	p1_y = y + dir_y * triangle_size;
	p2_x = x + (dir_x * (triangle_size / 2)) - (dir_y * (triangle_size / 2));
	p2_y = y + (dir_y * (triangle_size / 2)) + (dir_x * (triangle_size / 2));
	p3_x = x + (dir_x * (triangle_size / 2)) + (dir_y * (triangle_size / 2));
	p3_y = y + (dir_y * (triangle_size / 2)) - (dir_x * (triangle_size / 2));

	ft_mlx_pixel_put(p1_x, p1_y, s->main, color);
	ft_mlx_pixel_put(p2_x, p2_y, s->main, color);
	ft_mlx_pixel_put(p3_x, p3_y, s->main, color);
}

void	ft_mini_map(t_data *store)
{
	int	y;
	int	x;

	y = -1;
	while (store->map->map_grid[++y])
	{
		x = -1;
		while (store->map->map_grid[y][++x])
			ft_draw_map_element(store->map->map_grid[y][x], x, y, store);
	}
	ft_draw_square(store->player->x, store->player->y, store, 0x000);
	ft_draw_triangle(
		store->player->x * (HEIGHT / store->map->height) / 5 + 9, 
		store->player->y * (HEIGHT / store->map->height) / 5 - 14 + (HEIGHT - (store->map->height * (HEIGHT / store->map->height) / 5)), 
		store->player->dir_x,
		store->player->dir_y, 
		store, 0x000);
}
