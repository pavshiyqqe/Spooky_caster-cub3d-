/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:18:25 by abergman          #+#    #+#             */
/*   Updated: 2024/06/03 23:47:06 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
/*
int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		counter++;
	}
	return (counter);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (!size)
		return (ft_strlen((char *)src));
	while (src[count] != '\0' && count < (size -1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen((char *)src));
}
*/

static char	*is_string_empty(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "", 1);
	return (str);
}

static int	is_inside(char const c, char const *set)
{
	int	count;

	count = -1;
	while (set[++count])
	{
		if (set[count] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	length = ft_strlen(s1);
	start = 0;
	end = length - 1;
	while (is_inside(s1[start], set))
		start++;
	if (length == start)
		return (is_string_empty());
	while (is_inside(s1[end], set))
		end--;
	res = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (start + s1), (end - start + 2));
	return (res);
}
/*
int	main(void)
{
	char *res;

	res = ft_strtrim("           ", "\n ");
	return (0);
}*/
