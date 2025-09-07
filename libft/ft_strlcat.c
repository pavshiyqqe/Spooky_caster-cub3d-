/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:09:13 by abergman          #+#    #+#             */
/*   Updated: 2024/05/23 00:41:24 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Concatenate two strings. Appends src to string dst of size siz (unlike
       strncat(), siz is the full size of dst, not space left). At most siz-1
       characters will be copied. Always NULL terminates (unless siz <=
       strlen(dst)).

       Returns
           The strlcat() function returns strlen(src) + MIN(siz,
           strlen(initial dst)). If retval >= siz, truncation occurred.

       Appends src to string dst of size siz (unlike strncat(), siz is the
       full size of dst, not space left). At most siz-1 characters will be
       copied. Always NULL terminates (unless siz <= strlen(dst)).

       Returns
           The strlcat() function returns strlen(src) + MIN(siz,
           strlen(initial dst)). If retval >= siz, truncation occurred.

*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	count;

	count = 0;
	size_src = ft_strlen((char *)src);
	size_dst = ft_strlen((char *)dst);
	if (size == 0)
	{
		return (size_src + size);
	}
	while ((src[count] != '\0') && ((count + size_dst) < size - 1))
	{
		dst[size_dst + count] = src[count];
		count++;
	}
	dst[size_dst + count] = '\0';
	if (size_dst < size)
	{
		return (size_src + size_dst);
	}
	return (size_src + size);
}
