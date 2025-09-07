/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprite_frames.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:01:58 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:31:17 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_init_sprites(t_data *s, char **path, int w, int h)
{
	int			i;
	t_animation	*anim;

	i = -1;
	anim = s->animation;
	while (++i < anim->frame_count)
	{
		anim->frames[i].path = path[i];
		anim->frames[i].bits_per_pixel = 0;
		anim->frames[i].line_length = 0;
		anim->frames[i].endian = 0;
		anim->frames[i].image = mlx_xpm_file_to_image(s->mlx, path[i], &w, &h);
		anim->frames[i].address = mlx_get_data_addr(anim->frames[i].image,
				&anim->frames[i].bits_per_pixel, &anim->frames[i].line_length,
				&anim->frames[i].endian);
		anim->frames[i].width = w;
		anim->frames[i].height = h;
		free(path[i]);
	}
}

int	ft_initialisation_sprites(t_data *s, int h, int w)
{
	char	*path[9];

	s->animation->frames = malloc(sizeof(t_sprite) * 9);
	if (!s->animation->frames)
		return (0);
	s->animation->frame_count = 9;
	s->animation->current_frame = 0;
	s->animation->frame_delay = FRAME_DELAY;
	s->animation->frame_timer = 0;
	path[0] = ft_strdup("./textures/sprites/1.xpm");
	path[1] = ft_strdup("./textures/sprites/2.xpm");
	path[2] = ft_strdup("./textures/sprites/3.xpm");
	path[3] = ft_strdup("./textures/sprites/4.xpm");
	path[4] = ft_strdup("./textures/sprites/5.xpm");
	path[5] = ft_strdup("./textures/sprites/6.xpm");
	path[6] = ft_strdup("./textures/sprites/7.xpm");
	path[7] = ft_strdup("./textures/sprites/8.xpm");
	path[8] = ft_strdup("./textures/sprites/9.xpm");
	ft_init_sprites(s, path, w, h);
	return (1);
}
