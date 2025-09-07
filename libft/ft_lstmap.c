/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:34:31 by abergman          #+#    #+#             */
/*   Updated: 2024/06/03 22:12:57 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*response;
	t_list	*temp;
	void	*f_result;

	response = NULL;
	while (lst)
	{
		f_result = f(lst->content);
		temp = ft_lstnew(f_result);
		if (!temp)
		{
			del(temp);
			ft_lstclear(&response, del);
			return (NULL);
		}
		ft_lstadd_back(&response, temp);
		lst = lst->next;
	}
	return (response);
}
