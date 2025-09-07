/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:31:50 by abergman          #+#    #+#             */
/*   Updated: 2024/05/29 11:38:29 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
int	ft_strlen(char *s)
{
	int	length;

	length = 0;
	while(s[length] != '\0')
	{
		length++;
	}
	return (length);
}
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	length;

	length = ft_strlen(s);
	write(fd, s, length);
}
/*
int	main(void)
{
	ft_putstr_fd("qwerty", 1);
	return(0);
}*/
