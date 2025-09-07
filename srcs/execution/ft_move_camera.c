/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:33:21 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:29:25 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_look_right(t_data *store)
{
	t_player	*p;
	double		speed;
	double		old_player_x;
	double		old_camera_x;

	speed = ROTATE_SPEED;
	p = store->player;
	old_player_x = p->dir_x;
	old_camera_x = p->vector_x;
	p->dir_x = p->dir_x * cos(speed) - p->dir_y * sin(speed);
	p->dir_y = old_player_x * sin(speed) + p->dir_y * cos(speed);
	p->vector_x = p->vector_x * cos(speed) - p->vector_y * sin(speed);
	p->vector_y = old_camera_x * sin(speed) + p->vector_y * cos(speed);
	store->player = p;
}

void	ft_look_left(t_data *store)
{
	t_player	*p;
	double		speed;
	double		old_player_x;
	double		old_camera_x;

	speed = ROTATE_SPEED;
	p = store->player;
	old_player_x = p->dir_x;
	old_camera_x = p->vector_x;
	p->dir_x = p->dir_x * cos(-speed) - p->dir_y * sin(-speed);
	p->dir_y = old_player_x * sin(-speed) + p->dir_y * cos(-speed);
	p->vector_x = p->vector_x * cos(-speed) - p->vector_y * sin(-speed);
	p->vector_y = old_camera_x * sin(-speed) + p->vector_y * cos(-speed);
	store->player = p;
}
