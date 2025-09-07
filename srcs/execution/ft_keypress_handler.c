/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:20:27 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:30:41 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function updates the player's position by moving them forward
 * based on the current direction they are facing. It modifies the
 * player's coordinates stored in the `t_data` structure.
 * Checking for a collision with a wall when moving forward.
 * If the player has not encountered the wall, his coordinates are updated.
 */
void	ft_move_forward(t_data *store)
{
	double		new_x;
	double		new_y;
	t_player	*p;
	char		**grid;
	double		speed;

	grid = store->map->map_grid;
	speed = PLAYERS_SPEED;
	p = store->player;
	new_x = p->dir_x * speed;
	new_y = p->dir_y * speed;
	if (grid[(int)p->y][(int)(p->x + p->dir_x * speed)] != WALL)
		p->x += new_x;
	if (grid[(int)(p->y + p->dir_y * speed)][(int)p->x] != WALL)
		p->y += new_y;
	store->player = p;
}

void	ft_move_back(t_data *store)
{
	double		new_x;
	double		new_y;
	t_player	*p;
	char		**grid;
	double		speed;

	grid = store->map->map_grid;
	speed = PLAYERS_SPEED;
	p = store->player;
	new_x = p->dir_x * speed;
	new_y = p->dir_y * speed;
	if (grid[(int)p->y][(int)(p->x - p->dir_x * speed)] != WALL)
		p->x -= new_x;
	if (grid[(int)(p->y - p->dir_y * speed)][(int)p->x] != WALL)
		p->y -= new_y;
	store->player = p;
}

void	ft_move_left(t_data *store)
{
	double		new_x;
	double		new_y;
	t_player	*p;
	char		**grid;
	double		speed;

	grid = store->map->map_grid;
	speed = PLAYERS_SPEED;
	p = store->player;
	new_x = p->vector_x * speed;
	new_y = p->vector_y * speed;
	if (grid[(int)p->y][(int)(p->x - p->vector_x * speed)] == '0')
		p->x -= new_x;
	if (grid[(int)(p->y - p->vector_y * speed)][(int)p->x] == '0')
		p->y -= new_y;
	store->player = p;
}

void	ft_move_right(t_data *store)
{
	double		new_x;
	double		new_y;
	t_player	*p;
	char		**grid;
	double		speed;

	grid = store->map->map_grid;
	speed = PLAYERS_SPEED;
	p = store->player;
	new_x = p->vector_x * speed;
	new_y = p->vector_y * speed;
	if (grid[(int)p->y][(int)(p->x + p->vector_x * speed)] == '0')
		p->x += new_x;
	if (grid[(int)(p->y + p->vector_y * speed)][(int)p->x] == '0')
		p->y += new_y;
	store->player = p;
}
