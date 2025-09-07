/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:19:54 by abergman          #+#    #+#             */
/*   Updated: 2024/06/02 16:22:30 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*copy1;
	unsigned char	*copy2;

	copy1 = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	index = 0 ;
	if (n == 0)
		return (0);
	while ((index < n) && copy1[index] == copy2[index])
		index++;
	if (index == n)
		return (0);
	return (copy1[index] - copy2[index]);
}
/*
Test 1:
    ft_print_result(ft_memcmp("salut", "salut", 5));
Expected (cat -e test01.output):
0
Your result (cat -e user_output_test01):

Test 7:
    ft_print_result(ft_memcmp("abcdefghij", "abcdefgxyz", 7));
Expected (cat -e test07.output):
0
Your result (cat -e user_output_test07):
-1
*/
