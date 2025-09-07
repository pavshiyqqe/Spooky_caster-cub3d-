/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 02:14:48 by abergman          #+#    #+#             */
/*   Updated: 2024/05/24 15:32:15 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>
#define BUF_SIZE 20

void	*ft_memset(void *dest, int c, size_t count)
{
	char	*res;

	res = dest;
	{
		while (count)
		{
			*res = (unsigned char)c;
			res++;
			count--;
		}
		return (dest);
	}
}
