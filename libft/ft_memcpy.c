/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:24:54 by abergman          #+#    #+#             */
/*   Updated: 2024/06/03 18:35:17 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * DESCRIPTION
 * La fonction ft_memcpy() copie 'num' octets depuis la zone mémoire 'source' 
 * vers la zone mémoire 'destination'. 
 * Les deux zones ne doivent pas se chevaucher. 
 *
 * VALEUR RENVOYEE
 * Cette function renvoie un pointeur sur 'destination'.
 */

#include "libft.h"
#define BUF_SIZE 20

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	size_t		index;

	if (!source && !dest)
	{
		return (0);
	}
	index = 0;
	while (index < num)
	{
		((unsigned char *)dest)[index] = ((unsigned char *)source)[index];
		index++;
	}
	return (dest);
}
