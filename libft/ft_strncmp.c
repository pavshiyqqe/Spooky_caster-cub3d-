/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:22:33 by abergman          #+#    #+#             */
/*   Updated: 2024/06/02 16:21:25 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0'
		&& s1[index] == s2[index] && index < n)
		index++;
	if (index == n)
		return (0);
	return (((unsigned char *)s1)[index] - ((unsigned char *)s2)[index]);
}

/*
int	main(void)
{
	int origin = strncmp("test\200", "test\0", 6);
	int ft = ft_strncmp("test\200", "test\0", 6);
	printf("origin: %d, ft: %d\n", origin, ft);
	return (0);
}
*/
