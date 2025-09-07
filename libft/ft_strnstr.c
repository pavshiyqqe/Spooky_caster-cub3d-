/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:21:25 by abergman          #+#    #+#             */
/*   Updated: 2024/05/31 21:31:02 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	int		index_substr;

	index = 0;
	index_substr = 0;
	if (*little == '\0')
		return ((char *)big);
	while (index++ < len && *big != '\0' && *little != '\0')
	{
		if (*big == *little)
		{
			while ((*(big + index_substr) == *(little + index_substr))
				&& (index++ <= len))
			{
				if (*(little + index_substr + 1) == '\0')
					return ((char *)big);
				index_substr++;
			}
		}
		big++;
	}
	return (NULL);
}
