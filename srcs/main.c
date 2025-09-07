/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:52:13 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 09:24:35 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_data	store;

	if (!check_argv(argc, argv[1]))
		ft_error_msg("incorrect input");
	if (!init_data(&store, argv[1]) || !ft_check_size_of_window())
		free_exit(&store, "initialization failed");
	if (!parsing(&store))
		free_exit(&store, "The map is not valid");
	if (!ft_initialisation_main_texture(&store)
		|| !ft_initialisation_textures(&store))
		free_exit(&store, "window allocation failed");
	mlx_hook(store.mlx_win, KeyPress, KeyPressMask, ft_keypress, &store);
	mlx_hook(store.mlx_win, KeyRelease, KeyReleaseMask, ft_release_key, &store);
	mlx_loop_hook(store.mlx, ft_draw, &store);
	mlx_hook(store.mlx_win, 6, 1L << 6, ft_mouse_handler, &store);
	mlx_hook(store.mlx_win, 17, 5, ft_destroy_handler, &store);
	mlx_loop(store.mlx);
	return (0);
}
