/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:18:43 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:32:38 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_clear_window(t_data *store, t_texture *main)
{
	free_exit(store, NULL);
	(void)main;
	if (store->mlx_win)
		mlx_destroy_window(store->mlx, store->mlx_win);
	if (store->mlx)
	{
		mlx_destroy_display(store->mlx);
		free(store->mlx);
	}
}
