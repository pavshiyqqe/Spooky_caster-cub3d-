/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:27:51 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/07 11:30:19 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
This code shows a pixel plotting function for a graphics program.
- Performs boundary checking to ensure the pixel is within the screen dimensions
- Calculates the correct memory position in the texture buffer using:
	- Line length for row offset
	- Bits per pixel for column offset
- Writes the color value directly to memory using pointer arithmetic
 */

void	ft_mlx_pixel_put(int x, int y, t_texture *t, int color_bin)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = t->address + (y * t->line_length + x * (t->bits_per_pixel / 8));
		*(unsigned int *)dst = color_bin;
	}
}
