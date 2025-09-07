/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:56:45 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:29:03 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_release_key(int keynum, t_data *data)
{
	if (keynum == KEY_W)
		data->keys.w = false;
	if (keynum == KEY_S)
		data->keys.s = false;
	if (keynum == KEY_A)
		data->keys.a = false;
	if (keynum == KEY_D)
		data->keys.d = false;
	if (keynum == KEY_LEFT)
		data->keys.left = false;
	if (keynum == KEY_RIGHT)
		data->keys.right = false;
	return (0);
}

int	ft_keypress(int keynum, t_data *data)
{
	if (keynum == KEY_W)
		data->keys.w = true;
	if (keynum == KEY_S)
		data->keys.s = true;
	if (keynum == KEY_A)
		data->keys.a = true;
	if (keynum == KEY_D)
		data->keys.d = true;
	if (keynum == KEY_LEFT)
		data->keys.left = true;
	if (keynum == KEY_RIGHT)
		data->keys.right = true;
	if (keynum == KEY_ESC)
	{
		ft_destroy_handler(data);
		exit(0);
	}
	return (0);
}
