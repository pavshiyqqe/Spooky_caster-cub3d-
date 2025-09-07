/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:04:32 by abergman          #+#    #+#             */
/*   Updated: 2024/06/04 00:39:17 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>
/* 
 * Convert an integer to a string. The function itoa() converts the
 * integer value from val into an ASCII representation that will be stored
 * under s. The caller is responsible for providing sufficient storage in s.
 */

int	ft_abs(int n)
{
	int	res;

	if (n < 0)
		res = n * -1;
	else
		res = n;
	return (res);
}

int	ft_intlen(int n)
{
	int	length;

	if (n <= 0)
		length = 1;
	else
		length = 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		sign;

	if (!n && n != 0)
		return (NULL);
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	size = ft_intlen(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size--] = '\0';
	while (size >= 0)
	{
		res[size--] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
	}
	if (sign < 0)
		res[0] = '-';
	return (res);
}
