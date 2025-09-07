/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:55:03 by abergman          #+#    #+#             */
/*   Updated: 2024/05/30 20:52:59 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
/*
int     ft_strlen(char *str)
{
        int     counter;

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
	{
		return ft_strlen((char *)src);
	}
	while (src[count] != '\0' && count < (size -1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return ft_strlen((char *)src);
}
*/
unsigned int	ft_number_strings(char const *s, char c)
{
	unsigned int	count;
	unsigned int	index;

	count = 0;
	index = 0;
	if (!s[0])
		return (0);
	while (s[index] && s[index] == c)
		index++;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			if (s[index - 1] != c)
				count++;
			if (s[index] && s[index] == c)
				index++;
			continue ;
		}
		index++;
	}
	if (s[index - 1] != c)
		count++;
	return (count);
}

void	ft_mns(char const **nxt_str, unsigned int *nxt_str_len, char c)
{
	unsigned int	index;

	*nxt_str += *nxt_str_len;
	*nxt_str_len = 0;
	index = 0;
	while (**nxt_str && **nxt_str == c)
	{
		(*nxt_str)++;
	}
	while ((*nxt_str)[index])
	{
		if ((*nxt_str)[index] == c)
		{
			return ;
		}
		(*nxt_str_len)++;
		index++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	char			*next_string;
	unsigned int	next_string_length;
	unsigned int	number_strings;
	unsigned int	index;

	number_strings = ft_number_strings(s, c);
	res = (char **)malloc(sizeof(char *) * (number_strings + 1));
	if (!res || !s)
		return (NULL);
	index = 0;
	next_string = (char *)s;
	next_string_length = 0;
	while (index < number_strings)
	{
		ft_mns((const char **)&next_string, &next_string_length, c);
		res[index] = (char *)malloc(sizeof(char) * next_string_length + 1);
		if (!res[index])
			return (0);
		ft_strlcpy(res[index], next_string, next_string_length + 1);
		index++;
	}
	res[index] = NULL;
	return (res);
}
/*
int	main(void)
{
	ft_split(" Suspendisse   ", ' ');
	return (0);
}*/
