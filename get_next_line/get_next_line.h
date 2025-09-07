/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:16:15 by yyaniv            #+#    #+#             */
/*   Updated: 2024/06/14 18:59:28 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*ft_conserve(char *saved);
char	*ft_getline(char *saved);
char	*ft_read(int fd, char *saved, char *buf);
int		ft_newline(const char *saved);

#endif
