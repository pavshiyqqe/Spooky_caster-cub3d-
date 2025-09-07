/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:00:55 by abergman          #+#    #+#             */
/*   Updated: 2024/05/31 02:27:35 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
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
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	index;
	unsigned int	s1_size;
	unsigned int	s2_size;	

	s1_size = ft_strlen((char *)s1);
	s2_size = ft_strlen((char *)s2);
	index = 0;
	res = (char *)malloc(sizeof(*s1) * (s1_size + s2_size + 1));
	if (!s1 || !s2 || !res)
		return (NULL);
	while (s1[index] != '\0')
	{
		res[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index] != '\0')
	{
		res[index + s1_size] = s2[index];
		index++;
	}
	res[index + s1_size] = '\0';
	return (res);
}
/*
int	main(void)
{
	char *s1 = "qwe";
	char *s2 = "rty";
	char *res = ft_strjoin(s1, s2);
	printf("%s\n", res);
	return (0);
}
*/
