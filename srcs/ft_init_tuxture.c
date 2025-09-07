/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tuxture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:12:16 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 09:22:40 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

/*
 * This function allocates memory for a new texture structure and initializes
 * its fields to default values. The texture structure is used to store
 * information about a texture, such as its dimensions, pixel data, and other
 * relevant properties.
 */
t_texture	*ft_init_texture(void)
{
	t_texture	*new_texture;

	new_texture = (t_texture *)malloc(sizeof(t_texture) * 1);
	if (!new_texture)
		return (0);
	new_texture->address = NULL;
	new_texture->height = 0;
	new_texture->width = 0;
	new_texture->image = NULL;
	new_texture->path = NULL;
	new_texture->line_length = 0;
	new_texture->endian = 0;
	new_texture->bits_per_pixel = 0;
	return (new_texture);
}

int	ft_init_animation(t_data *data)
{
	data->animation = malloc(sizeof(t_animation));
	if (!data->animation)
		return (0);
	data->animation->frames = NULL;
	data->animation->frame_count = 0;
	data->animation->current_frame = 0;
	data->animation->frame_delay = 0;
	data->animation->frame_timer = 0;
	return (1);
}
