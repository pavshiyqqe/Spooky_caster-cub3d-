/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:39:59 by abergman          #+#    #+#             */
/*   Updated: 2024/05/30 16:39:17 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*response;	

	index = 0;
	response = (unsigned char *)s;
	while (index < n)
	{
		if (response[index] == (unsigned char)c)
			return (&response[index]);
		index++;
	}
	return (NULL);
}
