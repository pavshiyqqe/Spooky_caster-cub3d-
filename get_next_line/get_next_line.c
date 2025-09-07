/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:18:42 by yyaniv            #+#    #+#             */
/*   Updated: 2025/02/12 16:45:02 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *saved, char *buf)
{
	char	*temp;
	ssize_t	octets;

	octets = 1;
	while (!ft_newline(saved))
	{
		octets = read(fd, buf, BUFFER_SIZE);
		if (octets <= 0)
		{
			free(buf);
			if (octets < 0 || saved[0] == '\0')
			{
				free(saved);
				return (NULL);
			}
			return (saved);
		}
		buf[octets] = '\0';
		temp = ft_strjoin(saved, buf);
		free(saved);
		saved = temp;
	}
	free(buf);
	return (saved);
}

char	*ft_substr_get(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	length;

	length = ft_strlen(s);
	if (start >= length || length == 0)
	{
		result = (char *)malloc(sizeof(char) * 1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (len > length - start)
		len = length - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

char	*ft_getline(char *saved)
{
	char	*line;
	size_t	j;

	j = 0;
	while (saved[j] != '\n' && saved[j] != '\0')
		j++;
	if (saved[j] == '\n')
		j++;
	line = ft_substr_get(saved, 0, j);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_conserve(char *saved)
{
	int		i;
	int		length;
	char	*stock;

	i = 0;
	while (saved[i] != '\n' && saved[i] != '\0')
		i++;
	if (saved[i] == '\n')
		i++;
	length = ft_strlen(saved) - i;
	stock = ft_substr_get(saved, i, length);
	if (!stock)
		return (NULL);
	free(saved);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char		*saved;
	char			*line;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!saved)
	{
		saved = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!saved)
			return (NULL);
		saved[0] = '\0';
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	saved = ft_read(fd, saved, buf);
	if (saved != NULL && saved[0] != '\0')
	{
		line = ft_getline(saved);
		saved = ft_conserve(saved);
	}
	return (line);
}
